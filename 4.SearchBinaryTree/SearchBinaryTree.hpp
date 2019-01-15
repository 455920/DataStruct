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
   :pRoot_(NULL)
  {}

 ~SBTree()
 {
   Destroy();
   std::cout<<"析构"<<std::endl;
 }

  void Destroy()
  {
   Destroy_(pRoot_); 
  }

  void Destroy_(pNode cur)
  {
    if(cur==NULL)
      return;
    Destroy_(cur->left_);
    Destroy_(cur->right_);
    delete cur;
  }

   pNode BuyNode(T value)
   {
       pNode tmp = new Node(value);
       tmp->left_=NULL;
       tmp->right_=NULL;
       return tmp;
   }


//递归插入
   bool InsertR(T value)
   {
     if(pRoot_==NULL)
     {
       pRoot_ = BuyNode(value);
       return true;
     }
    return  InsertR_(pRoot_,value);
   }

   bool InsertR_(pNode cur,T value)
   {
    
      if(value < cur->value_)
      {
        if(cur->left_==NULL)
        {
          cur->left_=BuyNode(value);
          return true;
        }
        else 
        {
          return  InsertR_(cur->left_,value);
        }
      }
      else if(value > cur->value_)
      {
        if(cur->right_==NULL) 
        {
          cur->right_=BuyNode(value);
          return true;
        }
        else 
        {
          return InsertR_(cur->right_,value);
        }
      }
      else 
      {
        return false;
      }
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
             cur=cur->left_;
           }
           else if(value > cur-> value_) 
           {
             parent =cur;
             cur=cur->right_;
           }
           else 
           {
             return false;//值相同，插入失败
           }
         }

         if(value < parent->value_)
         {
           parent->left_ = BuyNode(value);
         }
         else 
         {
           parent->right_=BuyNode(value);
         }
         return true;
      }      
    }
    

    //中序遍历
    void InOrderPrint()
    {
      InOrderPrint_(pRoot_);
    }
    void InOrderPrint_(pNode cur)
    {
        if(cur==NULL)
          return;
        InOrderPrint_(cur->left_);
        std::cout<<cur->value_<<std::endl;
        InOrderPrint_(cur->right_);
    }


    //搜索节点
    pNode Find(const T& value)
    {
      Find_(value,pRoot_);
    }
    pNode Find_(const T& value,pNode cur)
    {
      if(cur==NULL)
        return NULL;
      if(cur->value_==value)
        return cur;
      //去左子树中搜索
     pNode tmp =  Find_(value,cur->left_);
     if(tmp)
       return tmp;
      //去右子树中搜索
     return  Find_(value,cur->right_);
    }





    bool RemoveR(const T& value)
    {
        return RemoveR_(value,pRoot_);
    }
    //1.要删除的节点是叶子节点，直接删除
    //2.要删除的节点只有左子树，让它的左子树代替它的位置，然后删除它的左子树
    //3.要删除的节点只有右子树，让它的左子树代替它的位置，然后删除它的右子树
    //4.要删除的节点有左子树又有右子树，找到它的右子树的最左节点，然后与之交换值，然后递归删除改值即可
   bool RemoveR_(const T& value,pNode& cur)//传入指针本身
    {
       if(cur==NULL)
         return false;

        if(value < cur->value_)
        {
         return  RemoveR_(value,cur->left_);
        }
        else if(value > cur->value_)
        {
          return  RemoveR_(value,cur->right_);
        }
        else 
        {
          if(cur->left_==NULL&&cur->right_==NULL)
          {
            pNode del = cur;
            cur = NULL;
            delete del;
          }
          //有左无
          else if(cur->left_&&cur->right_==NULL)
          {
            pNode del = cur ;
            cur=cur->left_;
            delete del;
          }
          //无左有右
          else if(cur->right_&&cur->left_==NULL) 
          {
            pNode del =cur ;
            cur= cur->right_;
            delete del;
          }
          else 
          {
            //寻找右子树的最左子树
            pNode replace = cur->right_;
            while(replace->left_)
            {
              replace = replace->left_;
            }
            cur->value_=replace->value_;
            //递归删除
            return RemoveR_(replace->value_,cur->right_);
          }
          return true; 
        }
    }   
}; 
