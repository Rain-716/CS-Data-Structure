#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
struct node{
    int c;
    int e;
    node *next;
    node(){}
    node(int c,int e):c(c),e(e),next(NULL){}
};
class Polynomial{
    private:
        node* head;
    public:
        Polynomial();// 默认构造函数
        Polynomial(const Polynomial& other);// 拷贝构造函数
        Polynomial& operator=(const Polynomial& other);// 赋值运算符重载
        ~Polynomial();// 析构函数
        void insert(int c,int e);// 参数 c 表示系数，e 表示指数。
        Polynomial derivative();// 根据每项的指数进行求导，新的系数是原系数乘以指数，指数减 1
        void print();//打印函数：按顺序打印多项式的每一项
        void clear();// 清除函数：释放链表中所有节点的内存并将头指针置为 NULL
};
Polynomial::Polynomial():head(NULL){}
Polynomial::Polynomial(const Polynomial& other):head(NULL) {
    if (other.head==NULL) return;
    head=new node(other.head->c,other.head->e);
    node* current=head;
    node* other_current=other.head->next;
    while (other_current!=NULL) {
        current->next=new node(other_current->c,other_current->e);
        current=current->next;
        other_current=other_current->next;
    }
}
Polynomial& Polynomial::operator=(const Polynomial& other) {//赋值运算符重载
    if (this==&other) {
        return *this;
    }
    clear();
    if (other.head!=NULL) {
        head=new node(other.head->c,other.head->e);
        node* current=head;
        node* other_current=other.head->next;
        while (other_current!=NULL) {
            current->next=new node(other_current->c,other_current->e);
            current=current->next;
            other_current=other_current->next;
        }
    }
    return *this;
}
void Polynomial::clear() {
    node* now=head;
    while (now!=NULL) {
        node* tmp=now;
        now=now->next;
        delete tmp;
    }
    head=NULL;
}
Polynomial::~Polynomial(){
    clear();
}
void Polynomial::print(){
    node* now=head;
    if(now==NULL){
        cout<<"0"<<endl;
        return;
    }
    while(now!=NULL){
        cout<<now->c<<"x^"<<now->e<<" ";
        now=now->next;
    }
    cout<<endl;
}
void Polynomial::insert(int c,int e)
{
    if (!head){
        head=new node(c,e);
        return;
    }
    if (head->e<e){
        node* q=new node(c,e);
        q->next=head;
        head=q;
        return;
    }
    node* p=head;
    while (p->next&&p->next->e>e){
        p=p->next;
    }
    node* q=new node(c,e);
    q->next=p->next;
    p->next=q;
}
Polynomial Polynomial::derivative()
{
    Polynomial res;
    node* p=head;
    while(p&&p->e>=1){
        res.insert(p->c*p->e,p->e-1);
        p=p->next; 
    }
    return res;
}
signed main(){
    Polynomial p;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int c,e;cin>>c>>e;
        p.insert(c,e);
    }
    Polynomial p2=p.derivative();
    p2.print();
}