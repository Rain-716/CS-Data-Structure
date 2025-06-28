#include <bits/stdc++.h>
using namespace std;
int minNo=(1<<31)-1;
vector <int> l,r;
int Height(int i)
{
    if (!i){
        return 0;
    }
    int lh=Height(l[i]);
    int rh=Height(r[i]);
    if (abs(lh-rh)>1){
        minNo=min(minNo,i);
    }
    return max(lh,rh)+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    l.assign(n+1,0);
    r.assign(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    int h=Height(1);
    if (minNo==(1<<31)-1){
        cout<<"Yes"<<'\n'<<h<<'\n';
        return 0;
    }
    cout<<"No"<<'\n'<<minNo<<'\n';
    return 0;
}