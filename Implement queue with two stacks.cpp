#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> s1,s2;
    int N;
    cin>>N;
    while (N--){
        int x;
        string s;
        cin>>s;
        if (s!="pop"){
            cin>>x;
        }
        if (s=="push"){
            s1.push(x);
        }
        else if (s=="pop"){
            if (s2.empty()){
                while (!s1.empty()){
                    int temp=s1.top();
                    s1.pop();
                    s2.push(temp);
                }
            }
            s2.pop();
        }
        else {
            if (x==1){
                if (s2.empty()){
                    while (!s1.empty()){
                        int temp=s1.top();
                        s1.pop();
                        s2.push(temp);
                    }
                }
                cout<<s2.top()<<endl;
            }
            else {
                if (s1.size()<s2.size()){
                    cout<<s1.size()<<" "<<s2.size()<<endl;
                }
                else {
                    cout<<s2.size()<<" "<<s1.size()<<endl;
                }
            } 
        }
    }
    return 0;
}