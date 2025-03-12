#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
class Solution
{
    public:
        struct Node          // Node为链式存储的栈内结点类
        {        
            int element_;    // 结点存储的元素
            Node *next_;     // 下一个结点地址（自顶向下）
            Node()=delete;   // 创建结点必须指定元素值和下一个结点地址
            Node(int element,Node *next) : element_(element),next_(next) {}
        };
        static void Solve() // 对一个序列进行判断，输出结果
        { 
            int n;
            std::cin>>n;
            std::string out_seq;
            std::cin>>out_seq;
            MyStackAndGetAns::GetAns(n,out_seq);
        }
    private:
        class MyStackAndGetAns  // 栈的实现和答案输出
        { 
            public:
                MyStackAndGetAns()  // 构造函数，重置栈顶和栈内元素个数
                { 
                    top_=nullptr;
                    size_=0;
                }
                virtual ~MyStackAndGetAns() // 析构函数，清空栈
                { 
                    while (top_!=nullptr) {
                        Node *next=top_->next_;
                        delete top_;
                        top_=next;
                        assert(size_>0);
                        size_--;
                    }
                    assert(size_==0);
                }
                void Push(int element)
                { 
                    top_=new Node{element,top_};
                    size_++;
                }
                int Top()
                {
                    if (this->Empty()){
                        return 0;
                    }
                    return top_->element_;
                }
                void Pop()
                {
                    Node* temp=top_;
                    top_=top_->next_;
                    delete temp;
                    size_--;
                }
                bool Empty()
                {
                    return !top_;
                }
                static void GetAns(int n,std::string out_seq)
                {
                    int j=1;
                    bool b=0;
                    MyStackAndGetAns s;
                    for (int i=0;i<n;i++){
                        while (s.Top()!=out_seq[i]-'0'&&j<=n&&!b){
                            b=j==n;
                            b ? s.Push(j) : s.Push(j++);
                        }
                        if (j==n&&s.Top()!=out_seq[i]-'0'){
                            std::cout<<"no"<<std::endl;
                            return;
                        }
                        s.Pop();
                    }
                    std::cout<<"yes"<<std::endl;
                }
            private:
                size_t size_; // 栈内元素数量
                Node *top_;   // 栈顶指针
        };
};
int main()
{
    int k;
    std::cin>>k;
    while (k--) {
        Solution::Solve();
    }
    return 0;
}