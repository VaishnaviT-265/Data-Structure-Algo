#include<iostream>
using namespace std;

class dequeue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        dequeue(int size);
        ~dequeue();
        void enqueueFront(int x);
        void enqueueRear(int x);
        int dequeueFront();
        int dequeueRear();
        bool isEmpty();
        bool isFull();
        void display();
};

dequeue::dequeue(int size)
{
    this->size=size;
    front=rear=-1;
    Q=new int[size];
}

dequeue::~dequeue()
{
    delete[] Q;
}

void dequeue::enqueueFront(int x)
{
    if(front==-1)
        cout<<"DEQueue overflow"<<endl;
    else
    {
        Q[front--]=x;
    }
}

void dequeue::enqueueRear(int x)
{
    if(isFull())
        cout<<"Queue is overflow"<<endl;
    else
    {
        Q[++rear]=x;
    }
}

int dequeue::dequeueFront()
{
    int x=-1;
    if(isEmpty())
    {
        cout<<"DEQueue underflow"<<endl;
    }
    else
    {
        x=Q[front++];
    }
    return x;
}

int dequeue::dequeueRear()
{
    int x=-1;
    if(rear==-1)
    {
        cout<<"DEQueue underflow"<<endl;
    }
    else
    {
        x=Q[rear--];
    }
    return x;
}

bool dequeue::isEmpty()
{
    if(front==rear)
    {
        return 1;
    }
    return 0;
}

bool dequeue::isFull()
{
    if(rear==size-1)
        return 1;
    return 0;
}

void dequeue::display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
        if(i<rear)
        {
            cout<<"<-"<<flush;
        }
    }
    cout<<endl;
}

int main()
{
   int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    dequeue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
 
    return 0;
}