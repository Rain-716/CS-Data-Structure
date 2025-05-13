#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt=0;
vector <vector<int>> adj;
vector <bool> b;
void dfs(int s)
{
    b[s]=true;
    cnt++;
    cout<<s<<" ";
    for (int i : adj[s]){
        if (!b[i]){
            dfs(i);
            cout<<s<<" ";
        }
    }
}
int main()
{
    int N,M,S;
    cin>>N>>M>>S;
    adj.assign(N+1,{});
    b.assign(N+1,false);
    while (M--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1;i<=N;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(S);
    if (cnt<N){
        cout<<0;
    }
    return 0;
}