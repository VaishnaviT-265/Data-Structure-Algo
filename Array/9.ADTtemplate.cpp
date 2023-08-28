#include<iostream>
using namespace std;

template<class T>
class Array{
private:
    T A[20];
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
    void append(T ele);
};
template<class T>
void Array<T>::create(){
    cout << "Enter the no of elements: ";
    cin>>length;
    cout<<"Enter the "<<length<<" elements\t: ";
    for(int i=0; i<length; i++)
    {
        cin>>A[i];
    }
}
template<class T>
void Array<T>::display(){
    for(int i=0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
}
template<class T>
void Array<T>::append(T ele){
     if(length<size)
        A[length++]=ele;

    cout<<"\nAppending an element\t: ";
}

int main()
{
    Array<int> r;
    //Calling create function
    r.create();
    cout<<"Array elements are\t: ";
    r.display();
    r.append(10);
    r.display();

    return 0;
}