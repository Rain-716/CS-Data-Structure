#include <iostream>
#include <string>
using namespace std;
#define NIL nullptr
typedef int ElemType;
typedef struct ListNode* Position;  // 指针即结点位置
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
        string error_;
        ListException(string s) :error_(s) {};
    };
    LinkedList();  // 构造函数，初始化一个空的线性表
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();  // 析构函数,释放线性表占用的空间
    Position Search(ElemType x);  // 在线性表中查找元素x，查找成功，返回x的位置，否则返回NIL
    void Insert(ElemType tar,ElemType x);  // 在线性表的元素tar后插入元素x
    void Remove(ElemType x);  // 从线性表中删除第一个值为x的元素
    friend ostream& operator<<(ostream&,const LinkedList&); //输出一个链表
    friend istream& operator>>(istream&,LinkedList&);  //输入一个链表
};
int main()
{
    LinkedList List;
    cin >> List;
    // op: 0表示插入操作，1表示删除操作，2表示搜索操作
    // tar: 插入/删除的目标节点值
    // val: 插入操作时的新节点值，删除操作时可忽略
    int op=0,tar=0,val=0;
    int nOp=0;
    cin>>nOp;
    for (int i=0;i<nOp;i++) {
        cin>>op>>tar;
        if (op==0) { // 插入
            cin>>val;
            List.Insert(tar,val);
        }
        else if (op==1) { // 删除
            val=tar;
            List.Remove(val);
        }
        else { // 搜索
            val=tar;
            Position pos=List.Search(val);
            if (pos) {
                cout<<pos->data_<<endl;
            }
            else {
                cout<<-1<<endl;
            }
        }
    }
    cout<<List<<endl;
    return 0;
}
LinkedList::LinkedList()
{
    head_=new ListNode{0,NIL};  // 头指针指向一个空头结点
    length_=0;
}
LinkedList::LinkedList(const LinkedList& llist)
{
    Position temp,p;
    temp=llist.head_->next_;
    length_=llist.length_;
    head_=new ListNode{0,NIL};  // 产生空头结点
    p=head_;
    while (temp!=NIL) {
        p->next_=new ListNode{temp->data_,NIL};
        p=p->next_;
        temp=temp->next_;
    }
}
LinkedList& LinkedList::operator=(const LinkedList& llist)
{
    Position p,temp;
    if (this!=&llist) {
        p=head_->next_;
        while (p!=NIL) {
            temp=p;
            p=p->next_;
            delete temp;
        }
        length_=0;
        head_->next_=NIL;
        temp=llist.head_->next_;
        length_=llist.length_;
        p=head_;
        while (temp!=NIL) {
            p->next_=new ListNode{temp->data_,NIL};
            p=p->next_;
            temp=temp->next_;
        }
    }
    return *this;
}
LinkedList::~LinkedList()
{
    Position p=head_;
    while (p!=NIL) {
        head_=p->next_;
        delete p;
        p=head_;
    }
    length_=0;
}
ostream& operator<<(ostream& os,const LinkedList& llist)
{
    if (llist.length_==0) {
        cout<<endl;
        return os;
    }
    Position p=llist.head_->next_;
    cout<<p->data_;
    p=p->next_;  //输出头结点信息
    while (p!=NIL) {
        cout<<" "<<p->data_;
        p=p->next_;
    }
    cout<<endl;
    return os;
}
istream& operator>>(istream& is,LinkedList& llist)
{
    Position q,p;
    q=p=llist.head_->next_;
    while (p!=NIL) {  //删除llist原有的结点
        q=p->next_;
        delete p;
        p=q;
    }
    llist.head_->next_=NIL;
    llist.length_=0;
    int n,d;
    cin>>n;
    if (n==0) {
        return is;
    }
    p=llist.head_;
    for (int i=1;i<=n;i++)
    {
        cin>>d;
        q=new ListNode{d,NIL};
        p->next_=q;
        p=q;
    }
    llist.length_=n;
    return is;
}
Position LinkedList::Search(ElemType x)
{
    Position p=head_->next_;
    while (p&&p->data_!=x){
        p=p->next_;
    }
    return p;
}
void LinkedList::Insert(ElemType tar,ElemType x)
{
    if (!head_->next_){
        Position p=new ListNode{x,NIL};
        head_->next_=p;
        length_++;
        return;
    }
    Position p=this->Search(tar);
    Position q=new ListNode{x,p->next_};
    p->next_=q;
    length_++;
}
void LinkedList::Remove(ElemType x)
{
    Position p=head_;
    while (p->next_&&p->next_->data_!=x){
        p=p->next_;
    }
    if (p->next_){
        Position temp=p->next_;
        p->next_=temp->next_;
        delete temp;
        length_--;
    }
}