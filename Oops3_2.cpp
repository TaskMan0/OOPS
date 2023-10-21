#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    int i,p=0,j=0,k=0;
    string s,t[100],l;
    getline(cin,s);
    l=s;    
    p=s.find('.',k+1);
    t[j++]=s.substr(k,p+1);
    s.erase(0,p+1);
    while(s[p+1]!='\0')
    {
        p=s.find('.',0);
        t[j]=s.substr(0,p+1);
        s.erase(0,p+1);
        j++;
    }
    ofstream o;
    o.open("2.txt");
    cout<<"\"Writing to the file line by line\""<<endl;
    for(i=0;i<j;i++)
    {
        o<<t[i]<<endl;
    }
    o.close();
    ifstream f;
    string h;
    f.open("2.txt");
    cout<<"\"Reading from the file line by line\""<<endl;
    while(!f.eof())
    {
        getline(f,h);
        cout<<h<<endl;
    }
    return 0;
}