#include <iostream>
#include <vector>
using namespace std;
// 定义链表结点
struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node(int _val) : val(_val),prev(nullptr),next(nullptr) {}
};
int cacheCapacity;      // 缓存容量
Node* head=nullptr;     // 链表头，最近使用
Node* tail=nullptr;     // 链表尾，最久未使用
int cacheSize=0;        // 当前缓存中节点数量
// 桶，用于记录每个数字在缓存中的节点指针，初始时均为 nullptr
vector<Node*> bucket(100001,nullptr);
bool request(int x)
{
    if (bucket[x]){
        Node* n=bucket[x];
        if (n!=head){
            if (n==tail){
                tail=n->prev;
                tail->next=nullptr;
            }
            else {
                n->prev->next=n->next;
                n->next->prev=n->prev;
            }
            n->next=head;
            head->prev=n;
            head=head->prev;
            head->prev=nullptr;
        }
        return 1;
    }
    else {
        Node* n=new Node{x};
        bucket[x]=n;
        if (head){
            n->next=head;
            head->prev=n;
            head=head->prev;
            if (cacheSize==cacheCapacity){
                Node* temp=tail;
                tail=tail->prev;
                tail->next=nullptr;
                bucket[temp->val]=nullptr;
                delete temp;
                return 0;
            }
        }
        else {
            head=n;
            tail=n;
        }
        cacheSize++;
        return 0;
    }
}
int main()
{
    int n;
    cin>>n>>cacheCapacity;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        bool hit=request(x);
        cout<<(hit ? "hit" : "miss")<<endl;
    }
    return 0;
}