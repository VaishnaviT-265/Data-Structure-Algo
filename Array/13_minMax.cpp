#include <iostream>
using namespace std;

int main()
{
    int arr[]={2,6,-1,7,3,4,10,8,15,9},n=10,min=arr[0],max=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        else if(arr[i]>max)
            max=arr[i];
    }
    cout<<"min= "<<min<<endl<<"max= "<<max;
    return 0;
}