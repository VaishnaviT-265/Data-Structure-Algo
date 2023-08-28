#include<iostream>
using namespace std;

//displaying an array
void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Rotating an array
void rotate(int arr[],int n)
{
    int last=arr[0];
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=last;
    cout<<"Rotating an array \t: ";
    display(arr,n);
}

//Left shifting an array elements
void left_shift(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=0;
    cout<<"Left shifting an array\t: ";
    display(arr,n);
}

//Right shifting an array elements
void right_shift(int arr[],int n)
{
    for(int i=n; i>0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=0;

    cout<<"Right shifting an array\t: ";
    display(arr,n);
}
int main()
{
    int arr[]={1,2,3,4,5};

    cout<<"Before shifting an array: ";
    display(arr,5);
    
    //Rotating an array 
    rotate(arr,5);

    //Left shifting an array
    left_shift(arr,5);

    //Right shifting an array
    right_shift(arr,5);

    return 0;
}l