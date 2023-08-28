//lower-traingular

#include<iostream>
using namespace std;

class lowerTraingle
{
    private:
        int *A;
        int n;
    public:
    lowerTraingle(int n)
    {
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    ~lowerTraingle()
    {
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    int getDimension(){ return n;}
};

void lowerTraingle::set(int i,int j,int x)
{
    if(i>=j)
    {
        A[i*(i-1)/2+j-1]=x;
    }
}

int lowerTraingle::get(int i,int j)
{
    if(i>=j)
    {
        return A[i*(i-1)/2+j-1];
    }
    return 0;
}

void lowerTraingle::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
            {
                cout<<A[i*(i-1)/2+j-1]<<" ";
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
    lowerTraingle low(d);
    int x;
    cout<<"Enter all elements: "<<endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            low.set(i,j,x);
        }
    }

    cout<<"Lower Traingular matrix is: "<<endl;
    low.display();
    cout<<"Dimenstion of Lower traingular matrix is :"<<low.getDimension()<<endl;

    cout<<"Element at index [3,2] is: "<<low.get(3,2)<<endl;

    return 0;
}