#include<iostream>
using namespace std;

int main()
{
    int *p=new int [5];
    int *q=new int [15]; //creating new larger size array
    cout<<"Enter 5 elements:";
    for(int i=0; i<5; i++)
    {
        cin>>p[i];
    }

    // copying p[] elements into new array q[]
    for(int i=0; i<5; i++) 
    {
        q[i]=p[i];     
    }

    delete []p;  // deleting memory for p[]
    p=q;        // pointing p to q. Now both p & q pointing to same array
    q=NULL;    //  q is pointing to null i.e., now only p is pointing to that array

    cout<<sizeof(p)<<endl;

    return 0;
}