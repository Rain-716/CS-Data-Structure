#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int index;
    vector <node*> children;
};
static int leafNum=0;
void preTraversal(node* parent)
{

    cout<<parent->index<<" ";
    for (int i=0;i<parent->children.size();i++){
        preTraversal(parent->children[i]);
    }
}
void postTraversal(node* parent)
{
    for (int i=0;i<parent->children.size();i++){
        postTraversal(parent->children[i]);
    }
    cout<<parent->index<<" ";
}
void levelTraversal(node* parent)
{
    queue <node*> q;
    q.push(parent);
    while (!q.empty()){
        node* temp=q.front();
        cout<<temp->index<<" ";
        for (int i=0;i<temp->children.size();i++){
            q.push(temp->children[i]);
        }
        q.pop();
    }
    cout<<endl;
}
void printLeaf(node* parent)
{
    if (parent->children.empty()){
        leafNum++;
        cout<<parent->index<<" ";
        return;
    }
    for (int i=0;i<parent->children.size();i++){
        printLeaf(parent->children[i]);
    }
}
int Height(node* parent)
{
    if (parent->children.empty()){
        return 1;
    }
    int h=0;
    for (int i=0;i<parent->children.size();i++){
        h=max(Height(parent->children[i]),h);
    }
    return h+1;
}
int main()
{
    vector <node*> a(1000);
    int index,parent,size=0;
    while (cin>>index>>parent){
        a[index]=new node();
        a[index]->index=index;
        if (parent!=-1){
            a[parent]->children.push_back(a[index]);
        }
        size++;
    }
    cout<<1<<endl;
    node* root=a[1];
    preTraversal(root);
    cout<<endl;
    postTraversal(root);
    cout<<endl;
    levelTraversal(root);
    cout<<size<<endl;
    printLeaf(root);
    cout<<endl;
    cout<<leafNum<<endl;
    cout<<Height(root)<<endl;
    return 0;
}