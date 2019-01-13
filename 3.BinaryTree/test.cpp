#include "BinaryTree.hpp"
#include <vector>
using std::vector;

void TestCreateBinaryTree()
{
  vector<char> v;
  char arr[]={'A','B','D','#','#','#','C',  
  'E','#','#','F','#','#'};
  int len = sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<len;i++)
  {
    v.push_back(arr[i]);
  }
  int count=0;
  pTreeNode root = CreateBinaryTree(v,count);
  
  printf("递归\n");
  PreOrderPrintR(root);
  printf("\n");
  InOrderPrintR(root);
  printf("\n");
  PostOrderPrintR(root);
  printf("\n");
  printf("非递归\n");
  PreOrderPrintNR(root);
  printf("\n");
  InOrderPrintR(root);
  printf("\n");
  PostOrderPrintNR(root);
  printf("\n");
  printf("高度:%d\n",BinaryTreeHeight(root));
  count =0;
  BinaryTreeKth(root,3,count);
  printf("第%d层的节点个数:%d\n",3,count);

  pTreeNode pCommeNode = BinaryTreeCommonNode(root,'D','F');
  printf("公共节点值:%c \n",pCommeNode->value_);
}



int main()
{
  TestCreateBinaryTree();
  return 0;
}
