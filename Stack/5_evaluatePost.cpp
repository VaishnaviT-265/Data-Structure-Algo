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
        int isOperand(char x);
        int Eval(string postfix);
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

int Stack:: isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}
int Stack::Eval(string postfix)
{
    int i,x1,x2,r;
    for(int i=0; i<postfix.size(); i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2=pop();
            x1=pop();
            switch(postfix[i])
            {
                case '+':
                    r=x1+x2;
                    push(r);
                    break;
                case '*':
                    r=x1*x2;
                    push(r);
                    break;
                case '/':
                    r=x1/x2;
                    push(r);
                    break;
                case '-':
                    r=x1-x2;
                    push(r);
                    break;
            }
        }
    }
    return pop();
}
int main()
{
    Stack stk;
    string postfix="35*62/+4-";
    cout<<stk.Eval(postfix);

    
    return 0;
}