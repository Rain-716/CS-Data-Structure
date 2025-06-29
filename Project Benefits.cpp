#include <bits/stdc++.h>
using namespace std;
using pll=pair<long long,long long>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,k;
    long long W;
    cin>>n>>W>>k;
    vector <pll> project(n);
    for (auto& i : project){
        cin>>i.first>>i.second;
    }
    sort(project.begin(),project.end());
    int i=0;
    priority_queue <long long> v;
    while (k--){
        while (i<n&&project[i].first<=W){
            v.push(project[i++].second);
        }
        if (v.empty()){
            break;
        }
        W+=v.top();
        v.pop();
    }
    cout<<W<<'\n';
    return 0;
}