#include<iostream>
using namespace std;

//Structure Array
struct Array{
    int A[20];
    int size=20;
    int length;
};

// Creating an array by accepting elemenets from users
void create(Array *r)
{
    cout<<"Enter the no of elements: ";
    cin>>r->length;
    cout<<"Enter the "<<r->length<<" elements\t: ";
    for(int i=0; i<r->length; i++)
    {
        cin>>r->A[i];
    }
}

//Displaying array elements
void display(Array r)
{
    for(int i=0; i<r.length; i++)
    {
        cout<<r.A[i]<<" ";
    }
}

//Appending an element at the end of the array elements
void append(Array *arr, int ele)
{
   if(arr->length<arr->size)
        arr->A[arr->length++]=ele;

    cout<<"\nAppending an element\t: ";
}

//inserting an element at given index
void insert(Array *arr,int index,int x)
{
    if(index>=0 && index <= arr->length)
    {
    for(int i=arr->length; i>index; i--)
    {
        arr->A[i]=arr->A[i-1];
    }

    arr-> A[index]=x;
    arr-> length++;
    cout<<"\nInserting an element\t: ";
    }
}

//deleting element of the given index
void Delete(Array *r,int index)
{
    int x=r->A[index];

    if(index >=0 && index <= r->length)
    {
        for(int i = index ; i < r->length-1 ; i++)
        {
            r->A[i] = r->A[i+1];
        }

        r->length--;

        cout<<"\nDeleted element is\t: "<<x<<endl;
        cout<<"Deleting an element\t: ";
    }
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//Searching an key elmemt in the array and returning an index
int linearSearch(Array *arr,int key)
{
   
    for(int i=0; i < arr->length; i++)
    {
        if(key==arr->A[i])
        {
            return i;
            /* There are two methods to improve array 1) Transformation 2) Move to Front

            1) Transformation -> In this we swap the key element with its previous element 
               swap(&arr->A[i],&arr->A[i-1]);
            

            2) Move to front -> Swap the key element with first index element so the next time if we search for the same element it will become easier
               swap(&arr -> A[i], &arr -> A[0]); */
        }
        
    }
    return -1;
}

//Sorting the array
void sort(Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
    {
        for(int j=i+1; j<arr->length; j++)
        {
            if(arr->A[i]>arr->A[j])
        {
            int temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
        }
    }
}

//Interative Binary Search
int iterativeBinSearch(Array arr,int key)
{
    int l=0,h=arr.length,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr.A[mid]==key)
            return mid;
        else if(key<arr.A[mid] )
            h=mid-1;
        else    
            l=mid+1;
    }
    return -1;
}

//Recursive binary searcint 
recursiveBinSearch(Array arr,int key,int l,int h)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(arr.A[mid]==key)
            return mid;
        else if(key<arr.A[mid])
            return recursiveBinSearch(arr,key,l,mid-1);
        else
            return recursiveBinSearch(arr,key,mid+1,h);
    }
    return -1;
}

//Returning elememt at given index
int get(Array r,int index)
{
    if(index>=0 && index<r.length)
        return r.A[index];
    return -1;
}

//setting number at given index
void set(Array *r,int index,int val)
{
    if(index>=0 && index<r->length)
        r->A[index]=val;
}

//finding maximum of array
int max(Array r)
{
    int max=r.A[0];
    for(int i=0; i<r.length; i++)
    {
        if(r.A[i]>max)
            max=r.A[i];
    }
    return max;
}

//finding minimum of array
int min(Array r)
{
    int min=r.A[0];
    for(int i=0; i<r.length; i++)
    {
        if(r.A[i]<min)
            min=r.A[i];
    }
    return min;
}

//finding sum of the array elements
int sum(Array r)
{
    int total=0;
    for(int i=0; i<r.length; i++)
    {
        total+=r.A[i];
    }
    return total;
}

//finding average of array
int avg(Array r)
{
    int total=0;
    for(int i=0; i<r.length; i++)
    {
        total+=r.A[i];
    }
    return total/r.length;
}

//Reversing an array 
void reverse(Array *r)
{
    for(int i=0,j=r->length-1; i<j; i++,j--)
    {
        swap(&r->A[i] , &r->A[j]);
    }
}

//Inserting an element in sorted array
void insertInSorted(Array *r,int key)
{
    if(r->length==r->size)
        return;
    else
    {
        int i=r->length-1;
        while(i>=0 && r->A[i]>key)
        {
            r->A[i+1]=r->A[i];
            i--;
        }
        r->A[i+1]=key;
        r->length++;
    }
}

//Checking arrayn is sorted or not
bool isSorted(Array r)
{
  for(int i=0; i<r.length-1; i++)
  {
    if(r.A[i]>r.A[i+1])
        return false;
  }
  return true;
}

//Shifting -ve elements to left side
void  leftNegative(Array *r)
{
    int i=0,j=r->length-1;
    while(i<j)
    {
        while(r->A[i]<0)
            i++;
        while(r->A[j]>=0)
            j--;
        
        if(i<j)
         swap(&r->A[i] , &r->A[j]);
    }
}

//Merging thw two arrays
void merge(int arr1[],int arr2[],int n,int m)
{
    int arr3[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    for(;i<n;i++)
        arr3[k++]=arr1[i++];
    for(;j<m;j++)
        arr3[k++]=arr2[j++];
    
    cout<<"\nPrinting merged arrays: ";
    for(int i=0; i<n+m; i++)
    {
        cout<<arr3[i]<<" ";
    }
}

int main()
{
    Array r;
    int ch;
    //Calling create function
    create(&r);
    cout<<"Array elements are\t: ";
    display(r);

    do
    {
    cout<<"\n-----------------* MENU *-------------------------\n";
    cout<<"1. Append Element\n2. Insert Element \n3. Delete Element \n4. Linear Search \n5. Binary Search \n6. Get & set Index \n7. Find min,max,sum,avg \n8. Reverse Array \n9. Insert in Sorted Array \n10. Positive ,Negative elements of array \n11. Merge array \n12. Exit";
    cout<<"\nEnter your choice: ";
    cin>>ch;
   switch (ch)
   {
   case 1:
   //Calling append function
        append(&r,8);
        display(r);
        break;
    case 2:
        //Calling insert function
        insert(&r,4,10);
        display(r);
        break;
    case 3:
        //Calling delete function
        Delete(&r,1);
        display(r);
        break;
    case 4:
        //Linear search
        int key;
        cout<<"\nEnter element to search : "<<flush;
        cin>>key;
        cout<<key<<" is found at index\t: "<< linearSearch(&r,key)<<endl;
        break;
    case 5:
        //Binary Search
        sort(&r);
        cout<<"Enter element to search : "<<flush;
        cin>>key;
        cout<<key<<" is found at index\t: "<< iterativeBinSearch(r,key)<<endl;
        cout<<key<<" is found  at index\t: "<< recursiveBinSearch(r,key,0,r.length)<<endl;
        break;
    case 6:
        //Get number of specified index
        cout<<"Number at 4th index is\t: "<<get(r,4)<<endl;
        //set number at given index
        set(&r,3,10);
        break;
    case 7:
        //Maximum number
         cout<<"Maximum number is\t: "<<max(r)<<endl;

        //Minimum number
        cout<<"Minimum number is\t: "<<min(r)<<endl;

        //Sum of an array is
        cout<<"Sum of array is\t\t: "<<sum(r)<<endl;

        //avg of array 
        cout<<"Avg of array is\t\t: "<<avg(r)<<endl;
        break;
    case 8:
        //Reversing an array
        reverse(&r);
        cout<<"After reversing\t\t: ";
        display(r);
        break;
    case 9:
        //Inserting an element in sorted array
        sort(&r);
        cout<<"\nEnter element to insert : ";
        cin>>key;
        insertInSorted(&r, key);
        cout<<"Inserted in Sorted array: ";
        display(r);

        //Checking array is sorted or not
        if(isSorted(r))
            cout<<"\n ---------- Array is Sorted --------------"<<endl;
        else    
            cout<<" ------------ Array is not sorted ----------"<<endl;
        break;
    case 10:
        //Sorting an array in such a way that negative elements are at left side
        cout<<"Enter -ve & +ve elements:"<<endl;
        create(&r);
        leftNegative(&r);
        cout<<"Array elements are\t: "; 
        display(r);
        break;

    case 11:
        // Merging two arrays 
        int arr1 [5] = {2, 5, 8, 11, 15};
        int arr2 [6] = {3, 6, 7, 9, 14, 18, };
        merge(arr1,arr2,5,6);
        break;

     }
    }while(ch!=12);
}