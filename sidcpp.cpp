#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int p=t;
    stack <int> n;
    stack <string> name;
    while(t>0)
    {
        int a;
        cin>>a;
        if (a!=-1)
        {
            string b;
            cin>>b;
            if(a!=0)
            {   
                    n.push(a);
                    name.push(b);
            }
           
        }
        if (a==-1)
        {   int siz=n.size();
            int count=1; 
            int tn; 
            string tname;
            tn=n.top();
            tname=name.top();
            stack <int> demo;
            stack <string> dname;
            while (!n.empty())
            {
                if(tn>n.top())
                {
                    tn=n.top();
                    demo.push(n.top());
                    dname.push(name.top());
                    tname=name.top();
                    n.pop();
                    name.pop();
                }
                else
                {   demo.push(n.top());
                    dname.push(name.top());
                    n.pop();
                    name.pop();
                }
                
            }
            int flag=1;
            while (flag!=0)
            {  
                if (tn==demo.top()&&tname==dname.top())
                {  
                    flag=0;
                }
                else
                {
                    n.push(demo.top());
                    name.push(dname.top());
                    demo.pop();
                    dname.pop();
                    count++;
                }
            }
            count=siz-count;
            cout <<count<<" "<<tname<<endl; 
        }
        
        
        t--;
    }
}