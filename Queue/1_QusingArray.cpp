#include<iostream>
using namespace std;

//Creating class queue
class  Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;

    public:
        Queue(int size)
        {
            front=rear=-1;
            this->size=size;
            Q=new int[this->size];
        }
        void enqueue(int x);
        int dequeue();
        void display();
};

//Enqueue to insert an element
void Queue::enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        Q[rear]=x;
    }
}
//Dequeue to delete an element
int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {
        
        x=Q[front+1];
        front++;
        
    }
    return x;
}

//Dsiplaying queue
void Queue::display()
{
    for(int i=front+1 ; i<=rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}

//main function
int main()
{
    Queue q(5);

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();

    cout<<q.dequeue()<<endl;
    
    q.enqueue(9);
    q.enqueue(10);
    q.display();
    return 0;
}