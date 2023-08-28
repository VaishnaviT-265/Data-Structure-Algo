#include<iostream>
using namespace std;

//Creating class queue for circular queue
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
            front=rear=0;
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
    if((rear+1)%size==front)
        cout<<"Queue is Full"<<endl;
    else
    {
        rear=(rear+1)%size;
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
        front=(front+1)%size;   
        x=Q[front];
           
    }
    return x;
}

//Dsiplaying Circular queue
void Queue::display()
{
    int i=front+1;
    do
    {
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    }while(i!=(rear+1)%size);
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