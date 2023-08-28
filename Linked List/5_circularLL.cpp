#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*head=NULL;

void create(int A[],int n)
{
    head=new Node;
    Node *last,*temp;

    head->data=A[0];
    head->next=head;
    last=head;

    for(int i=1; i<n; i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void display(Node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    
}

void Rdisplay(Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
    flag=0;
}

int length(Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    } while (p!=head);
    return len;
    
}

//Inserting into circular linked list
void insert(Node *p,int index,int x)
{
    Node *t;
    int i;
    if(index<0 || index >length(p))
        return;
    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            //inserting at first index
            while(p->next != head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(i=0; i<index-1; i++)
            p=p->next;
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t; 
    }
}

//Deleting an element
int Delete(Node *p,int index)
{
    Node *q;
    int i,x;
    if(index<0 && index >length(p))
        return -1;
    if(index==1)
    {
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(head==p)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for(i=0; i<index-2; i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[]={1,2,3,4,5,6};
    create(A,6);
    display(head);
    cout<<endl<<"Recursive: ";
    Rdisplay(head);

    insert(head,-1,10);
    cout<<endl;
    display(head);

    cout<<"Deleting an element: "<<Delete(head,1)<<endl;
    display(head);
    return 0;
}