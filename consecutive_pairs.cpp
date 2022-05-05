#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int d;
	struct node* m;
};
struct node * insert(struct node* h, int d)
{
	struct node* v= (struct node*)malloc(sizeof(struct node*));
	struct node* ptr= NULL;
	v->d= d;
	v->m= NULL;
	if(h==NULL)
	{
		h=v;
		return h;
	} 
	ptr=h;
	while(ptr->m!=NULL)
	{
		ptr=ptr->m;
	}
	ptr->m=v;
	return h;
}
void display(struct node* h)
{
	while(h!=NULL)
	{
		printf("%d ", h->d);
		h=h->m;
	}
}
void max(struct node* h)
{
	int m=0, a, b;
	while(h->m!=NULL)
	{
		if(h->d+ h->m->d>m){
			a=h->d;
			b=h->m->d;
			m=h->d+ h->m->d;
		}
		h=h->m;
	}
	printf("%d %d\n", a,b);
}
 
 
int main()
{
	struct node* head=NULL;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
		head=insert(head, arr[i]);
	}
	// display(head);
	// printf("\n");
	max(head);
}