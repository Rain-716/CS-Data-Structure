#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int v);
};
class LinkedList
{
    public:
        Node* head;
        LinkedList();
        LinkedList(const LinkedList&);
        ~LinkedList();
        void buildList(int,const vector<int>&,const vector<int>&);
};
Node::Node(int v) : val(v),next(nullptr),random(nullptr) {}
LinkedList::LinkedList() : head(nullptr) {}
LinkedList::~LinkedList()
{
    Node* cur=head;
    while (cur){
        Node* nxt=cur->next;
        delete cur;
        cur=nxt;
    }
}
// 根据输入数据构建链表；randomIndex中-1表示空指针
void LinkedList::buildList(int n,const vector<int>& vals,const vector<int>& randomIndex)
{
    if (n==0){
        return;
    }
    vector<Node*> nodes(n,nullptr);
    for (int i=0;i<n;i++){
        nodes[i]=new Node(vals[i]);
        if (i>0){
            nodes[i-1]->next=nodes[i];
        }
    }
    head=nodes[0];
    for (int i=0;i<n;i++){
        if (randomIndex[i]!=-1){
            nodes[i]->random=nodes[randomIndex[i]];
        }
    }
}
LinkedList::LinkedList(const LinkedList& other)
{
    unordered_map <Node*,Node*> nodemap;
    this->head=new Node{other.head->val};
    Node *curold=other.head,*curnew=head;
    nodemap[curold]=curnew;
    while (curold->next){
        Node* temp=new Node{curold->next->val};
        curnew->next=temp;
        curold=curold->next;
        curnew=curnew->next;
        nodemap[curold]=curnew;
    }
    curold=other.head,curnew=head;
    while(curold){
        if (!curold->random){
            curnew->random=nullptr;
        }
        else {
            curnew->random=nodemap[curold->random];
        }
        curold=curold->next;
        curnew=curnew->next;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> vals(n),randomIndex(n);
    for (int i=0;i<n;i++){
        cin>>vals[i];
    }
    for (int i=0;i<n;i++){
        cin>>randomIndex[i];
    }
    LinkedList list;
    list.buildList(n, vals, randomIndex);
    // 使用复制构造函数生成深拷贝链表
    LinkedList copyList(list);
    // 遍历复制链表，将结点存入 vector，并利用 unordered_map
    // 构造结点到下标的映射
    vector<Node*> nodes;
    unordered_map<Node*,int> indexMap;
    Node* cur=copyList.head;
    int idx=0;
    while (cur){
        nodes.push_back(cur);
        indexMap[cur]=idx++;
        cur=cur->next;
    }
    // 输出每个结点的值以及 random
    // 指针在复制链表中的下标（若为空则输出 -1）
    for (int i=0;i<(int)nodes.size();i++){
        int randIdx=-1;
        if (nodes[i]->random){
            randIdx=indexMap[nodes[i]->random];
        }
        cout<<nodes[i]->val<<" "<<randIdx<<"\n";
    }
    return 0;
}