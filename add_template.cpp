#include <iostream>
using namespace std;
#define MAX_SIZE 100010
struct node // 表示单链表的一个节点
{
	int val;	// 表示当前节点的值
	node *next; // 表示指向下一节点的指针
	node() {}
	node(int v) : val(v),next(NULL) {} // 构造一个值为 v 的节点的构造函数
};
class Stack // 表示一个栈
{
	private:
		int capacity; // 表示栈最多能存储的元素个数
		int size;	  // 表示当前栈中存储的元素个数
		int *data;	  // 存储栈中元素的数组，默认元素类型为整型
	public:
		Stack(unsigned=MAX_SIZE);								  // 构造函数，初始化一个空栈
		~Stack();												  // 析构函数
		friend istream &operator>>(istream &,Stack &);			  // 读入一个大整数，存储在栈中
		bool empty();											  // 返回栈是否为空
		void push(int x); // 向栈顶压入一个元素
		int top();		  // 返回栈顶元素
		void pop();		  // 弹出栈顶的元素，注意这个函数没有返回值
};
node *add(Stack &s1,Stack &s2); // 将两个以栈的形式表示的非负大整数相加，得到的结果存入链表后返回（需要完成）
int main()
{
	Stack s1,s2;
	cin>>s1>>s2;
	node *res=add(s1,s2);
	while (res!=NULL){
		cout<<res->val;
		res=res->next;
	}
	return 0;
}
Stack::Stack(unsigned sz)
{
	data=new int[sz]{0};
	capacity=sz;
	size=0;
}
Stack::~Stack()
{
	delete[] data;
	capacity=0;
	size=0;
}
istream &operator>>(istream &is,Stack &st)
{
	string s;
	cin>>s;
	int sz=s.size();
	for (int i=0;i<sz;i++){
		st.push(s[i]-'0');
	}
	return is;
}
bool Stack::empty()
{
	return !size;
}
void Stack::push(int x)
{
	data[size]=x;
	size++;
}
int Stack::top()
{
	if (this->empty()){
		return 0;
	}
	return data[size-1];
}
void Stack::pop()
{
	if (!this->empty()){
		size--;
	}
}
node *add(Stack &s1,Stack &s2)
{
	int carry=0;
	node* head=nullptr;
	while (!(s1.empty()&&s2.empty())){
		int num1=s1.top();
		int num2=s2.top();
		s1.pop();
		s2.pop();
		int sum=num1+num2+carry;
		carry=sum/10;
		node* temp=new node{sum%10};
		temp->next=head;
		head=temp;
	}
	if (carry){
		node* temp=new node{carry};
		temp->next=head;
		head=temp;
	}
	return head;
}