#include<iostream>
#include <stack>
#define endl "\n"
using namespace std;
int main()
{
    int a;
    cin>>a;
    for(int i=0; i<a; i++)
    {  cout<<"Case "<<i+1<<":"<<endl;
        int b,c;
        cin>>b>>c;
        stack<int> ar[b];
        for( int j=0; j<c; j++)
        {
            string d;
            cin>>d;
            if(d=="push")
            {
                int e,f;
                cin>>e>>f;
                ar[e-1].push(f);
            }
            else if( d=="put")
            {
                int e,f;
                cin>>e>>f;
                stack<int> s;
                while(!ar[e-1].empty()){
                    s.push(ar[e-1].top());
                    ar[e-1].pop();
                }
                while(!s.empty())
                {
                    ar[f-1].push(s.top());
                    s.pop();
                }
            }
            else if(d=="pop")
            {
                int e;
                cin>>e;
               if(!ar[e-1].empty())
                   ar[e-1].pop(); 
            }
            else
            {
                int e;
                cin>>e;
                if(ar[e-1].empty())
                  cout<<"Empty!"<<endl;
                else
                  cout<<ar[e-1].top()<<endl;
            }
        }
    }
}