#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    bool b=1;
    stack <char> cha;
    stack <bool> str;
    string line;
    while (getline(cin,line)&&b){
        for (int i=0;i<line.length()&&b;i++){
            if (line[i]=='('||line[i]=='['||line[i]=='{'){
                cha.push(line[i]);
            }
            else if ((line[i]==')'&&cha.top()!='(')||(line[i]==']'&&cha.top()!='[')||(line[i]=='}'&&cha.top()!='{')){
                cout<<"NO"<<endl;
                return 0;
            }
            else if((line[i]==')'&&cha.top()=='(')||(line[i]==']'&&cha.top()=='[')||(line[i]=='}'&&cha.top()=='{')){
                cha.pop();
            }
        }
        for (int i=0;i<line.length()-1&&b;i++){
            if (line[i]=='/'&&line[i+1]=='*'){
                str.push(0);
                i++;
            }
            else if (line[i]=='*'&&line[i+1]=='/'){
                if (str.top()){
                    cout<<"NO"<<endl;
                    return 0;
                }
                else {
                    str.pop();
                    i++;
                }
            }
        }
    }
    if (cha.empty()&&str.empty()){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}