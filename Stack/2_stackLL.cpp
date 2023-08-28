#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack()
        {
            top=NULL;
        }
        
        void push(int x);
        int pop();
        void display();
        int peek(int index);
};

void Stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack is Full"<<endl;
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    else
    {
        Node *p=top;
        x=top->data;
        top=top->next;
        delete p;
    }
    return x;
}

void Stack::display()
{
    Node *p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Stack::peek(int index)
{
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
    {
        Node *p=top;
        for(int i=0; p!=NULL && i<index-1; i++)
        {
            p=p->next;
        }
        return p->data;
    }
}
int main()
{
    Stack stk;
    stk.push(5);
    stk.push(10);
    stk.push(15);
    stk.display();
    cout<<"POP:"<<stk.pop()<<endl;
    cout<<"Element at 2 is: "<<stk.peek(2)<<endl;
    

    return 0;
}