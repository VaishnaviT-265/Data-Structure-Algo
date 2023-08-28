#include<iostream>
using namespace std;

int main()
{
    char a[]="decimal";
    char b[]="medicalk";
    int H[26]={0},i;

    for(i=0; a[i]!=0; i++)
    {
        H[a[i]-97]++;
    }

    for(i=0; b[i]!='\0'; i++)
    {
        H[b[i]-97]--;
        if(H[b[i]-97]<0)
        {
            cout<<"Not Anagram";
            return 0;
        }

    }
    if(b[i]=='\0')
        cout<<"It is Anagram"<<endl;
    return 0;
}