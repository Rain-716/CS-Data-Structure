#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct node
{
    int val;
    node *l,*r;
    node (int v) : val(v),l(nullptr),r(nullptr) {}
};
node* buildTree(vector <int>& pre,int preL,int preR,unordered_map <int,int>& in,int inL,int inR)
{
    if (preL>preR||inL>inR){
        return nullptr;
    }
    int rootVal=pre[preL];
    node* root=new node(rootVal);
    int i=in[rootVal];
    root->l=buildTree(pre,preL+1,preL+i-inL,in,inL,i-1);
    root->r=buildTree(pre,preL+i-inL+1,preR,in,i+1,inR);
    return root;
}
void levelTraversalb(node* parent)
{
    queue <node*> q;
    q.push(parent);
    while (!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if (temp->l){
            q.push(temp->l);
        }
        if (temp->r){
            q.push(temp->r);
        }
    }
    cout<<'\n';
}
void levelTraversalm(node* parent)
{
    queue <node*> q;
    q.push(parent);
    while (!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if (temp->l){
            q.push(temp->l);
            temp=temp->l;
            while (temp->r){
                q.push(temp->r);
                temp=temp->r;
            }
        }
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    vector <int> pre(n);
    unordered_map <int,int> in(n);
    for (int i=0;i<n;i++){
        cin>>pre[i];
    }
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        in[t]=i;
    }
    node* root=buildTree(pre,0,n-1,in,0,n-1);
    cout<<root->val<<'\n';
    levelTraversalb(root);
    levelTraversalm(root);
    return 0;
}