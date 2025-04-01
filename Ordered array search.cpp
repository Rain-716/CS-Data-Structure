#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,Q;
    cin>>N>>Q;
    vector <int> a(N);
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    while (Q--){
        int t,res=-1,l=0,r=N,m;
        cin>>t;
        while (l<r){
            m=l+(r-l)/2;
            if (a[m]==t){
                res=m;
                break;
            }
            else if (a[m]<t){
                l=m+1;
            }
            else {
                r=m;
            }
        }
        while (res>0&&a[res]==a[res-1]){
            res--;
        }
        cout<<res<<'\n';
    }
    return 0;
}