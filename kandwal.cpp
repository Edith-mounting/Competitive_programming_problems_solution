#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int n,c=0;
    string s;
    cin>>n>>s;
    char ch;
    stack<char> ob;
    stack<char> ob1;
    for(int i=0;i<n;i++)
    {
        ob.push(s[i]);
    }
    while(!ob.empty())
    {
        ch=ob.top();
        ob.pop();
        if(ch==ob.top() && c<3)
        {
            ob1.push(ch);
            c=c+1;
        }
        else
        {
            if(c==3)
            {
                for(int i=3;i>=1;i--)
                {
                    ob1.pop();
                }
                while(!ob1.empty())
                {
                    ob.push(ob1.top());
                    ob1.pop();
                }
            }
            ob1.push(ch);
            c=0;
        }
    }
    while(!ob1.empty())
    {
    cout<<ob1.top();
    ob1.pop();
    }
}
