#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int B=31;
int n;
vector <unsigned long long> hs,hr,pow;
unsigned long long getHash(vector <unsigned long long>& h,int l,int r)
{
    return h[r]-h[l-1]*pow[r-l+1];
}
bool check(int L)
{
    if (!L){
        return true;
    }
    unordered_map <unsigned long long,int> pos(n-L+1);
    for (int i=1;i+L-1<=n;i++){
        unsigned long long hash=getHash(hs,i,i+L-1);
        auto it=pos.find(hash);
        if (it==pos.end()||pos[hash]>i+L-1){
            pos[hash]=i+L-1;
        }
    }
    for (int i=1;i+L-1<=n;i++){
        unsigned long long rHash=getHash(hr,i,i+L-1);
        auto it=pos.find(rHash);
        if (it!=pos.end()){
            int rLeft=n-i-L+2;
            if (pos[rHash]<rLeft){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());
    n=s.size();
    hs.assign(n+1,0);
    hr.assign(n+1,0);
    pow.assign(n+1,1);
    for (int i=1;i<=n;i++){
        hs[i]=hs[i-1]*B+s[i-1]-'a';
        hr[i]=hr[i-1]*B+r[i-1]-'a';
        pow[i]=pow[i-1]*B;
    }
    int low=0,high=n/2+1,mid=0,res=0;
    while (low<high){
        mid=(low+high)>>1;
        if (check(mid)){
            res=mid;
            low=mid+1;
        }
        else {
            high=mid;
        }
    }
    cout<<res<<endl;
    return 0;
}