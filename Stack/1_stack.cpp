#include<iostream>
using namespace std;

class Stack
{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(int size)
        {
            this->size=size;
            top=-1;
            s=new int[size];
        }
        ~Stack()
        {
            delete[] s;
        }

        void display();
        void push(int x);
        int pop();
        int peek(int index);
        int isEmpty();
        int isFull();
        int stackTop();
};

void Stack::display()
{
    for(int i=top; i>=0; i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void Stack::push(int x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        s[top]=x;
    }
}

int Stack::pop()
{
    int x=-1;
    if(isEmpty())
        cout<<"Stack Underflow"<<endl;
    else
    {
        x=s[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x=-1;
    if(top-index+1 <0 && top-index+1==size-1)
        cout<<"Invalid index"<<endl;
    else
    {
        x=s[top-index+1];
    }
    return x;
}

int Stack::isFull()
{
    if(top==size-1)
        return 1;
    return 0;
}

int Stack::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    return s[top];
}

int main()
{
    int size,temp;
    cout<<"Enter size of Stack: ";
    cin>>size;

    Stack stk(size);
    cout<<"Stack Empty: "<<stk.isEmpty()<<endl;
    
    cout<<"Enter "<<size<<" elements: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>temp;
        stk.push(temp);
    }

    cout<<"Stack Elements are: ";
    stk.display();

    cout<<endl<<"Stack full: "<<stk.isFull()<<endl;

    cout<<"Pop : "<<stk.pop()<<endl;
    cout<<"After popping stack elements are: ";
    stk.display();

    cout<<"Top is: "<<stk.stackTop()<<endl;

    cout<<"Element at index 2  is: "<<stk.peek(2)<<endl;
    return 0;
}