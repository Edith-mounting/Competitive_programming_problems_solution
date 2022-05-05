#include <iostream>
using namespace std;

class CircularQueue{
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
    CircularQueue m(4);
    cout<<m.enqueue(1)<<endl;
    cout<<m.enqueue(2)<<endl;
    cout<<m.enqueue(3)<<endl;
    cout<<m.enqueue(4)<<endl;
    cout<<m.isFull()<<endl;
    cout<<m.enqueue(5)<<endl;
    cout<<m.dequeue()<<endl;
    cout<<m.dequeue()<<endl;
    cout<<m.front()<<endl;
    cout<<m.rear()<<endl;
    cout<<m.dequeue()<<endl;
    cout<<m.isFull()<<endl;
    cout<<m.isEmpty()<<endl;
    cout<<m.dequeue()<<endl;
    cout<<m.isEmpty()<<endl;
    
}