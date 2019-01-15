#include "SearchBinaryTree.hpp"


void TestInsertNR()
{
  SBTree<int> tree;
  tree.InsertNR(1);
  tree.InsertNR(10);
  tree.InsertNR(4);
  tree.InsertNR(6);
  tree.InsertNR(2);
  tree.InsertNR(8);
  tree.InsertNR(0);
  tree.InOrderPrint();
}

void TestInsertR()
{
  SBTree<int> tree;
  tree.InsertR(1);
  tree.InsertR(10);
  tree.InsertR(4);
  tree.InsertR(6);
  tree.InsertR(2);
  tree.InsertR(8);
  tree.InsertR(0);
  tree.InOrderPrint();
}

void TestFind()
{
  SBTree<int> tree;
  tree.InsertR(1);
  tree.InsertR(10);
  tree.InsertR(4);
  tree.InsertR(6);
  tree.InsertR(2);
  tree.InsertR(8);
  tree.InsertR(0);
  SBTreeNode<int>* tmp = tree.Find(8);
  if(tmp)
  {
    std::cout<<tmp->value_<<std::endl;
  }
  else 
  {
   std::cout<<"no find"<<std::endl;
  }
}


void TestRemove() 
{
  SBTree<int> tree;
  tree.InsertR(1);
  tree.InsertR(10);
  tree.InsertR(4);
  tree.InsertR(6);
  tree.InsertR(2);
  tree.InsertR(8);
  tree.InsertR(0);
  tree.InOrderPrint();
  std::cout<<"----"<<std::endl;
  tree.RemoveR(4);
  tree.InOrderPrint();
}

int main()
{
  //TestInsertNR(); 
  //TestInsertR(); 
  //TestFind();
  TestRemove();
  return 0;
}
