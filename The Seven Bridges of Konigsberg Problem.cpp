#include <iostream>
#include <vector>
using namespace std;
struct UnionFind
{
    vector <int> p;
    UnionFind(int n) : p(n+1)
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
    void Union(int x,int y)
    {
        int xp=Find(x);
        int yp=Find(y);
        p[yp]=xp;
    }
};
int main()
{
    int N,M;
    cin>>N>>M;
    vector <int> degree(N+1);
    UnionFind uf(N);
    while (M--){
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
        uf.Union(x,y);
    }
    int root=uf.Find(1);
    for (int i=1;i<=N;i++){
        if (degree[i]%2||!degree[i]||uf.Find(i)!=root){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;
}