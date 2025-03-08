#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
#define NIL nullptr
typedef int ElemType;
typedef struct ListNode *Position;  // 指针即结点位置
struct ListNode {
    ElemType data_;   // 存储数据
    Position next_;  // 线性表中下一个元素的位置
};
class LinkedList {
    private:
        Position head_;  // 单链表头指针,指向空头结点
        int length_;    // 表长
    public:
        struct ListException   // 异常处理
        {
            std::string error_;
            ListException(std::string s):error_(s) {};
        };
        LinkedList();  // 构造函数，初始化一个空的线性表
        ~LinkedList();  // 析构函数,释放线性表占用的空间
        bool check_circle(); // 检查是否成环
        LinkedList(const LinkedList&); // 拷贝构造函数
        LinkedList& operator=(const LinkedList&);  // 赋值运算符重载
        int Josephus(const int& n,const int& m,const int& k);  // 约瑟夫问题
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        LinkedList list;
        cin>>n>>m>>k;
        int ans=list.Josephus(n,m,k);
        LinkedList list2(list);
        LinkedList list3;
        list3=list2;
        if(list2.check_circle()&&list3.check_circle()){
            cout<<ans<<endl;
        }
        else{
            cout<<"检测到你没有使用环形链表，这个题不给分哦"<<endl;
        }
    }
}
LinkedList::LinkedList()
{
    head_=new ListNode{0,NIL};  // 头指针指向一个空头结点
    head_->next_=head_;  // 头结点指向自己，形成环
    length_=0;
}
LinkedList::~LinkedList()
{
    Position p=head_->next_,temp;
    while (p!=head_&&p!=NIL) {
        temp=p;
        p=p->next_;
        delete temp;
        --length_;
    }
    delete head_;
    if (length_!=0) {
        std::cout<<"释放空间出错，lenth_="<<length_<<endl;
    }
}
bool LinkedList::check_circle()
{
    if (head_==NIL||head_->next_==head_) {
        // 如果链表为空或只有头结点，则是一个有效的循环链表
        return true;
    }
    Position slow=head_->next_;  // 慢指针
    Position fast=head_->next_;  // 快指针
    while (fast!=NIL&&fast->next_!=NIL) {
        slow=slow->next_;          // 慢指针每次移动一步
        fast=fast->next_->next_;   // 快指针每次移动两步
        // 如果快慢指针相遇，说明链表中有环
        if (slow==fast) {
            return true;
        }
    }
    // 如果快指针到达了末尾，说明没有环
    return false;
}
LinkedList::LinkedList(const LinkedList& llist)
{
    head_=new ListNode{0,NIL};
    Position p=llist.head_->next_,q=head_;
    while(p!=llist.head_){
        q->next_=new ListNode{p->data_,NIL};
        p=p->next_;
        q=q->next_;
    }
    q->next_=head_;
    length_=llist.length_;
}
LinkedList& LinkedList::operator=(const LinkedList& llist)
{
    Position p=head_->next_;
    while (p!=head_&&p) {
        Position temp=p;
        p=p->next_;
        delete temp;
        length_--;
    }
    delete head_;
    head_=new ListNode{0,NIL};
    p=llist.head_->next_;
    Position q=head_;
    while(p!=llist.head_){
        q->next_=new ListNode{p->data_,NIL};
        p=p->next_;
        q=q->next_;
    }
    q->next_=head_;
    length_=llist.length_;
    return *this;
}
int LinkedList::Josephus(const int& n,const int& m,const int& k)
{
    int cnt=0;
    Position p=head_;
    for (int i=1;i<=n;i++){
        p->next_=new ListNode{i,NIL};
        p=p->next_;
        length_++;
    }
    p->next_=head_;
    p=head_;
    while (length_>0){
        for (int i=1;i<m;i++){
            p=p->next_;
            if (p==head_){
                p=p->next_;
            }
        }
        Position temp=p->next_;
        if (temp==head_){
            temp=temp->next_;
            p=p->next_;
        }
        p->next_=temp->next_;
        int data=temp->data_;
        delete temp;
        length_--;
        cnt++;
        if (cnt==k){
            return data;
        }
    }
}