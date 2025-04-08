#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    vector <int> a(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>i>>j;
    if (!a[i]){
        cout<<"ERROR: T["<<i<<"] is NULL";
        return 0;
    }
    if (!a[j]){
        cout<<"ERROR: T["<<j<<"] is NULL";
        return 0;
    }
    if (i==j){
        cout<<i<<" "<<a[i]<<endl;
        return 0;
    }
    int iLevel=log2(i);
    int jLevel=log2(j);
    while (iLevel>jLevel){
        i>>=1;
        iLevel--;
    }
    while (iLevel<jLevel){
        j>>=1;
        jLevel--;
    }
    while (i!=j){
        i>>=1;
        j>>=1;
    }
    cout<<i<<" "<<a[i]<<endl;
    return 0;
}