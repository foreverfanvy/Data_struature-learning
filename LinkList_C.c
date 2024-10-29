/*本文件配套使用的是链表操作
 *原始结构设定为1个int+1个指向node的指针
 *包含的基础C库是stdio and stdlib
 *注意这个文件没有main函数只是用来引入库而已不要直接编译运行
 *执行的功能有：
 *      1.node *init_LinkNode(int val)
 *      初始化一个节点
 *      2.void delete_LinkList(node *head)
 *      删除释放链表占用的空间
 *      3.node *insert_LinkList(node *head, int val,int position)
 *      插入一个val到pos位置，初始Index从0开始
 *      4.int search_LinkList(node *head,int val)
 *      在链表中的data查询有没有val这个数据
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

//初始化一个链表
node *init_LinkNode(int val)
{
    node *head = (node *)malloc(sizeof(node));
    head->data = val;
    head->next = NULL;
    return head;
}

//销毁链表
void delete_LinkList(node *head)
{
    if(head == NULL)return  ;
    for(node *temp = head,*q; temp != NULL; temp = q)
    {
        q = temp->next;
        free(temp);
    }
}

//插入操作
node *insert_LinkList(node *head, int val,int position)
{
    if(head == NULL)return NULL;
    if(position ==0)
    {
        node *q = init_LinkNode(val);
        q->next = head;
        return q;
    }
    node *q = init_LinkNode(val);
    node *temp = head;
    for(int i=0;i<position-1;i++)temp = temp->next;
    q->next = temp->next;
    temp->next = q;
    return head;
}

//在链表中搜索某一个数
int search_LinkList(node *head,int val)
{
    node *temp = head;
    int count = 0;
    while(temp->data != val)
    {
        if(temp->next == NULL)return -1;
        temp = temp->next;
        count++;
        if(temp->data == val)
        {
            printf("Its Index is %d",count);
            return count;
        }
    }
}


