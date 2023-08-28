#include<iostream>
using namespace std;

class Array
{
private:
    int A[20];
    int size;
    int length;
    void swap(int *x,int *y);
public:
    Array()
    {
        size=20;
        length=0;
    }
    void create();
    void display();
    void append(int ele);
    void insert(int index,int x);
    void Delete(int index);
    int linearSearch(int key);
    void sort();
    int iterativeBinSearch(int key);
    int recursiveBinSearch(int key,int l,int h);
    int get(int index);
    void set(int index,int val);
    int max();
    int min();
    int sum();
    int avg();
    void reverse();
    void insertInSorted(int key);
    bool isSorted();
    void  leftNegative();
    void merge(int arr1[],int arr2[],int n,int m);
};

void Array::swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

// Creating an array by accepting elemenets from users
void Array::create()
{
    cout << "Enter the no of elements: ";
    cin>>length;
    cout<<"Enter the "<<length<<" elements\t: ";
    for(int i=0; i<length; i++)
    {
        cin>>A[i];
    }
}
//Displaying array elements
 void Array::display()
    {
        for(int i=0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
    }

//Appending an element at the end of the array elements
void Array:: append(int ele)
{
   if(length<size)
        A[length++]=ele;

    cout<<"\nAppending an element\t: ";
}

//inserting an element at given index
void Array:: insert(int index,int x)
{
    if(index>=0 && index <=length)
    {
    for(int i=length; i>index; i--)
    {
        A[i]=A[i-1];
    }

    A[index]=x;
    length++;
    cout<<"\nInserting an element\t: ";
    }
}

//deleting element of the given index
void Array:: Delete(int index)
{
    int x=A[index];

    if(index >=0 && index <= length)
    {
        for(int i = index ; i < length-1 ; i++)
        {
            A[i] = A[i+1];
        }

       length--;

        cout<<"\nDeleted element is\t: "<<x<<endl;
        cout<<"Deleting an element\t: ";
    }
}


//Searching an key elmemt in the array and returning an index
int Array:: linearSearch(int key)
{
   
    for(int i=0; i < length; i++)
    {
        if(key==A[i])
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
void Array:: sort()
{
    for(int i=0; i<length-1; i++)
    {
        for(int j=i+1; j<length; j++)
        {
            if(A[i]>A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        }
    }
}

//Interative Binary Search
int Array:: iterativeBinSearch(int key)
{
    int l=0,h=length,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(A[mid]==key)
            return mid;
        else if(key<A[mid])
            h=mid-1;
        else    
            l=mid+1;
    }
    return -1;
}

//Returning elememt at given index
int Array:: get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

//setting number at given index
void Array::set(int index,int val)
{
    if(index>=0 && index<length)
        A[index]=val;
}

//finding maximum of array
int Array::max()
{
    int max=A[0];
    for(int i=0; i<length; i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

//finding minimum of array
int Array:: min()
{
    int min=A[0];
    for(int i=0; i<length; i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

//finding sum of the array elements
int Array::sum()
{
    int total=0;
    for(int i=0; i<length; i++)
    {
        total+=A[i];
    }
    return total;
}

//finding average of array
int Array::avg()
{
    int total=0;
    for(int i=0; i<length; i++)
    {
        total+=A[i];
    }
    return total/length;
}

//Reversing an array 
void Array::reverse()
{
    for(int i=0,j=length-1; i<j; i++,j--)
    {
        swap(&A[i] , &A[j]);
    }
}

//Inserting an element in sorted array
void Array::insertInSorted(int key)
{
    if(length==size)
        return;
    else
    {
        int i=length-1;
        while(i>=0 && A[i]>key)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
        length++;
    }
}

//Checking arrayn is sorted or not
bool Array::isSorted()
{
  for(int i=0; i<length-1; i++)
  {
    if(A[i]>A[i+1])
        return false;
  }
  return true;
}

//Shifting -ve elements to left side
void Array:: leftNegative()
{
    int i=0,j=length-1;
    while(i<j)
    {
        while(A[i]<0)
            i++;
        while(A[j]>=0)
            j--;
        
        if(i<j)
         swap(&A[i] , &A[j]);
    }
}

//Merging thw two arrays
void Array:: merge(int arr1[],int arr2[],int n,int m)
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
    r.create();
    cout<<"Array elements are\t: ";
    r.display();

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
        r.append(8);
        r.display();
        break;
    case 2:
        //Calling insert function
        r.insert(4,10);
        r.display();
        break;
    case 3:
        //Calling delete function
        r.Delete(1);
        r.display();
        break;
    case 4:
        //Linear search
        int key;
        cout<<"\nEnter element to search : "<<flush;
        cin>>key;
        cout<<key<<" is found at index\t: "<< r.linearSearch(key)<<endl;
        break;
    case 5:
        //Binary Search
        r.sort();
        cout<<"Enter element to search : "<<flush;
        cin>>key;
        cout<<key<<" is found at index\t: "<< r.iterativeBinSearch(key)<<endl;
        break;
    case 6:
        //Get number of specified index
        cout<<"Number at 4th index is\t: "<<r.get(4)<<endl;
        //set number at given index
        r.set(3,10);
        break;
    case 7:
        //Maximum number
         cout<<"Maximum number is\t: "<<r.max()<<endl;

        //Minimum number
        cout<<"Minimum number is\t: "<<r.min()<<endl;

        //Sum of an array is
        cout<<"Sum of array is\t\t: "<<r.sum()<<endl;

        //avg of array 
        cout<<"Avg of array is\t\t: "<<r.avg()<<endl;
        break;
    case 8:
        //Reversing an array
        r.reverse();
        cout<<"After reversing\t\t: ";
        r.display();
        break;
    case 9:
        //Inserting an element in sorted array
        r.sort();
        cout<<"\nEnter element to insert : ";
        cin>>key;
        r.insertInSorted(key);
        cout<<"Inserted in Sorted array: ";
        r.display();

        //Checking array is sorted or not
        if(r.isSorted())
            cout<<"\n ---------- Array is Sorted --------------"<<endl;
        else    
            cout<<" ------------ Array is not sorted ----------"<<endl;
        break;
    case 10:
        //Sorting an array in such a way that negative elements are at left side
        cout<<"Enter -ve & +ve elements:"<<endl;
        r.create();
        r.leftNegative();
        cout<<"Array elements are\t: "; 
        r.display();
        break;

    case 11:
        // Merging two arrays 
        int arr1 [5] = {2, 5, 8, 11, 15};
        int arr2 [6] = {3, 6, 7, 9, 14, 18, };
        r.merge(arr1,arr2,5,6);
        break;

     }
    }while(ch!=12);
}