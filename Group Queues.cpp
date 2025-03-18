#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    struct person
    {
        int group,index;
        bool b=0;
    };
    int n,q,maxgroup=1;
    cin>>n;
    queue <int> order;
    vector <person> p(n+1);
    for (int i=1;i<=n;i++){
        p[i].index=i; 
        cin>>p[i].group;
        maxgroup=max(p[i].group,maxgroup);
    }
    vector <queue <person>> queues(maxgroup+1);
    cin>>q;
    while (q--){
        string s;
        cin>>s;
        if (s=="ENQUEUE"){
            int x;
            cin>>x;
            if (p[x].b){
                continue;
            }
            int group=p[x].group;
            if (queues[group].empty()){
                order.push(group);
            }
            queues[group].push(p[x]);
            p[x].b=1;
        }
        else {
            if (order.empty()){
                cout<<-1<<endl;
                continue;
            }
            int first_group=order.front();
            int first_person=queues[first_group].front().index;
            p[first_person].b=0;
            cout<<first_person<<endl;
            queues[first_group].pop();
            if (queues[first_group].empty()){
                order.pop();
            }
        }
    }
    return 0;
}