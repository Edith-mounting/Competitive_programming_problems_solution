#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n,p=0,q=0;
    cin>>n;
    deque<int> g;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        g.push_front(a);
    }
    int m=1;
    while(!g.empty()){
        if(g.front()>=g.back()){
            if(m%2==1){
                p+=g.front();
                g.pop_front();
            }
            else{
                q+=g.front();
                g.pop_front();
            }
        }
        else{
            if(m%2==1){
                p+=g.back();
                g.pop_back();
            }
            else{
                q+=g.back();
                g.pop_back();
            }
        }
        m++;
    }
    cout<<p<<" "<<q;

}