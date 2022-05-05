#include <iostream>
#include <stack>
using namespace std;
class CircularQueue
{   
    private:
        int *dog;
        int f=-1;int r=-1;int size;
    public:
        CircularQueue(int k)
        {
            dog=new int[k];
            size=k;
        }
        bool isEmpty()
        {
            if(f==-1)
            return true;
            else
            return false;
        }
        bool isFull()
        {
            if ((r==size-1 && f==0)||(r==f-1))
            return true;
            else
            return false;
        }
        int front()
        {
            if(isEmpty())
            return-1;
            else
            {
                int x=dog[f];
                return x;
            }
        }
        int rear()
        {
            if(isEmpty())
            return-1;
            else
            return dog[r];
        }
        bool enqueue(int n)
        {
            if(isFull())
            return false;
            else 
            {
                if(isEmpty())
                {
                    r=0;
                    f=0;
                }
                else if (r==size-1&&f!=0)
                {
                    r=0;
                }
                else
                r++;
                dog[r]=n;
                return true;
            }
        }
        bool dequeue ()
        {
            if(isEmpty())
            {
                return false;
            }
            else
            {
                if(f==r)
                {
                    f=-1;
                    r=-1;
                }
                else if(f==size-1)
                f=0;
                else
                f++;
                return true;
            }
        }
        
};
int main()
{
    int n,k;
    cin>>n>>k;
    CircularQueue myQueue(n);
    int flag=1,i=1;
    while(i<=n&&flag==1)
    {
        int a;cin>>a;
        if(myQueue.enqueue(a))
        flag==1;
        else
        flag==0;
        i++;
    }//by the way return of enqueue does not have any effect so could have skipped flag
    int count=1;
    for(i=1;i<=n-1;i++)
    {
        while(count!=k)
        {
            int temp=myQueue.front();
            myQueue.dequeue();
            count++;
            myQueue.enqueue(temp);
        }
        if(count==k)
        {
            myQueue.dequeue();
            count=1;
        }
    }
    cout<<myQueue.rear();
}
