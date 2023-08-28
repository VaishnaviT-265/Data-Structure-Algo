#include<iostream>
using namespace std;

class matrix
{
    private:
        int A[10];
        int n;
    public:
        matrix(int a)
        {
            n=a;
        }

        void set(int i,int j,int x)
        {
            if(i==j)
                A[i-1]=x;
        }

        int get(int i,int j)
        {
            if(i==j)
            {
                return A[i-1];
            }
            return 0;
        }

        void display()
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i==j)
                    {
                        cout<<A[i]<<" ";
                    }
                    else
                    {
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
};
int main()
{
    matrix m(4);
    m.set(1,1,10);
    m.set(2,2,20);
    m.set(3,3,30);
    m.set(4,4,40);
    cout<<"Diagonal matrix is "<<endl;
    m.display();
    cout<<"The value at [2,2] is: "<<m.get(2,2)<<endl;
    return 0;
}