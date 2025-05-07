#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n,K;
    cin>>n>>K;
    priority_queue <long long,vector<long long>,greater<long long>> freq;
    for (int i=0;i<n;i++){
        int temp;
        cin>>temp;
        freq.push(temp);
    }
    if (n==1){
        cout<<freq.top();
        return 0;
    }
    while ((n-1)%(K-1)){
        freq.push(0);
        n++;
    }
    long long res=0;
    while (freq.size()>1){
        long long sum=0;
        for (int i=0;i<K;i++){
            sum+=freq.top();
            freq.pop();
        }
        freq.push(sum);
        res+=sum;
    }
    cout<<res<<endl;
    return 0;
}