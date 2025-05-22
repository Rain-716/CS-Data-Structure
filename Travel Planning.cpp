#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int v,len,cost;
};
struct cmp
{
    bool operator() (edge& e1,edge& e2)
    {
        if (e1.len!=e2.len){
            return e1.len>e2.len;
        }
        return e1.cost>e2.cost;
    }
};
int main()
{
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    const int INF=(1<<31)-1;
    vector <vector<edge>> adj(N);
    priority_queue <edge,vector<edge>,cmp> pq;
    vector <int> dis(N,INF),cost(N,INF);
    dis[S]=0;cost[S]=0;
    while (M--){
        int u,v,l,c;
        cin>>u>>v>>l>>c;
        adj[u].push_back({v,l,c});
        adj[v].push_back({u,l,c});
    }
    pq.push({S,0,0});
    while (!pq.empty()){
        auto [u,l,c]=pq.top();
        pq.pop();
        if (u==D){
            break;
        }
        if (l<dis[u]||(l==dis[u]&&c<=cost[u])){
            for (auto [v,l1,c1] : adj[u]){
                int plusl=dis[u]+l1;
                int plusc=cost[u]+c1;
                if (plusl<dis[v]||(plusl==dis[v]&&plusc<cost[v])){
                    dis[v]=plusl;
                    cost[v]=plusc;
                    pq.push({v,dis[v],cost[v]});
                }
            }
        }
    }
    cout<<dis[D]<<" "<<cost[D]<<endl;
    return 0;
}