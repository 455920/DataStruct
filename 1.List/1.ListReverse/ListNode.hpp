#pragma once 
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

#define DataType int


typedef struct ListNode
{
  DataType value_;
  struct ListNode* Next_;   
}Node,*pNode;

pNode BuyNode(DataType value)
{
  pNode cur=(pNode)malloc(sizeof(DataType));
  assert(cur);
  cur->value_=value;
  cur->Next_=NULL;
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
    cur->Next_==NULL;
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
    printf("%d->",root->value_);
    root=root->Next_;
  }
  printf("%d\n",root->value_);
}

//链表的逆置方法
//1.在创建一个链表
//略
//2.三指针非递归法
void ListReserveNR(pNode* pRoot)
{
  pNode cur1;
  pNode cur2;
  pNode cur3;
  assert(pRoot);
  //只有一个节点不需要逆置
  if(*pRoot==NULL&&(*pRoot)->Next_==NULL)
  {
    return;
  }
  cur1=*pRoot;
  cur2=cur1->Next_;
  cur3=cur2->Next_;
  cur1->Next_=NULL;
  while(cur2)
  {
    cur2->Next_=cur1;
    cur1=cur2;
    cur2=cur3;
    if(cur3)
    {
      cur3=cur3->Next_;
    }
  }
  *pRoot=cur1;
}


//3.递归方法
void ListReserveR(pNode* pRoot,pNode root)
{
  if(root==NULL||root->Next_==NULL)
  {
    *pRoot=root;
    return;
  }
  ListReserveR(pRoot,root->Next_);
  root->Next_->Next_=root;
  root->Next_=NULL;
}
