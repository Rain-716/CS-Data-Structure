#include <iostream>
#include <vector>
using namespace std;
bool is=true;
void inTraversal(int root,vector <int>& a,vector <int>& l,vector <int>& r,vector <int>& In)
{
    if (root==a.size()||!is){
        return;
    }
    inTraversal(l[root],a,l,r,In);
    if (!In.empty()){
        if (In.back()>=a[root]){
            is=false;
            return;
        }
    }
    In.push_back(a[root]);
    inTraversal(r[root],a,l,r,In);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        vector <int> a(n+1),l(n+1),r(n+1),In;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        for (int i=1;i<=n;i++){
            cin>>l[i];
        }
        for (int i=1;i<=n;i++){
            cin>>r[i];
        }
        int root;
        cin>>root;
        inTraversal(root,a,l,r,In);
        cout<<(is ? "Yes" : "No")<<'\n';
        In.clear();
        is=true;
    }
    return 0;
}