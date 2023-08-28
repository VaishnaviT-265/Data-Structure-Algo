#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*head=NULL,*second= NULL,*third=NULL;

//Creating Linked list
void create(int A[],int n)
{
    head=new Node;
    Node *temp,*last;
    
    head->data=A[0];
    head->next=nullptr;
    last=head;

    for(int i=1; i<n; i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
}

void create2(int A[],int n)
{
    second=new Node;
    Node *temp,*last;
    
    second->data=A[0];
    second->next=nullptr;
    last=second;

    for(int i=1; i<n; i++)
    {
        temp=new Node;
        temp->data=A[i];
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
}

//concatinating two linked lists
void concat(Node *p,Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
//Displaying Linked list
void display(Node *p)
{
    cout<<"Linked list is: ";
    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

//Merging the two lists
void merge(Node *p,Node *q)
{
    Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}
int main()
{
    int n=5;
    int arr1[]={10,20,30,40,50};
    int arr2[]={5,15,25,35,45};

    cout<<"First ";
    create(arr1,n);
    display(head);

    cout<<endl<<"Second ";
    create2(arr2,n);
    display(second);

    /*cout<<endl<<"Concatenated ";
    concat(head,second);
    display(third);*/

    cout<<endl<<"Merged ";
    merge(head,second);
    display(third);
    return 0;
}