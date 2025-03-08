#include <iostream>
#include <string>
using namespace std;
int main()
{
    int big=1e9+1,small=-1e9-1,mid=0;
    while (1){
        mid=small+(big-small)/2;
        cout<<mid<<endl;
        string s;
        cin>>s;
        if (s=="big"){
            big=mid+1;
        }
        else if (s=="small"){
            small=mid-1;
        }
        else if (s=="equal"){
            break;
        }
    }
    return 0;
}