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
        int pre(char x);
        int isOperand(char x);
        string inToPost(string infix);
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

int Stack::pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    return 0;
}

int Stack:: isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

string Stack:: inToPost(string infix)
{
    int i=0,j=0;
    string postfix="      ";
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    
    return postfix;
}
int main()
{
    Stack stk;
    string infix="a+b*c";
    stk.push('#');
    string postfix=stk.inToPost(infix);
    cout<<postfix;
    
    return 0;
}