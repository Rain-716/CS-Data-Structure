#include <iostream>
#include <vector>
using namespace std;
struct tri
{
    int r,c,v;
};
inline int cmp(const tri &t1,const tri &t2)
{
    if (t1.r!=t2.r){
        return t1.r-t2.r;
    }
    else {
        return t1.c-t2.c;}
}
int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1,n2,m1,m2,N1,N2;
    cin>>n1>>m1>>N1;
    vector <tri> A(N1);
    for (int i=0;i<N1;i++){
        cin>>A[i].r>>A[i].c>>A[i].v;
    }
    cin>>n2>>m2>>N2;
    vector <tri> B(N2);
    for (int i=0;i<N2;i++){
        cin>>B[i].r>>B[i].c>>B[i].v;
    }
    int i=0,j=0;
    vector <tri> C;
    while (i<N1&&j<N2){
        int c=cmp(A[i],B[j]);
        if (c<0){
            C.push_back(A[i++]);
        }
        else if (c>0){
            C.push_back(B[j++]);
        }
        else {
            C.push_back({A[i].r,A[i].c,A[i++].v+B[j++].v});
        }
    }
    while (i<N1){
        C.push_back(A[i++]);
    }
    while (j<N2){
        C.push_back(B[j++]);
    }
    for (int i=0;i<C.size();i++){
        cout<<C[i].r<<" "<<C[i].c<<" "<<C[i].v<<'\n';
    }
    return 0;
}