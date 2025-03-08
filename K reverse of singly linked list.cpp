#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node() {}
    node(int v):val(v),next(NULL) {}
};
class LinkedList {
private:
    node* head;//头指针，指向不存数据的表头结点
public:
    LinkedList();// 默认构造函数
    LinkedList(const LinkedList& other);// 拷贝构造函数
    LinkedList& operator=(const LinkedList& other); // 赋值运算符重载
    ~LinkedList();// 析构函数
    void insert(int v);// 插入函数
    void print();// 打印链表
    void clear();// 清除链表
    void K_Reverse(int k);// K 反转函数
};
LinkedList::LinkedList() {
    head=new node(-1);// 表头结点的值可以任意，因为它不存储实际数据
    head->next=NULL;
}
LinkedList::LinkedList(const LinkedList& other) {
    head=new node(-1); 
    node* current=head;
    node* other_current=other.head->next; 
    while (other_current!=NULL) {
        current->next=new node(other_current->val);
        current=current->next;
        other_current=other_current->next;
    }
}
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this==&other) {
        return *this; 
    }
    clear();
    head=new node(-1);
    node* current=head;
    node* other_current=other.head->next;
    while (other_current!=NULL) {
        current->next=new node(other_current->val);
        current=current->next;
        other_current=other_current->next;
    }
    return *this;
}
void LinkedList::clear() {
    node* current=head;
    while (current!=NULL) {
        node* temp=current;
        current=current->next;
        delete temp;
    }
    head=NULL;
}
LinkedList::~LinkedList() {
    clear();
}
void LinkedList::print() {
    node* now=head;
    now=now->next;
    while (now!=NULL) {
        cout<<now->val<<" ";
        now=now->next;
    }
    cout<<endl;
}
void LinkedList::insert(int v) {
    node* temp=new node(v);
    node* temp1=head;
    while (temp1->next!=NULL) {
        temp1=temp1->next;
    }
    temp1->next=temp;
}
void LinkedList::K_Reverse(int k)
{
    int cnt=0,num=0;
    node* n=head;
    while (n->next){
        n=n->next;
        num++;
    }
    if (num<k||k==1){
        return;
    }
    node *p=head,*q=p->next,*r=q->next,*s=head->next,*fhead=head;
    while (cnt<num/k*k){
        if (q==s){
            p->next=nullptr;
        }
        q->next=p;
        p=q;
        q=r;
        if (!(r->next)){
            r->next=new node(-1);
        }
        r=r->next;
        cnt++;
        if (!(cnt%k)){
            fhead->next=p;
            p=s;
            fhead=s;
            s=q;
        }
    }
    if (num%k){
        p->next=q;
    }
    else {
        p->next=nullptr;
    }
    node* u=head;
    for (int i=0;i<num;i++){
        u=u->next;
    }
    u->next=nullptr;
}
int main() 
{
    LinkedList l;
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        l.insert(x);
    }
    l.K_Reverse(k);
    l.print();
    return 0;
}