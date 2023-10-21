#include<iostream>
#include<fstream>

using namespace std;
struct temp
{
    int rollno;
    string name;
};

int main(){
    ofstream ptr;
    ptr.open("1.txt");
    ptr<<"This is made using ofstream object and will be printed using ifstream object"<<endl;
    ptr.close();
    ifstream ptr1;
    ptr1.open("1.txt");
    string s;
    ptr1>>s;
    while(!ptr1.eof())
    {
        cout<<s<<" ";
        ptr1>>s;
    }
    cout<<endl;
    ptr1.close();
    fstream l,k;
    l.open("2.txt",ios::in);
    if(l.fail())
    {
        cerr<<"As file doesn't exist, no file is created"<<endl;
    }
    l.close();
    char c;
    k.open("1.txt",ios::in);
    k<<"Lohith";
    if(k.bad())
    {
        cout<<"Invalid operation"<<endl;
    }
    fstream g;
    g.open("2.txt",ios::in);
    g.clear();
    if(g.good())
    {
        cout<<"No invalid operation even after performing clear"<<endl;
    }
    g.close(),k.close();
    fstream i,o;
    o.open("4.txt",ios::out|ios::trunc);
    string e="This is written to file char by char and will be read char by char";
    for(int j=0;j<e.size();j++)
    {
        o.put(e[j]);
    }
    o.close();
    i.open("4.txt",ios::in);
    char t;
    while(!i.eof())
    {
       i.get(t);
       cout<<t;
    }
    i.close();
    o.open("4.txt",ios::app);
    o<<" and it is appended";
    o.close();
    i.open("4.txt",ios::in);
    string d;
    getline(i,d);
    cout<<endl<<d<<endl;
    i.close();
    i.open("4.txt",ios::ate | ios::binary);
    int x=0;
    i.get(d[x]);
    while(!i.eof())
    {
        i.get(d[++x]);
    }
    cout<<"Printing using pointer at the end\n"<<d<<endl;
    i.close();
    o.open("5.txt",ios::out);
    string E[2]={"This is written to file line by line","Will be printed line by line"};
    for(int r=0;r<2;r++)
    {
       o<<E[r]<<endl;
    }
    o.close();
    i.open("5.txt",ios::in);
    while(!i.eof())
    {
        getline(i,d);
        cout<<d<<endl;
    }
    i.close();
    o.open("6.txt",ios::out);
    temp y;
    y.rollno=12212015;
    y.name="Lohith";
    o.write((char*)&y,sizeof(y));
    o.close();
    i.open("6.txt",ios::in);
    i.read((char*)&y,sizeof(y));
    i.close();
    i.open("4.txt",ios::in);
    //lets read the original text in the file
    getline(i,d);
    cout<<d<<endl;
    //lets read from the 8th position;
    i.seekg(8,ios::beg);
    cout<<"The pointer is at "<<i.tellg()<<endl;
    getline(i,d);
    cout<<d<<endl;
    i.close();
    o.open("7.txt",ios::out);
    o<<"In the world of cinema, LCU has created an immensive response in audience";
    cout<<"The pointer is at "<<o.tellp()<<endl;
    o.seekp(22);
    cout<<"The pointer is at "<<o.tellp()<<endl;
    o<<" not always ";
    o.close();
    //Output after changing usind seekp is
    i.open("7.txt",ios::in);
    getline(i,d);
    cout<<d<<endl;
    i.close();
    return 0;
}