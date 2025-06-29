#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int N,M,i;
    cin>>N>>M;
    if (N<=M){
        vector <int> res(N);
        for (int& i : res){
            cin>>i;
        }
        sort(res.begin(),res.end(),greater<int>());
        for (int& i : res){
            cout<<i<<' ';
        }
        cout<<'\n';
        return 0;
    }
    priority_queue <int,vector<int>,greater<int>> pq;
    int NN=N-M,MM=M;
    while (MM--){
        cin>>i;
        pq.push(i);
    }
    while (NN--){
        cin>>i;
        if (i>pq.top()){
            pq.pop();
            pq.push(i);
        }
    }
    vector <int> res(M);
    for (int& i : res){
        i=pq.top();
        pq.pop();
    }
    for (auto it=res.rbegin();it!=res.rend();it++){
        cout<<*it<<' ';
    }
    cout<<'\n';
    return 0;
}