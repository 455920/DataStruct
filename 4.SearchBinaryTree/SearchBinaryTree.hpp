#include <iostream>

//搜索二叉树
template<class T>
struct SBTreeNode 
{
  SBTreeNode* left_;
  SBTreeNode* right_;
  T value_;
  SBTreeNode(const T&  v= T())
  :left_(NULL)
   ,right_(NULL)
   ,value_(v)
  {}
};


//搜索二叉树的左边小右边大
template<class T>
class SBTree 
{
  private:
    SBTreeNode<T>* pRoot_;//根节点
  typedef SBTreeNode<T>  Node;
  typedef SBTreeNode<T>* pNode;
  public:
    SBTree()
    {}

    pNode BuyNode(T value)
    {
        pNode tmp = new Node(value);
        return tmp;
    }

    //非递归方法插入 根据返回值判断插入成功与否
    bool InsertNR(T value)
    {
      if(pRoot_==NULL)
      {
        pRoot_ = BuyNode(value);
      }
      else 
      {
        pNode parent;
        pNode cur = pRoot_;
        //寻找一个最佳位置插入
        while(cur)
        {
          if(value < cur->value_)
          {
            parent = cur;
            cur=cur->right_;
          }
          else if(value > cur-> value_) 
          {
            parent =cur;
            cur=cur->left_;
          }
          else 
          {
            return false;//值相同，插入失败
          }
        }

        if(parent->left_==cur)
        {
          parent->left_ = BuyNode(value);
        }
        else 
        {
          parent->right_=BuyNode(value);
        }
    }
};

