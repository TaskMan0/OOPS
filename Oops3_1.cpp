#include<iostream>
#include<ctype.h>
#include<cstring>
using namespace std;

class cstr
{
    char c[200];
    public:
    cstr(char s[])
    {
        for(int i=0;s[i]!='\0';i++)
    {
        c[i]=s[i];
    }
    }
    bool ishexdig(char s[])
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(!isxdigit(s[i])){
            return false;
            }
        }
        return true;
    }
    bool isdig(char s[])
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(!isdigit(s[i])){
            return false;
            }
        }
        return true;
    }
    bool isalp(char s[])
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(!isalpha(s[i])){
            return false;
            }
        }
        return true;
    }
    int compare(char p[])
    {
        return strcmp(c,p);
    }
    char* findstring(char p[])
    {
        return strstr(c,p);
    }
    char* findcharac(char y)
    {
        return strchr(c,y);
    }
    void toupcase(char f[])
    {
    cout<<"The string \""<<f<<"\" after changing to upper case: ";
        for(int i=0;f[i]!='\0';i++)
        putchar(toupper(f[i]));
        cout<<endl;
    }
    void tolowcase(char f[])
    {
    cout<<"The string \""<<f<<"\" after changing to lower case: ";
        for(int i=0;f[i]!='\0';i++)
        putchar(tolower(f[i]));
        cout<<endl;
    }
};

int main(){
    char t[]="Hello Guys";
    cstr c2(t);
    char t2[]="ABC12546",t3[]="Programming",t4[]="8688796432";
    if(c2.ishexdig(t2))
    cout<<"The string \"ABC12546\" contains only hexa decimal."<<endl;
    if(c2.isalp(t3))
    cout<<"The string \"Programming\" contains only alphabet"<<endl;
    if(c2.isdig(t4))
    cout<<"The string \"8688796432\" contains only digits"<<endl;
    char r1[]="hello guys",r2[]="Guys",r3='y';
    cout<<"String comparison of \"Hello Guys\" with \"hello guys\": "<<c2.compare(r1)<<endl;
    char *o=c2.findstring(r2);
    if(o!=NULL)
    cout<<"The string "<<r2<<" is found in \"Hello Guys\""<<endl;
    char *e=c2.findcharac(r3);
    if(e!=NULL)
    cout<<"The character '"<<r3<<"' is found in \"Hello Guys\""<<endl;
    char r[]="desktop";
    c2.toupcase(r);
    char g[]="COMMANDER";
    c2.tolowcase(g);
    return 0;
}