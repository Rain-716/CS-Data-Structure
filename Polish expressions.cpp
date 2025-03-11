#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    stack<double> num;
    string line,temp;
    getline(cin,line);
    istringstream sin(line);
    vector <string> s;
    while (sin>>temp){
        s.push_back(temp);
    }
    reverse(s.begin(),s.end());
    for (int i=0;i<s.size();i++){
        if (s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/"){
            double num1=num.top();
            num.pop();
            double num2=num.top();
            num.pop();
            double res;
            if (s[i]=="+"){
                res=num1+num2;
            }
            else if (s[i]=="-"){
                res=num1-num2;
            }
            else if (s[i]=="*"){
                res=num1*num2;
            }
            else if (s[i]=="/"){
                res=num1/num2;
            }
            num.push(res);
        }
        else {
            num.push(stod(s[i]));
        }
    }
    cout<<fixed<<setprecision(6)<<num.top()<<endl;
    return 0;
}