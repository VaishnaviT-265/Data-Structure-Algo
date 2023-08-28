// **** Queue using Linked list ****
#include<iostream>
using namespace std;

//Create node's structure
struct Node
{
    int data;
    Node *next;
}*front=nullptr,*rear=nullptr;

//Enequeue to insert an element
void enequeue(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Queue is overflow"<<endl;
    else
    {
        t->data=x;
        t->next=nullptr;
        if(front==nullptr)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

//Dequeue to delete an element
int dequeue()
{
    int x=-1;
    Node *p;
    if(front==nullptr)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x=front->data;
        p=front;
        front=front->next;
        delete[] p;
    }
    return x;
}

//Displaying queue
void display()
{
    Node *t=front;
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

//main function
int main()
{
    display();
    enequeue(10);
    enequeue(20);
    enequeue(30);
    enequeue(40);
    enequeue(50);
    display();

    cout<<dequeue()<<endl;
    return 0;
}
