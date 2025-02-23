#include <iostream>
#include <vector>
using namespace std;
int cmp(vector <int> &a,vector <int> &b,int m,int n)
{
    for (int i=0;i<min(m,n);i++){
        if (a[i]<b[i]){
            return -1;
        }
        if (a[i]>b[i]){
            return 1;
        }
    }
    if (m<n){
        return -1;
    }
    if (m>n){
        return 1;
    }
    if (m==n){
        return 0;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector <int> a(m),b(n);
    for (int i=0;i<m;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<cmp(a,b,m,n)<<endl;
    return 0;
}