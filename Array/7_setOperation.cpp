#include<iostream>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void union1(int arr1[],int arr2[])
{
    int res[10];
    int i,j,k=0;
    while(i<5 && j<5)
    {
        if(arr1[i]<arr2[j])
        {
            res[k++]=arr1[i++];
        }
        else if(arr1[i]==arr2[j])
        {
            res[k++]=arr1[i++];
            j++;
        }
        else
        {
            res[k++]=arr2[j++];
        }
    }
    display(res,7);
}

void diff(int arr1[],int arr2[])
{
    int arr3[5],k=0,i=0,j=0;   
    while(i<5 && j<5)
    {
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else if(arr2[j]<arr1[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    display(arr3,5);
}

void intersect(int arr1[],int arr2[])
{
    int ans[5],i=0,j=0,k=0;
    while(i<5 && j<5)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]==arr2[j])
        {
            ans[k++]=arr1[i++];
            j++;
        }
        else if(arr2[j]<arr1[i])
            j++;
    }
    display(ans,2);
}
int main()
{
    int arr1 [5] = { 2,5,7,9,10};
    int arr2 [5] = { 1,5,6,9,11};


    // union of sorted arrays
    union1(arr1,arr2);

    //intersection of sorted arrays
    intersect(arr1,arr2);
   
    

    // difference of sorted arrays
    diff(arr1,arr2);

    return 0;
}