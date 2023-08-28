#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*head=NULL;

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

//Checking loop is exists in the linked list or not
int isLoop(Node *f)
{
    Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q ? q->next:q;
        
    } while (p && q && p!=q);
    return p==q ? 1:0;
}
int main()
{
    int n=5;
    Node *t1,*t2;
    int arr1[]={10,20,30,40,50};

    create(arr1,n);

    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;

    if(isLoop(head))
    {
        cout<<"Loop is exists in the linked list"<<endl;
    }
    else
    {
        cout<<"There is no loop in the linked list"<<endl;
    }

    return 0;
}