#include<iostream>
using namespace std;

//Find pair of elements with sum k
void pairWithSum()
{
    int arr[]={6,3,8,10,16,7,5,2,9,14},k=10,n=10;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==k)
                cout<<arr[i]<<" + "<<arr[j]<<" = "<<k<<endl;
        }
    }
}

//using hash table
void pairWithHash()
{
    cout<<"Finding pair with sum k: "<<endl;
    int arr[]={6,3,8,10,16,7,5,2,9,14},k=10,n=10;
    int H[14]={0};
    for(int i=0; i<n; i++)
    {
        if(H[k-arr[i]]>=1 && arr[i]<=k)
            cout<<arr[i]<<" + "<<k-arr[i]<<" = "<<k<<endl;
        H[arr[i]]++;
    }
}

//Finding pair with sum k in sorted array
void pairSort()
{
    cout<<"Finding pair with sum k in sortd array:"<<endl;
    int arr[]={1,3,4,5,6,8,9,10,12,14},n=10,k=10;
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==k)
        {
            cout<<arr[i]<<" + "<<arr[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]<k)
            i++;
        else
            j--;
    }
}
int main()
{
    pairWithSum();
    pairWithHash();
    pairSort();
    return 0;
}