// Finding missing element in an array

#include<iostream>
using namespace std;
//Finding missing element in first n natural numbers
void single()
{
    int arr[]={1,2,3,4,5,6,8,9,10},sum=0,n=10;
    for(int i=0; i<n-1;i++)
    {
        sum+=arr[i];
    }
    int s=n*(n+1)/2;
    cout<<"Missing element in first n Natural numbers is :"<<s-sum<<endl;
}

//finding missing element in any sorted sequence
void single1()
{
    int arr1[]={6,7,8,9,10,11,13,14,15,16,17},n=10;
    int diff=arr1[0]-0;
    cout<<"Missing element in sequence is :";
    for (int i=0; i<n; i++)
    {
        if(diff!=arr1[i]-i)
        {
            cout<<i+diff<<endl;
            break;
        }
    }
}

//finding multiple missing in sorted elements
void multiple()
{
    int arr2[]={6,7,8,9,11,12,15,16,17,18,19},n=11,diff=arr2[0]-0;
    cout<<"Missing elements are: ";

    for(int i=0; i<n; i++)
    {
        if(arr2[i]-i!=diff)
        {
            while(diff<arr2[i]-i)
            {
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}

//finding multiple elements in unsorted elements
void multiple1()
{
    int arr3[]={4,7,3,6,12,8,9,5,2,10};
    int n=10,l=1,h=12;
    int H[h]={0};
    for(int i=0; i<n; i++)
        H[arr3[i]]++;
    cout<<"\nMissing elements in unsorted array are:";
    for(int i=l;i<=h;i++)
    {
        if(H[i]==0)
            cout<<i<<" ";
    } 
}
int main()
{
    single();
    single1();
    multiple();
    multiple1();
    return 0;
}