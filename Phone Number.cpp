#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct a
{
    int number=0;
    int times=0;
};
bool cmp(a a1,a a2)
{
    return a1.number<a2.number;
}
int main()
{
    int n;
    cin>>n;
    vector <a> vec;
    while(n--){
        int sum=0;
        string s;
        cin>>s;
        for (int i=0;i<s.length();i++){
            if (s[i]>='A'&&s[i]<='Z'){
                if (s[i]>='A'&&s[i]<='C'){
                    sum=sum*10+2;
                }
                if (s[i]>='D'&&s[i]<='F'){
                    sum=sum*10+3;
                }
                if (s[i]>='G'&&s[i]<='I'){
                    sum=sum*10+4;
                }
                if (s[i]>='J'&&s[i]<='L'){
                    sum=sum*10+5;
                }
                if (s[i]>='M'&&s[i]<='O'){
                    sum=sum*10+6;
                }
                if (s[i]>='P'&&s[i]<='S'){
                    sum=sum*10+7;
                }
                if (s[i]>='T'&&s[i]<='V'){
                    sum=sum*10+8;
                }
                if (s[i]>='W'&&s[i]<='Z'){
                    sum=sum*10+9;
                }
            }
            if (s[i]>='0'&&s[i]<='9'){
                sum=sum*10+(s[i]-'0');
            }
        }
        bool b=0;
        for (int i=0;i<vec.size();i++){
            if (sum==vec[i].number){
                vec[i].times++;
                b=1;
                break;
            }
        }
        if (!b){
            a temp;
            temp.number=sum;
            temp.times=1;
            vec.push_back(temp);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for (int i=0;i<vec.size();i++){
        cout<<setw(4)<<setfill('0')<<(vec[i].number/10000)<<'-'<<setw(4)<<setfill('0')<<(vec[i].number%10000)<<" "<<vec[i].times<<endl;
    }
    return 0;
}
