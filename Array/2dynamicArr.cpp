#include<iostream>
#include<stdio.h>
#include<stdlib.h>  
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    float *p;
    p=(float *)malloc(5*sizeof(int)); //in c (allocating memory in heap - malloc allocate just raw memory i.e., it returns void type of pointer so typecast it)

    p[0]=11;
    p[1]=12;
    p[2]=13;
    p[3]=14;
    p[4]=15;

    int *b=new int[5]; // in cpp

    //Taking array elements from the user
    cout<<"Enter 5 elements:";
    for(int i=0; i<5; i++)
    {
        cin>>b[i];
    }

    // Printing array elements of b[]
    cout<<"Array elements are: "<<;

    for(int i=0; i<5; i++)
    {
        cout<<b[i]<<" ";

    }

    //printing array elements of a[]
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
    }

    //printing array elements of p[]
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<p[i]<<" ";
    }


}