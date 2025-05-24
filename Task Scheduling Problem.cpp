#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N,cnt=0;
    cin>>N;
    queue <int> q;
    vector <int> indegree(N+1);
    vector <vector<int>> adj(N+1);
    for (int i=1;i<=N;i++){
        cin>>indegree[i];
        for (int j=0;j<indegree[i];j++){
            int temp;
            cin>>temp;
            adj[temp].push_back(i);
        }
    }
    for (int i=1;i<=N;i++){
        if (!indegree[i]){
            cnt++;
            q.push(i);
        }
    }
    while (!q.empty()){
        int t=q.front();
        q.pop();
        for (int& i : adj[t]){
            if (!(--indegree[i])){
                cnt++;
                q.push(i);
            }
        }
    }
    cout<<!(N-cnt)<<endl;
    return 0;
}