// C++ program to concatenate two strings using
// rope data structure.
#include <bits/stdc++.h>
using namespace std;

// Maximum no. of characters to be put in leaf nodes
const int LEAF_LEN = 2;

// Rope structure
class Rope
{
public:
	Rope *left, *right, *parent;
	char *str;
	int lCount;
};

// Function that creates a Rope structure.
// node --> Reference to pointer of current root node
// l --> Left index of current substring (initially 0)
// r --> Right index of current substring (initially n-1)
// par --> Parent of current node (Initially NULL)
void createRopeStructure(Rope *&node, Rope *par,
						string a, int l, int r)
{
	Rope *tmp = new Rope();
	tmp->left = tmp->right = NULL;

	// We put half nodes in left subtree
	tmp->parent = par;

	// If string length is more
	if ((r-l) > LEAF_LEN)
	{
		tmp->str = NULL;
		tmp->lCount = (r-l)/2;
		node = tmp;
		int m = (l + r)/2;
		createRopeStructure(node->left, node, a, l, m);
		createRopeStructure(node->right, node, a, m+1, r);
	}
	else
	{
		node = tmp;
		tmp->lCount = (r-l);
		int j = 0;
		tmp->str = new char[LEAF_LEN];
		for (int i=l; i<=r; i++)
			tmp->str[j++] = a[i];
	}
}

// Function that prints the string (leaf nodes)
void printstring(Rope *r)
{
	if (r==NULL)
		return;
	if (r->left==NULL && r->right==NULL)
		cout << r->str;
	printstring(r->left);
	printstring(r->right);
}

// Function that efficiently concatenates two strings
// with roots root1 and root2 respectively. n1 is size of
// string represented by root1.
// root3 is going to store root of concatenated Rope.
void concatenate(Rope *&root3, Rope *root1, Rope *root2, int n1)
{
	// Create a new Rope node, and make root1
	// and root2 as children of tmp.
	Rope *tmp = new Rope();
	tmp->parent = NULL;
	tmp->left = root1;
	tmp->right = root2;
	root1->parent = root2->parent = tmp;
	tmp->lCount = n1;

	// Make string of tmp empty and update
	// reference r
	tmp->str = NULL;
	root3 = tmp;
}

// Driver code
int32_t main()
{
	int w;
    cin>>w;
    while(w--){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        Rope *a1=NULL;
        Rope *b1=NULL;
        string a="0",b="1";
        createRopeStructure(a1, NULL, a, 0, 0);
        createRopeStructure(b1, NULL, b, 0, 0);
        Rope *x=NULL;//for 0
        Rope *y=NULL;//for 1
        createRopeStructure(x, NULL, a, 0, 0);
        createRopeStructure(y, NULL, b, 0, 0);
        int q1=1,q2=1;//length of a and b
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(q1<=q2){
                    Rope *root3 = NULL;
                    concatenate(root3, x, a1, 1);
                    a1=root3;
                    //a="0"+ a;
                }
                else{
                    concatenate(a1, x, b1, 1);
                    //a="0"+ b;
                }
                q1++;
            }
            else{
                if(q1<=q2){
                    concatenate(b1, y, a1, 1);
                    //b="1"+ a;
                }
                else{
                    Rope *root3 = NULL;
                    concatenate(root3, y, b1, 1);
                    b1=root3;
                    //b="1"+ b;
                }
                q2++;
            }
        }
        bool bl=true;
        for(int i=0;i<s.length();i++){
            if(s[i]==0){
                bl=false;
                break;
            }
        }
        if(bl){
            cout<<0;
        }
        else{
            printstring(b1);
        }
        cout<<"\n";
    }
}
