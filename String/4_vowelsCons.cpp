#include<iostream>
using namespace std;

void count1(char s[])
{
    int vcount=0,ccount=0;
    for(int i=0; s[i]!='\0';i++)
    {
        if(s[i]=='a' || s[i]=='e'| s[i]=='i' | s[i]=='o' | s[i]=='u' | s[i]=='A' | s[i]=='E' | s[i]=='I' | s[i]=='O' | s[i]=='U')
        {
            vcount++;
        }
        else if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
        {
            ccount++;
        }
    }
    cout<<"Vowels count = "<<vcount<<endl;
    cout<<"Consonents count = "<<ccount<<endl;
}

void countWord(char s[])
{
    int word=1;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]==' ' && s[i-1]!=' ')
            word++;
    }
    cout<<"Total words are: "<<word<<endl;
}
int main()
{
    char s[]="How are you";
    count1(s);
    countWord(s);
    return 0;
}