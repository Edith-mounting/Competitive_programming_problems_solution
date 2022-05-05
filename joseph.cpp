#include <iostream>
using namespace std;

class CircularQueue{
    public:
    int queuefront;
    int queuerear;
    int queuelength;
    int* queue;
    int count;

    public:
    CircularQueue(int k){
        queue=new int[k];
        queuelength=k;
        queuefront=-1;
        queuerear=-1;
        count=0;

    }
    int front(){
        if(queuefront==-1)return -1;
        else return *(queue+queuefront);
    }
    int rear(){
        if(queuerear==-1)return -1;
        else return *(queue+queuerear);
    }
    bool enqueue(int value){
        if(count==queuelength){
            return false;
        }
        else if(queuefront==-1){
            count++;
            queuefront=queuerear=0;
            *(queue+queuerear)=value;
            return true;
        }
        else{
            queuerear=(queuerear+1)%queuelength;
            *(queue+queuerear)=value;
            count++;
            return true;
        }
    }
    bool dequeue(){
        if(count==0){
            return false;
        }
        else{
            queuefront=(queuefront+1)%queuelength;
            count--;
            return true;
        }
    }
    bool isEmpty(){
        if(count==0)return true;
        else return false;
    }
    bool isFull(){
        if(count==queuelength)return true;
        else return false;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    CircularQueue s(n);
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        s.enqueue(el);
    }
    int c=1;
    for(int i=0;i<n;i++)
    {
        while(c!=k)
        {
            int x=s.front();
            s.dequeue();
            c++;
            s.enqueue(x);
        }
        if(c==k)
        {
            s.dequeue();
            c=1;
        }
    }
    cout<<s.rear();
}