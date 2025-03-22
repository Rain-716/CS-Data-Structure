#include <iostream>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int next [t.length()];
    next[0]=-1;next[1]=0;
    for (int i=2;i<t.length();i++){
        int k=next[i-1];
        while (k>=0&&t[i-1]!=t[k]){
            k=next[k];
        }
        next[i]=k+1;
    }
    int i=0,j=0;
    while (i<s.length()&&j<t.length()){
        if (s[i]==t[j]){
            i++;j++;
        }
        else {
            if (next[j]<0){
                i++;j=0;
            }
            else {
                j=next[j];
            }
        }
    }
    if (j==t.length()){
        cout<<i-t.length()<<endl;
    }
    else {
        cout<<-1<<endl;
    }
    return 0;
}