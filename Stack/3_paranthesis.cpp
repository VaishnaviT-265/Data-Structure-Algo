#include<iostream>
using namespace std;

class Node
{
    public:
        char data;
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
        
        void push(char x);
        char pop();
        int isBalanced(string str);
};

void Stack::push(char x)
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

char Stack::pop()
{
    char x;
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

int Stack::isBalanced(string str)
{
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            push(str[i]);

        else if(str[i]==')' || str[i]==']' ||str[i]=='}')
        {
            if(top==NULL)
                return 0;

            else if(str[i]==')')
            {
                if(top->data=='(')
                    pop();
                
            }
             else if(str[i]=='}')
            {
                if(top->data=='{')
                    pop();
              
            }
             else if(str[i]==']')
            {
                if(top->data=='[')
                    pop();
              
            }
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
    Stack stk;
    string str="{([a*b]+[b*c])}";
    if(stk.isBalanced(str))
        cout<<"paranthesis are balanced"<<endl;
    else
        cout<<"Parathesis are not balanced"<<endl;
    return 0;
}