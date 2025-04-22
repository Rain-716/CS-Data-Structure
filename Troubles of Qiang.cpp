#include <iostream>
#include <vector>
using namespace std;
struct DSU
{
    vector <int> p,e;
    DSU(int n) : p(n+1),e(n+1,-1)
    {
        for (int i=1;i<=n;i++){
            p[i]=i;
        }
    }
    int find(int x)
    {
        if (p[x]!=x){
            p[x]=find(p[x]);
        }
        return p[x];
    }
    void Union(int a,int b)
    {
        p[b]=a;
        if (e[b]!=-1){
            e[e[b]]=a;
        }
    }
};
int main()
{
    int T;
    cin>>T;
    while (T--){
        int n,m;
        cin>>n>>m;
        DSU dsu(n);
        while (m--){
            char c;
            int a,b;
            cin>>c>>a>>b;
            int rootA=dsu.find(a);
            int rootB=dsu.find(b);
            if (c=='A'){
                int eA=dsu.e[rootA];
                int eB=dsu.e[rootB];
                if (eA==-1&&eB==-1){
                    dsu.e[rootA]=rootB;
                    dsu.e[rootB]=rootA;
                }
                if (eA!=-1){
                    dsu.Union(dsu.e[rootA],rootB);
                }
                if (eB!=-1){
                    dsu.Union(dsu.e[rootB],rootA);
                }
            }
            else if (c=='Q'){
                if (rootA==rootB){
                    cout<<"In the same gang."<<endl;
                }
                else if (rootB==dsu.e[rootA]&&rootA==dsu.e[rootB]){
                    cout<<"In different gangs."<<endl;
                }
                else {
                    cout<<"Not sure yet."<<endl;
                }
            }
        }
    }
    return 0;
}