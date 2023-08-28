#include<iostream>
using namespace std;

int main()
{
    char a[]="Painter";
    char b[]="Painter";
    int i,j;
    for(i=0,j=0;a[i]!='\0' && b[i]!='\0'; i++,j++)
    {
        if(a[i]!=b[i])
            break;
    }
    if(a[i]==b[j])
        cout<<"Strings are equal";
    else if(a[i]<b[j])
        cout<<"String 1 is greater";
    else    
        cout<<"String 2 is greater";
    return 0;
}