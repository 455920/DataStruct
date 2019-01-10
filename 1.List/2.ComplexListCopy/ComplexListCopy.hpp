#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define DataType int

typedef struct ComplexListNode
{
    int value_;
    struct ComplexListNode* Next_;
    struct ComplexListNode* Rand_;
}Node,*pNode;


pNode BuyNode(DataType value)
{
  pNode cur=(pNode)malloc(sizeof(DataType));
  assert(cur);
  cur->value_=value;
  cur->Next_=NULL;
  cur->Rand_=NULL;
  return cur;
}



void BackPush(pNode* pRoot,DataType value)
{
  pNode cur;
  assert(pRoot);
  cur = *pRoot;
  if(cur==NULL)
  {
    *pRoot = BuyNode(value); 

  }
  else 
  {
    while(cur->Next_)
    {
      cur=cur->Next_;

    } 
     cur->Next_=BuyNode(value);

  }

}

void BackPop(pNode* pRoot)
{
  pNode cur;
  assert(pRoot);
  cur=*pRoot;
  if(cur==NULL)
    return;
  else if(cur->Next_==NULL)
  {
     free(cur);
     *pRoot=NULL;

  }
  else 
  {
    while(cur->Next_->Next_)
    {
      cur=cur->Next_;
  
    }
    free(cur->Next_);
    cur->Next_=NULL;

  }

}

void Print(pNode root)
{
  if(root==NULL)
  {
    return;

  }
  while(root->Next_)
  {
    if(root->Rand_)
    printf("%d(%d)->",root->value_,root->Rand_->value_);
    else
    printf("%d(null)->",root->value_);
    root=root->Next_;

  }
  if(root->Rand_)
    printf("%d(%d)\n",root->value_,root->Rand_->value_);
  else 
    printf("%d(null)\n",root->value_);

} 


pNode CpComplexList(pNode root)
{
  pNode ret;
  pNode cur=root;
  if(root==NULL)
    return NULL;
  //1.插入复制
  while(cur)
  {
    pNode tmp = BuyNode(cur->value_);
    tmp->Next_=cur->Next_;
    cur->Next_=tmp;
    cur=cur->Next_->Next_;
  }
  //2.复制rand指针
  cur=root;
  while(cur)
  {
    //第一个注意的地方，Rand不为空才进行此步
    if(cur->Rand_)
    cur->Next_->Rand_=cur->Rand_->Next_;
    cur=cur->Next_->Next_;
  }
  //3.拆
  ret=root->Next_;
  cur=root;
  while(cur)
  {
    pNode cur1 = cur->Next_;
    cur->Next_=cur1->Next_;
    //注意地方2，处理最后的节点
    if(cur1->Next_)
    cur1->Next_=cur1->Next_->Next_;
    cur=cur->Next_;
  }
  return ret;
}





















