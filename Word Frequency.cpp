#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T,i=0;
    cin>>T;
    while(T--){
        int count=0;
        string s,t,a;
        cin.ignore();
        getline(cin,s);
        cin>>t;
        for (int j=0;j<=s.length();j++){
            if (s[j]!=' '&&s[j]!=0){
                a+=s[j];
            }
            else {
                if (a==t){
                    count++;
                }
                a.clear();
            }
        }
        cout<<"case #"<<i++<<":"<<endl;
        cout<<count<<endl;
    }
    return 0;
}