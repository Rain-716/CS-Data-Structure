#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    const int INF=(1<<31)-1;
    vector <int> res(N+1),dis(N+1,INF),pathCnt(N+1,0),maxRes(N+1,0),pre(N+1,-1),path;
    vector <vector<pair<int,int>>> adj(N+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i=1;i<=N;i++){
        cin>>res[i];
    }
    while (M--){
        int u,v,l;
        cin>>u>>v>>l;
        adj[u].push_back({v,l});
        adj[v].push_back({u,l});
    }
    dis[S]=0;pathCnt[S]=1,maxRes[S]=res[S];
    pq.push({0,S});
    while (!pq.empty()){
        auto [l,u]=pq.top();
        pq.pop();
        if (l<=dis[u]){
            for (auto& [v,ll] : adj[u]){
                int plus=l+ll;
                if (plus<dis[v]){
                    dis[v]=plus;
                    pathCnt[v]=pathCnt[u];
                    maxRes[v]=res[v]+maxRes[u];
                    pre[v]=u;
                    pq.push({dis[v],v});
                }
                else if (plus==dis[v]){
                    pathCnt[v]+=pathCnt[u];
                    int Res=maxRes[u]+res[v];
                    if (Res>maxRes[v]){
                        maxRes[v]=Res;
                        pre[v]=u;
                    }
                }
            }
        }
    }
    cout<<pathCnt[D]<<" "<<maxRes[D]<<endl;
    for (int i=D;pre[i]!=-1;){
        i=pre[i];
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    for (int& i : path){
        cout<<i<<" ";
    }
    cout<<D<<endl;
    return 0;
}