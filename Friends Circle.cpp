#include <iostream>
#include <vector>
using namespace std;
struct DSU
{
    vector <int> p;
    DSU(int n) : p(n+1)
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
        int ra=find(a);
        int rb=find(b);
        p[rb]=ra;
    }
};
int main()
{
    int N,M,n,root,max=0;
    cin>>N>>M;
    DSU dsu(N+1);
    for (int i=0;i<M;i++){
        int first,t;
        cin>>n>>first;
        for (int j=1;j<n;j++){
            cin>>t;
            dsu.Union(first,t);
        }
    }
    vector <int> cnt(N+1,0);
    for (int i=1;i<=N;i++){
        root=dsu.find(i);
        cnt[root]++;
        if (cnt[root]>max){
            max=cnt[root];
        }
    }
    cout<<max<<endl;
    return 0;
}