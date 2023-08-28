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

//Reversing linked list
void Rdisplay(Node *p)
{
    if(p!=NULL)
    {
        Rdisplay(p->next);
        cout<<p->data<<" -> ";
    }
}

//Finding length of Linked list
int count(Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

//Finding length using recursive
int Rcount(Node *p)
{
    if(p==NULL)
        return 0;
    return Rcount(p->next)+1;
}

//Finding sum of linked list
int sum(Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
1
//Finding sum using recursive
int Rsum(Node *p)
{
    if(p==NULL)
        return 0;
    else    
        return Rsum(p->next)+p->data;
}

//Finding maximum of linked list
int max(Node *p)
{
    int max=INT_MIN;
    while(p!=NULL)
    {
        if(p->data > max)
            max=p->data;
        p=p->next;
    }
    return max;
}

//Finding max using recursive
int Rmax(Node *p)
{
    int x=0;
    if(p==NULL)
        return INT_MIN;
    else
    {
        x=Rmax(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}

//Linear search with improving 
Node *search(Node *p,int key)
{
    Node *q=NULL;
    while(p!=NULL)
    {
    
        if(p->data==key)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;
        }
 q=p;
 p=p->next;
    }
    return NULL;
}

//Linear Search using recursive
Node *Rsearch(Node *p,int key)
{
    if(p==NULL)
        return nullptr;
    if(p->data==key)
        return p;
    return Rsearch(p->next,key);
}

//inserting into linked list

void insert(Node *p,int index,int x)
{
    Node *t1=new Node;
    if(index< 0 || index > count(p))
        return ;
    t1->data=x;
    if(index==0)
    {
        t1->next=head;
        head=t1;
    }
    else
    {
        for(int i=0; i<index-1; i++) // O(n)
        {
            p=p->next;
        }
        t1->next=p->next;
        p->next=t1;
    }
}
//main Function
int main()
{
    struct Node *t;
    int arr1[]={1,2,3,4,6};
    create(arr1,6);
    display(head);
    cout<<"\nReverse of Linked list: ";
    Rdisplay(head);
    cout<<"\nLength of linked list is: "<<count(head)<<endl;
    cout<<"Length of Linked list using recursive : "<<Rcount(head)<<endl;
    cout<<"Sum of Linked list : "<<sum(head)<<endl;
    cout<<"Sum using Recursive: "<<Rsum(head)<<endl;
    cout<<"Max of linked list is : "<<max(head)<<endl;
    cout<<"Max using recursive: "<<Rmax(head)<<endl;
    t=search(head,3);
    if(t)
        cout<<"Key is found at :"<<t->data;
    else
        cout<<"Key not found"<<endl;

    insert(head,4,5);
    cout<<"\nAfter inserting an element ";
    display(head);

    return 0;
}