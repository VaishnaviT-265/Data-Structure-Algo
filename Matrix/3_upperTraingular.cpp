//Column-major

#include<iostream>
using namespace std;

class upperTraingle
{
    private:
        int *A;
        int n;
    public:
    upperTraingle(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    ~upperTraingle()
    {
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    int getDimension(){ return n;}
};

void upperTraingle::set(int i,int j,int x)
{
    if(i<=j)
    {
        A[j*(j-1)/2+i-1]=x;
    }
}

int upperTraingle::get(int i,int j)
{
    if(i<=j)
    {
        return A[j*(j-1)/2+i-1];
    }
    return 0;
}

void upperTraingle::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j)
            {
                cout<<A[j*(j-1)/2+i-1]<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int d;
    cout<<"Enter dimension: ";
    cin>>d;
    upperTraingle upper(d);
    int x;
    cout<<"Enter all elements: "<<endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            upper.set(i,j,x);
        }
    }

    cout<<"Lower Traingular matrix is: "<<endl;
    upper.display();
    cout<<"Dimenstion of Upper traingular matrix is :"<<upper.getDimension()<<endl;

    cout<<"Element at index [3,2] is: "<<upper.get(1,1)<<endl;

    return 0;
}