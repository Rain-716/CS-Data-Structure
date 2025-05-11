#include <iostream>
#include <vector>
using namespace std;
int W,H;
vector <vector <bool>> a;
int dfsCount(int i,int j)
{
    if (i<0||i>=H||j<0||j>=W||!a[i][j]){
        return 0;
    }
    a[i][j]=0;
    return 1+dfsCount(i,j+1)+dfsCount(i,j-1)+dfsCount(i-1,j)+dfsCount(i+1,j);
}
int main()
{
    cin>>W>>H;
    a.assign(H,vector<bool>(W,0));
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            char c;
            cin>>c;
            if (c=='*'){
                a[i][j]=1;
            }
        }
    }
    int Max=0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (a[i][j]){
                Max=max(Max,dfsCount(i,j));
            }
        }
    }
    cout<<Max<<endl;
    return 0;
}