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

//inserting into sorted list
void insertSort(Node *p,int x)
{
    Node *q;
    q=NULL;
    Node *t=new Node;
    t->data=x;
    t->next=NULL;
    
    if(head==NULL)
        head=t;
    while(p&&p->data < x)
    {
        q=p;
        p=p->next;
    }
    if(p==head)
    {
        t->next=head;
        head=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
}

//deleting from linked list
int delete1(int pos)
{
    Node *p,*q;
    int x=-1;
    if(pos<1 || pos>count(head))
        return -1;
    if(pos==1)
    {
        x=head->data;
        p=head;
        head=head->next;
        delete p;
        return x;
    }
    else
    {
        p=head;
        q=NULL;
        for(int i=0; i<pos-1 && p; i++)
        {
            q=p;
            p=p->next;
        }

        if(p)
        {
            x=p->data;
            q->next=p->next;
            delete p;
        }
    }
    return x;
}

//removing duplicate from sorted list
void rmDup(Node *p)
{
    Node *q1=p->next;
    while(q1!=NULL)
    {
        if(p->data==q1->data)
        {
            p->next=q1->next;
            delete q1;
            q1=p->next;
        }
        else
        {
        p=q1;
        q1=q1->next;
        }
    }
}
//Checking linked  list is sorted or not
bool isSorted(Node *p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(p->data < x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

//Reversing the linked list using array
void arrReverse(Node *p)
{
    int *a=new int[count(p)];
    int i=0;
    Node *q=p;
    while(q!=NULL)
    {
        a[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=a[i];
        q=q->next;
        i--;
    }
}

//Reversing linked list using sliding pointers
void slideRev(Node *p)
{
    Node *q,*r;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

//Recursive reverse using two pointers
void reverse(Node *q,Node *p)
{
    if(p!=NULL)
    {
        reverse(p,p->next);
        p->next=q;
    }
    else
    {
        head=q;
    }
}

//main Function
int main()
{
    int n;
    int arr[n];
    cout<<"Enter the size of elements: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    create(arr,n);
    display(head);
    cout<<"\nLength of linked list is: "<<count(head)<<endl;
   
    insertSort(head,5);
    cout<<"Inserting into sorted list ->";
    display(head);

    cout<<endl<<"Deleted element is: "<<delete1(1)<<endl;
    if(isSorted(head))
        cout<<"Linked list is sorted"<<endl;
    else    
        cout<<"Linked list is not sorted"<<endl;

    rmDup(head);
    cout<<"After removing duplicate elements: ";
    display(head);

    cout<<endl<<"After reversing using array: ";
    arrReverse(head);
    display(head);

    cout<<endl<<"Reverse Using sliding pointers: ";
    slideRev(head);
    display(head);

    cout<<endl<<"Recursively reversing: ";
    reverse(NULL,head);
    display(head);
    return 0;
}