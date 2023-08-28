#include<iostream>
#include<stdlib.h>
using namespace std;

struct Term
{
    int coeff,exp;
};

struct Poly
{
    int n;
    Term *terms;
};

void create(Poly *p)
{
    cout<<"Number of terms: ";
    cin>>p->n;
    p->terms=new Term[p->n];
    cout<<"Enter terms"<<endl;
    for(int i=0; i<p->n; i++)
    {
        cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}

void display(Poly p)
{
    for(int i=0; i<p.n; i++)
    {
        cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<"+";
    }
    cout<<endl;
}

struct Poly *add(struct Poly *p1,struct Poly *p2)
{
    int i,j,k;
    struct Poly *sum;

    sum=(struct Poly*)malloc(sizeof(struct Poly));
    sum->terms=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));
    i=j=k=0;

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp>p2->terms[j].exp)
            sum->terms[k++]=p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++]=p2->terms[j++];
        else
        {
            sum->terms[k].exp=p1->terms[i].exp;
            sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }
    for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i];
    for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j];

     sum->n=k;
    return sum;
}
int main()
{
    Poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3=add(&p1,&p2);
    
    cout<<endl;
    display(p1);
    cout<<endl;
    display(p2);
    cout<<endl;
    display(*p3);
    return 0;
}