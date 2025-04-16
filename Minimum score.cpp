#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    long long score=0;
    priority_queue <long long,vector<long long>,greater<long long>> pq;
    int n,t;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        pq.push(t);
    }
    while (pq.size()>1){
        long long t1=pq.top();
        pq.pop();
        long long t2=pq.top();
        pq.pop();
        long long sum=t1+t2;
        pq.push(sum);
        score+=(sum);
    }
    score+=pq.top();
    cout<<score<<endl;
    return 0;
}