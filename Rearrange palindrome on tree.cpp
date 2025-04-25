#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        vector <char> a(n+1);
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int q;
        cin>>q;
        vector <int> Alphabet(26,0);
        while (q>0){
            Alphabet[a[q]-'a']++;
            q/=2;
        }
        bool eOdd=false,res=true;
        for (int i=0;i<26;i++){
            if (Alphabet[i]%2){
                if (!eOdd){
                    eOdd=true;
                }
                else{
                    res=false;
                    break;
                }
            }
        }
        cout<<(res ? "Yes" : "No")<<endl;
    }
    return 0;
}