#include<iostream>
using namespace std;

//Finding permutatin using another array
void perm(string s,int k)
{
    static int A[10]={0};
    static char res[10];
    int i;
    if(s[k]=='\0')
    {
        res[k]='\0';
        cout<<res<<" ";
    }
    else
    {
        for(i=0; s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}



//Finding permutation using swapping 
void perm1(string &s,int l,int h)
{
    int i;
    if(l==h)
    {
        cout<<s<<" ";
    }
    else
    {
        for(i=l; i<=h; i++)
        {
            swap(s[l],s[i]);
            perm1(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}
int main()
{
    string str="ABC";
    int n=str.size();
    perm(str,0);
    cout<<endl;
    perm1(str,0,n-1);
    return 0;
}