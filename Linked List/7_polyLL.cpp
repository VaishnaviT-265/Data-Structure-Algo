#include<iostream>
#include<math.h>
using namespace std;
 struct Node
 {
    int coeff;
    int exp;
    Node *next;
 }*poly=NULL;

 void create()
 {
    Node *t,*last;
    int num,i;
    cout<<"Enter number of terms: ";
    cin>>num;

    cout<<"Enter each term with coefficient and exp"<<endl;

    for(i=0; i<num; i++)
    {
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
 }

 void display(Node *p)
 {
    while(p)
    {
        cout<<p->coeff<<"x"<<p->exp<<" + ";
        p=p->next;
    }
 }

 long Eval(Node *p,int x)
 {
    long val=0;
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
 }

 int main()
 {
    create();
    display(poly);
    cout<<endl<<"Answer is: "<<Eval(poly,1);  
   return 0;
 }