#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int f,t,w;
};
struct UnionFind
{
    vector <int> p;
    UnionFind (int n) : p(n+1)
    {
        for (int i=0;i<=n;i++){
            p[i]=i;
        }
    }
    int Find(int x)
    {
        return x==p[x] ? x : p[x]=Find(p[x]);
    }
    bool Union(int x,int y)
    {
        x=Find(x);
        y=Find(y);
        if (x==y){
            return false;
        }
        p[y]=x;
        return true;
    }
};
bool cmp(edge e1,edge e2)
{
    return e1.w<e2.w;
}
int main()
{
    int n,m,c,cost=0,cnt=0;
    cin>>n>>m>>c;
    UnionFind uf(n);
    vector <edge> e(m+n);
    for (int i=1;i<=n;i++){
        e[i+m-1].f=0;
        e[i+m-1].t=i;
        cin>>e[i+m-1].w;
    }
    for (int i=0;i<m;i++){
        cin>>e[i].f>>e[i].t>>e[i].w;
        e[i].w*=c;
    }
    sort(e.begin(),e.end(),cmp);
    for (auto i : e){
        if (uf.Union(i.f,i.t)){
            cost+=i.w;
            cnt++;
            if (cnt==n){
                break;
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}