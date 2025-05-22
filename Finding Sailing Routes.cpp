#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int u,v,w;
    bool in=false;
};
struct UnionFind
{
    int cnt;
    vector <int> p;
    UnionFind (int n) : p(n+1),cnt(n)
    {
        for (int i=1;i<=n;i++){
            p[i]=i;
        }
    }
    int Find (int x)
    {
        return x==p[x] ? x : p[x]=Find(p[x]);
    }
    bool Union (int x,int y)
    {
        x=Find(x);
        y=Find(y);
        if (x==y){
            return false;
        }
        p[y]=x;
        cnt--;
        return true;
    }
};
bool cmp(edge& e1,edge& e2)
{
    return e1.w<e2.w;
}
bool dfs(int u,int v,int& Max,vector <bool>& vis,vector <vector<pair<int,int>>>& adj)
{
    if (u==v){
        return true;
    }
    vis[u]=true;
    for (auto [t,w] : adj[u]){
        if (!vis[t]){
            if (dfs(t,v,Max,vis,adj)){
                Max=max(Max,w);
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m,cnt=0,weight=0;
    cin>>n>>m;
    UnionFind uf (n);
    vector <edge> e(m);
    vector <vector<pair<int,int>>> adj(n+1);
    for (edge& i : e){
        cin>>i.u>>i.v>>i.w;
    }
    sort (e.begin(),e.end(),cmp);
    for (edge& i : e){
        if (uf.Union(i.u,i.v)){
            i.in=true;
            cnt++;
            weight+=i.w;
            adj[i.u].push_back({i.v,i.w});
            adj[i.v].push_back({i.u,i.w});
            if (cnt==n-1){
                break;
            }
        }
    }
    if (cnt!=n-1){
        cout<<"NO MST"<<endl<<uf.cnt<<endl;
        return 0;
    }
    int Min=(1<<31)-1;
    bool eq=false;
    for (edge i : e){
        if (!i.in){
            int Max=-1;
            vector <bool> vis(n+1,false);
            dfs(i.u,i.v,Max,vis,adj);
            if (Max==i.w){
                eq=true;
                break;
            }
            Min=min(Min,i.w-Max);
        }
    }
    if (eq){
        cout<<"YES"<<endl<<weight<<endl;
    }
    else {
        cout<<"NO"<<endl<<weight<<" "<<(Min==(1<<31)-1 ? -1 : weight+Min)<<endl;
    }
    return 0;
}