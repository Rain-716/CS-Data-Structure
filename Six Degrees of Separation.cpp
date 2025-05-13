#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    vector <vector<int>> adj(N+1);
    while (M--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1;i<=N;i++){
        vector <int> cnt(N+1,-1);
        queue <int> q;
        int count=1;
        cnt[i]++;
        q.push(i);
        while (!q.empty()){
            int s=q.front();
            q.pop();
            if (cnt[s]==6){
                continue;
            }
            for (int j : adj[s]){
                if (cnt[j]==-1){
                    count++;
                    cnt[j]=cnt[s]+1;
                    q.push(j);
                }
            }
        }
        cout<<i<<": "<<fixed<<setprecision(2)<<count*100.0/N<<"%"<<endl;
    }
    return 0;
}