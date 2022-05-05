#include <iostream>
#include<cstdlib>

using namespace std;

class Circular_Queue
{
    public:
        int *cqueue_arr;
        int front, rear;
        int cap;
    public:
        Circular_Queue(int k)
        {
            cqueue_arr = new int [k];
            cap=k;
            rear = front = -1;
        }
        
        void insert(int item)
        {
            if ((front == 0 && rear == cap-1) || (front == rear+1))
            {
                cout<<"Queue Overflow \n";
                return;
            }
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                if (rear == cap- 1)
                    rear = 0;
                else
                    rear = rear + 1;
            }
            cqueue_arr[rear] = item ;
        }
        
        void del()
        {
            if (front == -1)
            {
                cout<<"Queue Underflow\n";
                return ;
            }
            cout<<"Element deleted from queue is : "<<cqueue_arr[front]<<endl;
            for(int i=front;i<cap-1;i++)
                {
                  cqueue_arr[i]=cqueue_arr[i+1];
                }
           
            cap=cap-1;
        }
        
};
int main()
{ 
    int k,n;
    cin>>n>>k;
    Circular_Queue s(n);
    for(int i=0;i<n;i++)
    {  cin>>n;
        s.insert(n);
        
    }
   
    int count=1;
    while(s.cap!=1)
    
    {
            if(count==k)
            {
                s.del();
                count=1;
                
                if(s.front==s.cap)
                {
                  s.front=0;
                }
                
            }
            else if(count!=k)
            {   count=count+1;
                s.front=s.front+1;
                if(s.front==s.cap)
                {
                  s.front=0;
                }
            }
        }
        cout<<s.cqueue_arr[s.front]<<"is winner"<<endl;
    
}

