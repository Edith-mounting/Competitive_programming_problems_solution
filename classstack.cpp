#include <iostream>
#define endl "\n"
using namespace std;

class MyStack{
    int stacktop;
    int stacklength;
    int* stack;
    int count;
    public:
        MyStack(){
            stacklength=1;
            stacktop=1;
            stack=new int[1];
            count=0;
        }
        void push(int x){
            if(stacktop==stacklength-1){
                int* x=new int[stacklength*2];
                for(int i=0;i<stacklength;i++){
                    *(x+i)=stack[i];
                }
                delete [] stack;
                stacklength=stacklength*2;
                stack=x;
                count++;
            }
            else{
                stacktop++;
                *(stack+stacktop)=x;
                count++;
            }
        }
        int pop(){
            int k=*(stack+stacktop);
            if(stacktop!=-1){
                stacktop--;
            }
            count--;
            return k;
        }
        int peek(){
            if(stacktop!=-1){
                return *(stack+stacktop);
            }
            else return -1;
        }
        bool empty(){
            if(count==0)return true;
            else return false;
        }
};
int main(){
    MyStack s;
    s.push(2);
    s.push(5);
    s.push(67);
    s.push(7);
    s.push(76);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.empty()<<endl;
}