#include<iostream>
using namespace std;

//finding duplicate elements =O(n)
void findDup()
{
    int arr[]={1,3,4,4,5,7,8,8,9,10},n=10,lastDup=0;
    cout<<"Duplicate elemenets are: ";
    for(int i=0; i<n; i++)
    {
        if(arr[i]==arr[i+1] && lastDup!=arr[i])
        {
            cout<<arr[i]<<" ";
            lastDup=arr[i];
        }
    }
}

//counting the duplicate elements = O(n)
void countDup()
{
    int arr[]={1,3,4,4,5,7,8,8,8,9,10},n=10;
    cout<<"\nCount of duplicate elements are: \n";
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]==arr[i+1])
        {
            int j=i+1;
            while(arr[j]==arr[i])
                j++;
            cout<<arr[i]<<":"<<j-i<<endl;
            i=j-1;
        }
    }
}
//Using hash  table = O(n)
void countDup2()
{
    int arr[]={1,3,4,4,5,7,8,8,8,9,10},n=10;
    int H[arr[10]]={0};
    for(int i=0; i<=n; i++)
    {
        H[arr[i]]++;
    }
    cout<<"\nCount of duplicate elements are: \n";
    for(int i=0; i<n;i++)
    {
        if(H[i]>1)
            cout<<i<<": "<<H[i]<<endl;
    }
    
}

//Finding duplicate in unsorted array
void countDup3()
{
    cout<<"Duplicate elements in unsorted array are:"<<endl;
    int arr[]={3,7,4,8,4,2,10,8,1,10},n=10,count=0;
    for(int i=0; i<n-1;i++)
    {
        count=1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<n; j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    arr[j]=-1;
                }
            }
        }
        if(count>1)
            cout<<arr[i]<<" "<<count<<endl;
    }
}

//Finding duplicate in unsorted array using hash table
void countDup4()
{
    cout<<"Duplicate elements in the array are:\n";
    int arr[]={3,7,4,8,4,2,10,8,1,10},n=10,count=0;
    int H[11]={0};
    for(int i=0; i<n;i++)
    {
        H[arr[i]]++;
    }
    for(int i=0;i<=n;i++)
    {
        if(H[i]>1)
        {
            cout<<i<<": "<<H[i]<<endl;
        }
    }
}
int main()
{
    findDup();
    countDup();
    countDup2();
    countDup3();
    countDup4();
    return 0;
}