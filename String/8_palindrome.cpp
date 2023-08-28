#include<iostream>
using namespace std;

int main()
{
    char str[]="MADAM";
    int j,i;
    for(j=0; str[j]!='\0'; j++){}
    j=j-1;
    for(i=0;i<j; i++,j--)
    {
        if(str[i]!=str[j])
        {
            cout<<"String is not palindrome";
            return 0;
        }

    }
    cout<<"String is palindrome";
    return 0;
}