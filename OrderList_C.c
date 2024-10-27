/*本文件配套使用的是顺序表操作
 *原始结构设定为2个int+1个指向int的指针
 *包含的基础C库是stdio and stdlib
 *注意这个文件没有main函数只是用来引入库而已不要直接编译运行
 *执行的功能有：
    1.vector *init(int size)
    初始化空的顺序表
    2.void destroy(vector *v)
    销毁顺序表
    3.int insert(vector *v,int pos,int val)
    插入数据
    4.int erase(vector *v,int pos)
    删除数据
    5.int expend(vector *v)     +    int insert_plus(vector *v,int pos,int val)
    扩容插入操作
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
    int size,count;
    int *data;
}vector;

//初始化一个空的顺序表
vector *init(int size)
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->size = size;
    v->count = 0;
    v->data = (int*)malloc(sizeof(int)*size);
    return v;
}

//销毁一个顺序表
void destroy(vector *v)
{
    free(v->data);
    free(v);
}

//插入一个数据
int insert(vector *v,int pos,int val)
{
    if(v->count == v->size)
    {
        printf("Your vector is full\n");
        return 0;
    }
    for(int i = v->size; i > pos; i--)
    {
        v->data[i] = v->data[i-1];
    }
    v->data[pos] = val;
    v->count++;
    printf("You have inserted %d to %d\n",v->data[pos],pos);
    return 1;
}

//删除操作
int erase(vector *v,int pos)
{
    if(pos<0||pos>v->count)
    {
        printf("Your position is not right\n");
        return 0;
    }
    for(int i = pos; i < v->size; i++)
    {
        v->data[i] = v->data[i+1];
    }
    v->count--;
    printf("You have erased %d in %d\n",v->data[v->size-1],pos);
    return 1;
}

//双倍扩容操作
int expend(vector *v)
{
    if(v == NULL)return 0;
    if(v->count == v->size)
    {
        int *p = (int *)realloc(v->data,sizeof(int)*v->size*2);
        if(p != NULL)v->data = p;
        else return 0;
    }
    v->size = v->size * 2;
    return 1;
}
//配套插入操作
int insert_plus(vector *v,int pos,int val)
{
    if(v->count == v->size)
    {
        expend(v);
    }
    for(int i = v->size; i > pos; i--)
    {
        v->data[i] = v->data[i-1];
    }
    v->data[pos] = val;
    v->count++;
    printf("You have inserted %d to %d\n",v->data[pos],pos);
    return 1;
}

