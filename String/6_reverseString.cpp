#include<iostream>
using namespace std;

void reverse1(char a[])
{
    char b[7];
    int i,j;
    for(i=0; a[i]!='\0'; i++){}
    i=i-1;
    for(j=0; i>=0; i--,j++)
    {
        b[j]=a[i];
    }
    b[j]='\0';
    cout<<"Reverse string is: "<<b<<endl;
}

void reverse2(char a[])
{
    int i,j;
    char temp;
    for(j=0;a[j]!='\0';j++)
    {

    }
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    cout<<"Reverse string is:"<<a<<endl;
}
int main()
{
    char a[]="Pyhton";
    reverse1(a);
    reverse2(a);
    return 0;
}