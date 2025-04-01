#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    vector <string> a;
    cin>>T;
    while (T--){
        char op;
        string s;
        cin>>op>>s;
        if (op=='A'){
            a.push_back(s);
        }
        else {
            auto t=find(a.begin(),a.end(),s);
            reverse(t,a.end());
            a.pop_back();
        }
        if (a.empty()){
            cout<<"EMPTY"<<endl;
            continue;
        }
        for (auto i : a){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}