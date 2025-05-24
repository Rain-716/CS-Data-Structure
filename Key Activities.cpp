#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge
{
    int u,v,t,id;
};
bool cmp(Edge& e1,Edge& e2)
{
    if (e1.u!=e2.u){
        return e1.u<e2.u;
    }
    return e1.id>e2.id;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector <Edge> e(M);
    vector <int> indegree(N+1,0);
    vector <vector<int>> adj(N+1),radj(N+1);
    queue <int> q;
    int idx=0;
    for (Edge& i : e){
        cin>>i.u>>i.v>>i.t;
        adj[i.u].push_back(idx);
        radj[i.v].push_back(idx);
        indegree[i.v]++;
        i.id=idx++;
    }
    for (int i=1;i<=N;i++){
        if (!indegree[i]){
            q.push(i);
        }
    }
    vector <int> arr;
    arr.reserve(N);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        arr.push_back(u);
        for (int& vi : adj[u]){
            if (!(--indegree[e[vi].v])){
                q.push(e[vi].v);
            }
        }
    }
    if (arr.size()!=N){
        cout<<0<<endl;
        return 0;
    }
    int T=0;
    vector <int> E(N+1,0);
    for (int& u : arr){
        for (int& vi : adj[u]){
            int v=e[vi].v;
            int t=e[vi].t;
            if (E[v]<E[u]+t){
                E[v]=E[u]+t;
                T=max(T,E[v]);
            }
        }
    }
    cout<<T<<endl;
    vector <int> L(N+1,T);
    for (int i=N-1;i>=0;i--){
        int v=arr[i];
        for (int& ui : radj[v]){
            int u=e[ui].u;
            int t=e[ui].t;
            L[u]=min(L[u],L[v]-t);
        }
    }
    vector <Edge> key;
    for (Edge& i : e){
        if (E[i.u]+i.t==L[i.v]){
            key.push_back(i);
        }
    }
    sort(key.begin(),key.end(),cmp);
    for (Edge& i : key){
        cout<<i.u<<"->"<<i.v<<endl;
    }
    return 0;
}