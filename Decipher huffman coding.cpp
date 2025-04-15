#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAXN 1000
#define inf 0x7fffffff
typedef struct huffnode
{
    char data; // 值
    struct huffnode* leftChild;     // 左子树
    struct huffnode* rightChild;    // 右子树
} HUFFNODE;
void input()
{

}
void decipherHuffmanCoding(HUFFNODE* head,char cipher[])
{
    int i=0;
    HUFFNODE* temp=head;
    while (cipher[i]=='0'||cipher[i]=='1'){
        if (!(cipher[i]-'0')){
            temp=temp->leftChild;
        }
        else {
            temp=temp->rightChild;
        }
        i++;
        if ((!temp->leftChild)&&(!temp->rightChild)){
            std::cout<<temp->data;
            temp=head;
        }
    }
}
int main()
{
    input();
    HUFFNODE* head;
    char cipher[MAXN];
    decipherHuffmanCoding(head,cipher);
    return 0;
}