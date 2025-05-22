#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,w;
};
struct UnionFind
{
    vector <int> p;
    UnionFind (int n) : p(n+1)
    {
        for (int i=1;i<=n;i++){
            p[i]=i;
        }
    }
    int Find(int x)
    {
        if (x!=p[x]){
            p[x]=Find(p[x]);
        }
        return p[x];
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
    int N,M,cnt=0,cost=0;
    cin>>N>>M;
    UnionFind uf(N);
    vector <edge> e(M);
    for (auto& i : e){
        cin>>i.x>>i.y>>i.w;
    }
    sort(e.begin(),e.end(),cmp);
    for (auto i : e){
        if (uf.Union(i.x,i.y)){
            cnt++;
            cost+=i.w;
            if (cnt==N-1){
                break;
            }
        }
    }
    cout<<(cnt==(N-1) ? cost : -1)<<endl;
    return 0;
}