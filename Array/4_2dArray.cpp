#include<iostream>
using namespace std;

int main()
{
    int n=3 , m=4;

    //array fully in the stack
    int arr1[n][m] = {{ 1,2,3,4}, { 5,6,7,8 }, { 9,10,11,12 }};
  
    //array partially inside stack & partially inside heap
    int *arr2[n];
    arr2[0]=new int[m];
    arr2[1]=new int[m];
    arr2[2]=new int[m];

    arr2[2][3]=15;
    
    //fully inside the heap
    int ** arr3;    // double pointer- pointer to pointer,& it stores the address of the other pointer.
    arr3=new int * [n];  //array of pointers of type int
    arr3[0]=new int[m];
    arr3[1]=new int[m];
    arr3[2]=new int[m];

    arr3[1][2]=20;

    //displaying array elements;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}