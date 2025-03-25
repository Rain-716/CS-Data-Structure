#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maxLength (string& s)
{
    vector <int> next(s.length()+1);
    next[0]=-1;next[1]=0;
    for (int i=2;i<=s.length();i++){
        int k=next[i-1];
        while (k>=0&&s[i-1]!=s[k]){
            k=next[k];
        }
        next[i]=k+1;
    }
    for (int i=1;i<=s.length();i++){
        if (s[i]==s[next[i]]){
            next[i]=next[next[i]];
        }
    }
    return next.back();
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n==1){
        cout<<s<<endl;
        return 0;
    }
    for (int i=1;i<n;i++){
        string t;
        cin>>t;
        int minL=min(s.length(),t.length());
        string ts=t.substr(0,minL)+" "+s.substr(s.length()-minL,minL);
        s+=t.substr(maxLength(ts));
    }
    cout<<s<<endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maxLength (string& s)
{
    vector <int> next(s.length()+1);
    next[0]=-1;next[1]=0;
    for (int i=2;i<=s.length();i++){
        int k=next[i-1];
        while (k>=0&&s[i-1]!=s[k]){
            k=next[k];
        }
        next[i]=k+1;
    }
    return next.back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n==1){
        cout<<s<<'\n';
        return 0;
    }
    for (int i=1;i<n;i++){
        string t;
        cin>>t;
        int minL=min(s.length(),t.length());
        string ts=t.substr(0,minL)+" "+s.substr(s.length()-minL,minL);
        s+=t.substr(maxLength(ts));
    }
    cout<<s<<'\n';
    return 0;
}