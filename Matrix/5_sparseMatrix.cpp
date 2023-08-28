#include<iostream>
using namespace std;

class Element
{
    public:
    int i,j,x;
};

class sparse
{
    private:
    int m,n,num;
    Element *e;
    public:
    sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        e=new Element[this->num];
    }
    ~sparse()
    {
        delete []e;
    }

   sparse operator+(sparse &s);
   friend istream & operator>>(istream &is,sparse &s);
   friend ostream & operator<<(ostream &os,sparse &s);
};
    istream & operator>>(istream &is,sparse &s)
    {
        cout<<"Enter non-zero elements"<<endl;
        for(int i=0; i<s.num; i++)
        {
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
        return is;
    }
    ostream & operator<<(ostream &os,sparse &s)
    {
        int i,j,k=0;
        for(i=0; i<s.m; i++)
        {
            for(j=0; j<s.n; j++)
            {
                if(i==s.e[k].i && j==s.e[k].j)
                {
                    cout<<s.e[k++].x<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        return os;
    }

    sparse sparse:: operator+(sparse &s)
    {
        int i,j,k=0;
        if(m!=s.m && n!=s.n)
            return sparse(0.0,0.0,0.0);
        sparse *sum=new sparse(m,n,num+s.num);

        while(i<num && j<s.num)
        {
            if(e[i].i<s.e[j].i)
                sum->e[k++]=e[i++];
            else if(e[i].i>s.e[j].i)
                sum->e[k++]=s.e[j++];
            else{
                 if(e[i].j<s.e[j].j)
                sum->e[k++]=e[i++];
            else if(e[i].j>s.e[j].j)
                sum->e[k++]=s.e[j++];
            else
            {
                sum->e[k]=e[i];
                sum->e[k++].x=e[i++].x+s.e[j++].x;
            }
            }
        }
        for(;i<num;i++)sum->e[k++]=e[i];
        for(;j<s.num;j++) sum->e[k++]=s.e[j];
        sum->num=k;
        return *sum;
    }

int main()
{   int m,n,num;
    cout<<"Enter Dimension of Matrix: ";
    cin>>m>>n;
    cout<<"\nEnter number of non-zero elements: ";
    cin>>num;

    sparse s1(m,n,num);
    sparse s2(m,n,num);
    
    cin>>s1;
    cin>>s2;

    sparse sum=s1+s2;

    cout<<"First Matrix" <<endl<<s1;
    cout<<"Second Matrix"<<endl<<s2;
    cout<<"Sum Matrix"<<endl<<sum;
    return 0;
}