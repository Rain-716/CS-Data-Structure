#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int N;
    cin>>N;
    while (N--){
        int a,b;
        string s1,s2;
        cin>>a>>b>>s1>>s2;;
        string buffer=s.substr(a-1,b-a+1);
        s.erase(a-1,b-a+1);
        size_t i=s.find(s1+s2);
        i==string::npos ? s.insert(s.length(),buffer) : s.insert(i+s1.length(),buffer);
    }
    cout<<s<<endl;
    return 0;
}