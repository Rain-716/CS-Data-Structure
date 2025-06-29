#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int pre,m;
bool mid(int i)
{
    if (i>=m){
        return true;
    }
    if (!mid(2*i+1)){
        return false;
    }
    if (a[i]<=pre){
        return false;
    }
    pre=a[i];
    return mid(2*i+2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    while (n--){
        cin>>m;
        a.resize(m);
        for (int& i : a){
            cin>>i;
        }
        pre=-1;
        cout<<(mid(0) ? "Yes" : "No")<<'\n';
    }
    return 0;
}