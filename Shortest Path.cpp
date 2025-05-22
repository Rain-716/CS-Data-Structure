#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n,m,S;
    cin>>n>>m>>S;
    vector <vector<pair<int,int>>> adj(n+1);
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector <int> dis(n+1,(1<<31)-1);
    vector <long long> cnt(n+1,0);
    dis[S]=0;cnt[S]=1;
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    pq.push({0,S});
    while (!pq.empty()){
        auto [w,v]=pq.top();
        pq.pop();
        if (w>dis[v]){
            continue;
        }
        for (auto [v1,w1] : adj[v]){
            int vPw1=dis[v]+w1;
            if (vPw1<dis[v1]){
                dis[v1]=vPw1;
                cnt[v1]=cnt[v];
                pq.push({vPw1,v1});
            }
            else if (vPw1==dis[v1]){
                cnt[v1]+=cnt[v];
            }
        }
    }
    for (int i=1;i<S;i++){
        cout<<dis[i]<<" "<<cnt[i]<<endl;
    }
    for (int i=S+1;i<=n;i++){
        cout<<dis[i]<<" "<<cnt[i]<<endl;
    }
    return 0;
}