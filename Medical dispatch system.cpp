#include <iostream>
class Queue
{
    private:
        struct Node
        {
            int citizen;
            Node *next;
            Node(int c) : citizen(c),next(nullptr) {}
        };
        Node *front; // 队列的头指针
        Node *rear;  // 队列的尾指针
    public:
        Queue();                   // 无参构造函数
        Queue(const Queue &q);      // 拷贝构造函数
        Queue &operator=(const Queue &q); // 赋值运算符重载
        ~Queue();                  // 析构函数
        bool isEmpty() const;
        void enqueueFront(int citizen);
        void enqueueRear(int citizen);
        int dequeue();
        void remove(int citizen);
};
// 无参构造函数
Queue::Queue() : front(nullptr),rear(nullptr) {}
// 拷贝构造函数
Queue::Queue(const Queue &q)
{
    front=rear=nullptr;  // 初始化为空队列
    Node *temp=q.front;    // 从源队列的头开始遍历
    while (temp!=nullptr){
        enqueueRear(temp->citizen); // 逐个复制节点
        temp=temp->next;
    }
}
// 赋值运算符重载
Queue &Queue::operator=(const Queue &q)
{
    if (this!=&q){
        // 清空当前队列
        while (!isEmpty()){
            dequeue();
        }
        // 复制源队列
        Node *temp=q.front;
        while (temp!=nullptr){
            enqueueRear(temp->citizen);
            temp=temp->next;
        }
    }
    return *this;
}
// 析构函数
Queue::~Queue()
{
    while (front!=nullptr){
        Node *temp=front;
        front=front->next;
        delete temp;
    }
}
bool Queue::isEmpty() const
{
    return !front&&!rear;
}
void Queue::enqueueFront(int citizen)
{
    Node* temp=new Node(citizen);
    temp->next=front;
    front=temp;
    if (front->next==nullptr){
        rear=front;
    }
}
void Queue::enqueueRear(int citizen)
{
    if (this->isEmpty()){
        front=new Node(citizen);
        rear=front;
        return;
    }
    rear->next=new Node(citizen);
    rear=rear->next;
}
int Queue::dequeue()
{
    if (this->isEmpty()){
        return -1;
    }
    Node* tempn=front;
    int tempc=front->citizen;
    front=front->next;
    if (!front){
        rear=nullptr;
    }
    delete tempn;
    return tempc;
}
void Queue::remove(int citizen)
{
    if (this->isEmpty()){
        return;
    }
    if (this->front->citizen==citizen){
        this->dequeue();
        return;
    }
    Node* temp=front;
    while (temp->next!=nullptr){
        if (temp->next->citizen!=citizen){
            temp=temp->next;
            continue;
        }
        Node* del=temp->next;
        temp->next=del->next;
        if (!(temp->next)){
            rear=temp;
        }
        delete del;
    }
}
int main()
{
    int caseCount=0;
    int P,C;
    while (std::cin>>P>>C){
        if (P==0&&C==0){
            break;
        }
        caseCount++;
        std::cout<<"Case "<<caseCount<<":"<<std::endl;
        Queue queue;
        for (int i=1;i<=(P<C?P:C);i++){
            queue.enqueueRear(i);
        }
        int citizen;
        for (int i=0;i<C;i++){
            char command;
            std::cin>>command;
            if (command=='N'){
                citizen=queue.dequeue();
                std::cout<<citizen<<std::endl;
                queue.enqueueRear(citizen);
            }
            else if (command=='E'){
                int x;
                std::cin>>x;
                queue.remove(x);
                queue.enqueueFront(x);
            }
        }
    }
    return 0;
}