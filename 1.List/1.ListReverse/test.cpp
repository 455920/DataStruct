#include "ListNode.hpp"


//非递归方法
void TestReserveNR()
{
  pNode pRoot=NULL;
  BackPush(&pRoot,1);
  BackPush(&pRoot,2);
  BackPush(&pRoot,3);
  Print(pRoot);
  ListReserveNR(&pRoot);
  Print(pRoot);
}

void TestReserveR()
{
  pNode pRoot=NULL;
  BackPush(&pRoot,1);
  BackPush(&pRoot,2);
  BackPush(&pRoot,3);
  Print(pRoot);
  ListReserveR(&pRoot,pRoot);
  Print(pRoot);
}


int main()
{
  //TestReserveNR();
  TestReserveR();
  return 0;
}
