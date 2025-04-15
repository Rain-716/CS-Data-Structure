#define MAXN 107 // 最大节点个数
#define INFINITY_WEIGHT 0x3F3F3F // 权重无穷大
#include <bits/stdc++.h>
typedef struct node
{
	char data;
	double weight;
    int leafNumber=1,pathLength=0;
    std::string code="",leafSeq;
	struct node *leftChild=nullptr,*rightChild=nullptr;
    node (char d,double w) : data(d),leafSeq(1,d),weight(w){}
} NODE;
bool cmp(node* n1,node* n2)
{
    if (fabs(n1->weight-n2->weight)>1e-9){
        return n1->weight>n2->weight;
    }
    if (n1->leafNumber!=n2->leafNumber){
        return n1->leafNumber>n2->leafNumber;
    }
    return n1->leafSeq>n2->leafSeq;
}
void Encode(node* root)
{
    if (root->leftChild){
        root->leftChild->code=root->code+"0";
        root->leftChild->pathLength=root->pathLength+1;
        Encode(root->leftChild);
    }
    if (root->rightChild){
        root->rightChild->code=root->code+"1";
        root->rightChild->pathLength=root->pathLength+1;
        Encode(root->rightChild);
    }
}
NODE* createHuffmanTree(char data[],double weight[],int number)
{
    std::vector <node*> a(number),copy(number);
    for (int i=0;i<number;i++){
        node* temp=new node(data[i],weight[i]);
        a[i]=temp;
        copy[i]=temp;
    }
    while (a.size()>1){
        sort(a.begin(),a.end(),cmp);
        node *i=a[a.size()-1],*j=a[a.size()-2];
        a.pop_back();a.pop_back();
        node* k=new node('*',i->weight+j->weight);
        k->leafSeq=i->leafSeq+j->leafSeq;
        sort(k->leafSeq.begin(),k->leafSeq.end());
        k->leafNumber=i->leafNumber+j->leafNumber;
        k->leftChild=i;k->rightChild=j;
        a.push_back(k);
    }
    node* root=a[0];
    Encode(root);
    for (int i=0;i<number;i++){
        node* temp=copy[i];
        std::cout<<data[i]<<" "<<temp->code<<" "<<temp->pathLength<<" "<<std::fixed<<std::setprecision(3)<<temp->weight*temp->pathLength<<std::endl;
    }
    return root;
}
int main()
{
    int number;
    std::cin>>number;
    char data[number];
    double weight[number];
    for (int i=0;i<number;i++){
        std::cin>>data[i];
    }
    for (int i=0;i<number;i++){
        std::cin>>weight[i];
    }
    NODE* root=createHuffmanTree(data,weight,number);
    std::cout<<"judge passed"<<std::endl;
    return 0;
}