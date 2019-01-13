#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#define DataType char

using std::stack;
typedef struct BinaryTreeNode
{
  struct BinaryTreeNode* left_;
  struct BinaryTreeNode* right_;
  DataType value_;
}*pTreeNode,TreeNode;



//创建一个二叉树的节点
pTreeNode BuyBinaryTreeNode(const DataType value)
{
    pTreeNode NewNode= (pTreeNode)malloc(sizeof(TreeNode));
    assert(NewNode);
    NewNode->value_=value;
    NewNode->left_=NULL;
    NewNode->right_=NULL;
    return NewNode;
}

//创建二叉树   '#'代表非法值
pTreeNode CreateBinaryTree(std::vector<char>& v,int& count)
{
    pTreeNode root=NULL;
    while(count<v.size()&&v[count]!='#')
    {
      root=BuyBinaryTreeNode(v[count]);
      ++count;
      root->left_=CreateBinaryTree(v,count);
      ++count;
      root->right_=CreateBinaryTree(v,count);
    }
    return root;

}


//递归前序遍历
void PreOrderPrintR(pTreeNode root)
{
  if(root==NULL)
    return;
  printf("%c ",root->value_);
  PreOrderPrintR(root->left_);
  PreOrderPrintR(root->right_);
}

//递归中序遍历
void InOrderPrintR(pTreeNode root)
{
  if(root==NULL)
    return;
  InOrderPrintR(root->left_);
  printf("%c ",root->value_);
  InOrderPrintR(root->right_);

}

//递归后序遍历
void PostOrderPrintR(pTreeNode root)
{
  if(root==NULL)
    return;
  PostOrderPrintR(root->left_);
  PostOrderPrintR(root->right_);

  printf("%c ",root->value_);
}



//非递归前序遍历
void PreOrderPrintNR(pTreeNode root)
{
  std::stack<pTreeNode> s1;//创建一个栈
  pTreeNode cur = root;
  while(cur||!s1.empty())
  {
    //找到每个节点的最左边
    while(cur)
    {
      printf("%c ",cur->value_);
      s1.push(cur);
      cur=cur->left_;
    }
    
    pTreeNode tmp = s1.top();
    if(tmp->right_)
    {
      cur = tmp->right_;
    }
    s1.pop();
  }
}

//非递归中序遍历
void InOrderPrintNR(pTreeNode root)
{
  std::stack<pTreeNode> s1;//创建一个栈
  pTreeNode cur = root;
  while(cur||!s1.empty())
  {
    //找到每个节点的最左边
    while(cur)
    {
      s1.push(cur);
      cur=cur->left_;
    }
    
    pTreeNode tmp = s1.top();
    printf("%c ",tmp->value_);
    if(tmp->right_)
    {
      cur = tmp->right_;
    }
    s1.pop();
  }
}

void PostOrderPrintNR(pTreeNode root)
{
  std::stack<pTreeNode> s1;//创建一个栈 
  pTreeNode cur = root;
  pTreeNode pre=NULL;//标记上一步所在位置
  while(cur||!s1.empty())
  {
    while(cur)
    {
      s1.push(cur);
      cur=cur->left_;
    }
    pTreeNode tmp = s1.top();
    if(tmp->right_&&tmp->right_!=pre)
    {
      cur=tmp->right_;
    }
    else 
    {
      printf("%c ",tmp->value_);
      pre = tmp;
      s1.pop();
    }
  } 
}


//二叉树的高度
int BinaryTreeHeight(pTreeNode root)
{
    if(root==NULL)
      return 0;
    int LeftHeight=BinaryTreeHeight(root->left_);//左子树的高度
    int RightHeight=BinaryTreeHeight(root->right_);//右子树的高度
    return LeftHeight>RightHeight? LeftHeight+1:RightHeight+1;//1表示本节点 
}

//求二叉树的第K层的节点个数
void BinaryTreeKth(pTreeNode root,int k,int& count)
{
    if(root==NULL)
      return;
    if(k==1)
      ++count;
    BinaryTreeKth(root->left_,k-1,count);
    BinaryTreeKth(root->right_,k-1,count);
}


//得到两个路劲
void BinaryTreeGetPath(pTreeNode root,
    stack<pTreeNode>& s,
    stack<pTreeNode>& s1,//
    stack<pTreeNode>& s2,//
    DataType ch1,//节点1的值
    DataType ch2)//节点2的值
{
  if(root==NULL)
    return;
  s.push(root);
  if(root->value_==ch1)
    s1=s;
  if(root->value_==ch2)
    s2=s;
  BinaryTreeGetPath(root->left_,s,s1,s2,ch1,ch2);
  BinaryTreeGetPath(root->right_,s,s1,s2,ch1,ch2);
  s.pop();
}
//求二叉树中两个节点的最近公共祖先节点
pTreeNode BinaryTreeCommonNode(pTreeNode root,DataType ch1,DataType ch2)
{
  stack<pTreeNode>  s;
  stack<pTreeNode>  s1;
  stack<pTreeNode>  s2;
  BinaryTreeGetPath(root,s,s1,s2,ch1,ch2);

 if(s1.size()>s2.size())
 {
   while(s1.size()!=s2.size())
     s1.pop();
 }
 else 
 {
   while(s1.size()!=s2.size())
   s2.pop();
 }
 
 while(s1.top()!=s2.top())
 {
   s1.pop();
   s2.pop(); 
 }
 return s1.top();
}

