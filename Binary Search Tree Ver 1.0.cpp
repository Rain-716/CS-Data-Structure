#include <iostream>
#include <vector>
using namespace std;
int n;
vector <int> a,l,r;
bool check(int rootIndex,int left,int right)
{
    if (rootIndex==n+1){
        return true;
    }
    if (!(left<a[rootIndex]&&a[rootIndex]<right)){
        return false;
    }
    return check(l[rootIndex],left,a[rootIndex])&&check(r[rootIndex],a[rootIndex],right);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        a.resize(n+1);
        l.resize(n+1);
        r.resize(n+1);
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            cin>>l[i];
        }
        for (int i=1;i<=n;i++){
            cin>>r[i];
        }
        int r;
        cin>>r;
        cout<<(check(r,0,1e9+1) ? "Yes" : "No")<<'\n';
    }
    return 0;
}