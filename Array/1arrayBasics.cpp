#include<iostream>
using namespace std;

int main()
{
    int A[5]={1,2,3,4,5};       // 1 2 3 4 5 
    int B[5]={2,5};            // 2 5 0 0 0 
    int c[5]={0};             // 0 0 0 0 0
    int D[]={1,2,3,4,5,6};   // 1 2 3 4 5 6

    cout<<A[2]<<endl;       // 3
    cout<<2[A]<<endl;      // 3
    for(int i=0; i<5; i++)
    {
        cout<<&A[i]<<endl;  // print address of array elements
    }
    return 0;
}