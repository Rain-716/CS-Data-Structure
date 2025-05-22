#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    const int INF=1<<31-1;
    int N,M,Min=INF,idx=0;
    cin>>N>>M;
    vector <vector<int>> dis(N+1,vector <int> (N+1,INF));
    while (M--){
        int u,v,l;
        cin>>u>>v>>l;
        if (l<dis[u][v]){
            dis[u][v]=dis[v][u]=l;
        }
    }
    for (int i=1;i<=N;i++){
        dis[i][i]=0;
    }
    for (int k=1;k<=N;k++){
        for (int i=1;i<=N;i++){
            if (dis[i][k]==INF){
                continue;
            }
            for (int j=1;j<=N;j++){
                if (dis[k][j]==INF){
                    continue;
                }
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for (int i=1;i<=N;i++){
        int Max=-1;
        for (int j=1;j<=N;j++){
            if (dis[i][j]==INF){
                Max=INF;
                break;
            }
            Max=max(Max,dis[i][j]);
        }
        if (Max<Min){
            Min=Max;
            idx=i;
        }
    }
    cout<<idx;
    if (idx){
        cout<<" "<<Min;
    }
    cout<<endl;
    return 0;
}