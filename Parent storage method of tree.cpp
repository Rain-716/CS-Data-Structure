#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int index;
    vector <node*> children;
};
void postTraversal(node* parent)
{
    if (parent){
        for (int i=0;i<parent->children.size();i++){
            postTraversal(parent->children[i]);
        }
        cout<<parent->index<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector <node*> a(n);
    for (int i=0;i<n;i++){
        a[i]=new node();
        a[i]->index=i;
    }
    for (int i=0;i<n;i++){
        int parent;
        cin>>parent;
        if (parent!=-1){
            a[parent]->children.push_back(a[i]);
        }
    }
    postTraversal(a[0]);
    return 0;
}