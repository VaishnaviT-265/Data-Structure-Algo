//Changing case from uppercase to Lowercase
//As ASCII code of A=65...Z=90 & a=97....z=122
//So for a= 97-65=32

#include<iostream>
using namespace std;

int main()
{
    char s[]="WELCOME";
    char s1[]="welcome";
    for(int i=0; s[i]!='\0';i++)
    {
        s[i]+=32;
    }
    for(int i=0; s[i]!='\0';i++)
    {
        s[i]-=32;
    }
    cout<<s<<endl<<s1<<endl;
    return 0;
}