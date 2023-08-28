#include<iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
}*first=NULL;

//Creating a linked list
void create(int A[],int n)
{
    Node *t,*last;
    int i;
    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

//finding the length of linked list
int len(Node *p)
{
    int len;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

//Display doubly linked list
void Display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//Insert
void insert(Node *p,int index,int x)
{
    Node *t;
    int i;
        if(index <0 && index> len(p))
            return;
        if(index==0)
        {
            t=new Node;
            t->data=x;
            t->prev=NULL;
            t->next=first;
            first->prev=t;
            first=t;
        }
        else{
            for(i=0; i<index-1;i++)
                p=p->next;
            t=new Node;
            t->data=x;
            t->prev=p;
            t->next=p->next;
            if(p->next)
            {
                p->next->prev=t;
            }
            p->next=t;
        }
}

//Delete
int Delete(Node *p,int index)
{
    int x=-1,i;
    if(index<1 || index >len(p))
        return -1;
    if(index==1)
    {
        first=first->next;
        if(first)
            first->prev=NULL;
        x=p->data;
        delete p;
    }
    else
    {
        for(i=0; i<index-1; i++)    
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}

//Reverse doubly linked list
void reverse(Node *p)
{
    Node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    cout<<"Length is: "<<len(first)<<endl;
    Display(first);

    insert(first,0,15);
    insert(first,5,20);
    Display(first);

    Delete(first,1);
    Display(first);

    cout<<"Reversing a linked list: ";
    reverse(first);
    Display(first);

    return 0;
}