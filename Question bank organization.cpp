#include <iostream>
using namespace std;
// 定义链表节点结构
struct Node
{
    int value; // 节点值
    Node* next; // 指向下一个节点的指针
    Node(int v,Node* n=nullptr); // 构造函数
};
// 自定义堆栈类
class CustomStack
{
    private:
        Node* stackTop; // 主堆栈的栈顶指针
        Node* maxStackTop; // 最大值堆栈的栈顶指针
    public:
        // 构造函数
        CustomStack();
        // 析构函数，释放所有节点
        ~CustomStack();
        // 入栈操作
        void push(int x);
        // 出栈操作
        void pop();
        // 获取当前最大值
        int getMax();
};
// Node 构造函数实现
Node::Node(int v,Node* n) : value(v),next(n) {}
// CustomStack 构造函数实现
CustomStack::CustomStack() : stackTop(nullptr),maxStackTop(nullptr) {}
// CustomStack 析构函数实现
CustomStack::~CustomStack()
{
    while (stackTop) {
        Node* temp=stackTop;
        stackTop=stackTop->next;
        delete temp;
    }
    while (maxStackTop) {
        Node* temp=maxStackTop;
        maxStackTop=maxStackTop->next;
        delete temp;
    }
}
void CustomStack::push(int x)
{
    stackTop=new Node(x,stackTop);
    if (!maxStackTop||x>=maxStackTop->value){
        maxStackTop=new Node(x,maxStackTop);
    }
}
void CustomStack::pop()
{
    if (!stackTop){
        return;
    }
    Node* temp=stackTop;
    int val=temp->value;
    stackTop=stackTop->next;
    delete temp;
    if (maxStackTop->value==val){
        temp=maxStackTop;
        maxStackTop=maxStackTop->next;
        delete temp;
    }
}
int CustomStack::getMax()
{
    if (!stackTop){
        return 0;
    }
    return maxStackTop->value;
}
int main() 
{
    int N;
    cin>>N; // 读取操作总数
    CustomStack cs; // 创建自定义堆栈对象
    for (int i=0;i<N;++i) {
        int op;
        cin>>op; // 读取操作类型
        if (op==0) {
            int X;
            cin>>X; // 读取入库题目的难度
            cs.push(X); // 执行入库操作
        } 
        else if (op==1) {
            cs.pop(); // 执行出库操作
        }
        else if (op==2) {
            cout<<cs.getMax()<<endl; // 输出当前题库中最难题目的难度
        }
    }
    return 0;
}