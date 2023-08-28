#include<iostream>
using namespace std;

//Finding duplicate letters by comparing with others
void dup1(char str[])
{
    int i;
    cout<<"Duplicate in string 'Finding' are: ";
    for( i=0; str[i]!='\0'; i++)
    {
        for(int j=i+1; str[j]!='\0';j++)
        {
            if(str[i]==str[j]){
                cout<<str[i]<<" ";
                break;
            }
        }
    }
}
void dup2(char str[])
{
    cout<<"\nDuplicate in string are:";
    int H[26]={0},i;
    for(i=0; str[i]!='\0'; i++)
    {
        H[str[i]-97]++;
    }
    for(int i=0; i<26; i++)
    {
        if(H[i]>1)
        {
            char ans=i+97;
            cout<<ans<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    char str[]="Finding";
    dup1(str);
    dup2(str);
    
    return 0;
}