#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
int main()
{
    struct dictionary
    {
        string pth,fy;
    };
    int k=1,m=131071;
    vector <dictionary> dic(m);
    string s;
    hash<string> hf;
    while (getline(cin,s)&&s.length()>0){
        dictionary temp;
        int i=s.find(' ');
        temp.pth=s.substr(0,i);
        temp.fy=s.substr(i+1);
        int index=hf(temp.fy)%m;
        while (dic[index].pth!=""){
            index=(index+k)%m;
        }
        dic[index]=temp;
    }
    while (cin>>s&&s.length()>0){
        int key=hf(s)%m,i=0;
        while (dic[key].fy!=s&&i<=m){
            key=(key+k)%m;
            i++;
        }
        if (i<=m){
            cout<<dic[key].pth<<endl;
        }
        else {
            cout<<"eh"<<endl;
        }
    }
    return 0;
}