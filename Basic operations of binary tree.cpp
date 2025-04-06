#include <bits/stdc++.h>
using namespace std;
class BiNODE
{
    public:
        char data; // 结点值，字符类型，可以按字典序比较大小
        BiNODE* lchild; // 左子节点
        BiNODE* rchild; // 右子节点
        BiNODE(char d='\0');//构造函数
        ~BiNODE();//析构函数
};
BiNODE::BiNODE(char d) : data(d),lchild(nullptr),rchild(nullptr) {}
BiNODE::~BiNODE()
{
    delete lchild;
    delete rchild;
}
class BinaryTree
{
    public:
        BinaryTree(BiNODE* r=nullptr);  // 构造函数
        ~BinaryTree(); //析构函数
        BiNODE* BuildTree();  // 构建二叉树的函数
        void Recursion_Pre_Order(BiNODE* node);  // 递归前序遍历函数
        void NoRecursion_Pre_Order(BiNODE* node);  // 非递归前序遍历函数
        void Recursion_In_Order(BiNODE* node);  // 递归中序遍历函数
        void NoRecursion_In_Order(BiNODE* node);  // 非递归中序遍历函数
        void Recursion_Post_Order(BiNODE* node);  // 递归后序遍历函数
        void NoRecursion_Post_Order(BiNODE* node);  // 非递归后序遍历函数
        void Hierachicalorder(BiNODE* node);  // 层次遍历函数
        int Size_Of_Tree(BiNODE* node);  // 计算二叉树大小的函数
        int Height_Of_Tree(BiNODE* node);  // 计算二叉树高度的函数
        bool Is_Full_Tree(BiNODE* node);  // 判断是否为满二叉树的函数
        bool Is_Complete_Tree(BiNODE* node);  // 判断是否为完全二叉树的函数
        bool Is_Perfect_Tree(BiNODE* node);  // 判断是否为完美二叉树的函数
        BiNODE* GetRoot();  // 获取根节点的函数
        void SetRoot(BiNODE* node);  // 修改根节点的函数
    private:
        BiNODE* root;  // 二叉树的根节点
        void freeTree(BiNODE* node);  // 释放二叉树节点的函数
};
BinaryTree::BinaryTree(BiNODE* r) : root(r) {}
BinaryTree::~BinaryTree()
{
    freeTree(root);
}
void BinaryTree::freeTree(BiNODE* node)
{
    if (node){
        delete node;
    }
}
BiNODE* BinaryTree::GetRoot()
{
    return root;
}
void BinaryTree::SetRoot(BiNODE* node)
{
    root=node;
}
BiNODE* buildTree(vector <char>& pre,int preL,int preR,unordered_map <char,int>& in,int inL,int inR)
{
    if (preL>preR||inL>inR){
        return nullptr;
    }
    char rootVal=pre[preL];
    BiNODE* root=new BiNODE(rootVal);
    int i=in[rootVal];
    root->lchild=buildTree(pre,preL+1,preL+i-inL,in,inL,i-1);
    root->rchild=buildTree(pre,preL+i-inL+1,preR,in,i+1,inR);
    return root;
}
BiNODE* BinaryTree::BuildTree()
{
    int n;
    cin>>n;
    vector <char> pre(n);
    unordered_map <char,int> in(n);
    for (int i=0;i<n;i++){
        cin>>pre[i];
    }
    for (int i=0;i<n;i++){
        char t;
        cin>>t;
        in[t]=i;
    }
    this->root=buildTree(pre,0,n-1,in,0,n-1);
    return root;
}
void BinaryTree::Recursion_Pre_Order(BiNODE* node)
{
    if (node){
        cout<<node->data<<" ";
        Recursion_Pre_Order(node->lchild);
        Recursion_Pre_Order(node->rchild);
    }
}
void BinaryTree::NoRecursion_Pre_Order(BiNODE* node)
{
    stack <BiNODE*> s;
    s.push(node);
    while (!s.empty()){
        BiNODE* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if (temp->rchild){
            s.push(temp->rchild);
        }
        if (temp->lchild){
            s.push(temp->lchild);
        }
    }
}
void BinaryTree::Recursion_In_Order(BiNODE* node)
{
    if (node){
        Recursion_In_Order(node->lchild);
        cout<<node->data<<" ";
        Recursion_In_Order(node->rchild);
    }
}
void BinaryTree::NoRecursion_In_Order(BiNODE* node)
{
    stack <BiNODE*> s;
    BiNODE* temp=node;
    while (!s.empty()||temp){
        while (temp){
            s.push(temp);
            temp=temp->lchild;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->rchild;
    }
}
void BinaryTree::Recursion_Post_Order(BiNODE* node)
{
    if (node){
        Recursion_Post_Order(node->lchild);
        Recursion_Post_Order(node->rchild);
        cout<<node->data<<" ";
    }
}
void BinaryTree::NoRecursion_Post_Order(BiNODE* node)
{
    stack <BiNODE*> s1,s2;
    s1.push(node);
    while (!s1.empty()){
        BiNODE* temp=s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->lchild){
            s1.push(temp->lchild);
        }
        if (temp->rchild){
            s1.push(temp->rchild);
        }
    }
    while (!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
void BinaryTree::Hierachicalorder(BiNODE* node)
{
    queue <BiNODE*> q;
    q.push(node);
    while (!q.empty()){
        BiNODE* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if (temp->lchild){
            q.push(temp->lchild);
        }
        if (temp->rchild){
            q.push(temp->rchild);
        }
    }
}
int BinaryTree::Size_Of_Tree(BiNODE* node)
{
    if (!node){
        return 0;
    }
    return Size_Of_Tree(node->lchild)+Size_Of_Tree(node->rchild)+1;
}
int BinaryTree::Height_Of_Tree(BiNODE* node)
{
    if (!node){
        return 0;
    }
    return max(Height_Of_Tree(node->lchild),Height_Of_Tree(node->rchild))+1;
}
bool BinaryTree::Is_Full_Tree(BiNODE* node)
{
    if (!node){
        return true;
    }
    BiNODE *l=node->lchild,*r=node->rchild;
    if ((l&&!r)||(!l&&r)){
        return false;
    }
    return Is_Full_Tree(l)&&Is_Full_Tree(r);
}
bool BinaryTree::Is_Complete_Tree(BiNODE* node)
{
    bool eNull=false;
    queue <BiNODE*> q;
    q.push(node);
    while (!q.empty()){
        BiNODE* temp=q.front();
        q.pop();
        BiNODE *l=temp->lchild,*r=temp->rchild;
        if (!l&&!eNull){
            eNull=true;
        }
        else if (l){
            if (eNull){
                return false;
            }
            q.push(l);
        }
        if (!r&&!eNull){
            eNull=true;
        }
        else if (r){
            if (eNull){
                return false;
            }
            q.push(r);
        }
    }
    return true;
}
bool BinaryTree::Is_Perfect_Tree(BiNODE* node)
{
    return Size_Of_Tree(node)==(1<<(Height_Of_Tree(node)))-1;
}
int main(void)
{
    BinaryTree tree;
    tree.BuildTree();
    tree.Recursion_Pre_Order(tree.GetRoot());
    printf("\n");
    tree.NoRecursion_Pre_Order(tree.GetRoot());
    printf("\n");
    tree.Recursion_In_Order(tree.GetRoot());
    printf("\n");
    tree.NoRecursion_In_Order(tree.GetRoot());
    printf("\n");
    tree.Recursion_Post_Order(tree.GetRoot());
    printf("\n");
    tree.NoRecursion_Post_Order(tree.GetRoot());
    printf("\n");
    tree.Hierachicalorder(tree.GetRoot());
    printf("\n");
    printf("%d\n",tree.Size_Of_Tree(tree.GetRoot()));
    printf("%d\n",tree.Height_Of_Tree(tree.GetRoot()));
    printf("%c\n",tree.Is_Full_Tree(tree.GetRoot()) ? 'T' : 'F');
    printf("%c\n",tree.Is_Complete_Tree(tree.GetRoot()) ? 'T' : 'F');
    printf("%c\n",tree.Is_Perfect_Tree(tree.GetRoot()) ? 'T' : 'F');
    return 0;
}