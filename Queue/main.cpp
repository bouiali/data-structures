#include <iostream>

using namespace std;
void insertion( );
void deletion();
               /* static circular queue */
class Queue
{
private:
    int maxx;//size
    int arr[10];//array
    int fron,rear;
public:
    Queue();
    void insert_item(int value);
    void delete_item();
    void display();
};
Queue::Queue()
{
    maxx = 10;
    fron = rear = -1;//start position
}
void Queue::insert_item(int value)
{
    if(fron == -1)//if the queue is empty
    {
        fron=rear=0;
        arr[0]= value;
    }
    else
    {
        if(fron == ((rear+1)%maxx))
        {
            cout<<"The queue is overflow !!! "<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%maxx;
            arr[rear]= value;
        }

    }
}
void Queue::delete_item()
{
    if(fron == -1)//if the queue is empty
    {
        cout<<"The queue is empty !!!"<<endl;
        return;
    }
    else
    {
        if(fron == rear)
            fron=rear=-1;
        else
            fron=(fron+1)%maxx;//position ++
    }

}
void Queue::display()
{
    if(fron == -1)//if the queue is empty
    {
        cout<<"The queue is empty !!!"<<endl;
        return;
    }
    else
    {
        cout<<"Front  ==>";
        for(int i=fron;i!=rear;i=(i+1)%maxx)
            cout<<i<<" :: "<<arr[i]<<endl;
        cout<<"Rear  ==>";
        cout<<rear<<" :: "<<arr[rear]<<endl;
    }
}
//variables declaration
int q[5], n =4 , front= -1 , rear= -1 , item ;
int main()
{
    Queue q;
    q.display();
    return 0;
}
                         /* static linear queue*/

void insertion()
{

    if((rear == n-1) && (front == (rear+1)) || (front == rear+1))
    {
        cout<<"...";
        rear = front =0;
    }
    else if (rear == -1)
        front = rear = 0;
    else if (rear == n-1)
    {
        cout<< "Queue Overflow\n" ;
        return;
    }

    else
        rear = rear+1;
    cout<< "Enter the item : " ;
    cin>> item ;
    q[rear] = item;
    cout << "is inserted :" << item << endl;

}
void deletion()
{
    if (front == -1 )
    {
        cout<< "\n Queue Underflow\n\n" ;
    }
    item=q[front];
    if ( front == rear )
    {
        front = -1 ;
        rear = -1 ;
    }
    else if ( front == n-1)
        front=-1;
    else
        front = front + 1 ;
    cout<< "is deleted :" << item<<"  front in :"<<front<<endl ;
}
