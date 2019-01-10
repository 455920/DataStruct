#include "ComplexListCopy.hpp"


void TestPrint()
{
  pNode cpl=NULL; 
  pNode p1 = BuyNode(1); 
  pNode p2 = BuyNode(2); 
  pNode p3 = BuyNode(3); 
  pNode p4 = BuyNode(4); 
  pNode p5 = BuyNode(5);
  p1->Next_=p2;
  p2->Next_=p3;
  p3->Next_=p4;
  p4->Next_=p5;
  p5->Next_=NULL;
  p1->Rand_=p2;
  p2->Rand_=p4;
  p3->Rand_=p5;
  p4->Rand_=NULL;
  p5->Rand_=p1;
  cpl=p1;
  Print(cpl);
}

void TestCp()
{
  pNode cpl=NULL; 
  pNode p1 = BuyNode(1); 
  pNode p2 = BuyNode(2); 
  pNode p3 = BuyNode(3); 
  pNode p4 = BuyNode(4); 
  pNode p5 = BuyNode(5);
  p1->Next_=p2;
  p2->Next_=p3;
  p3->Next_=p4;
  p4->Next_=p5;
  p5->Next_=NULL;
  p1->Rand_=p2;
  p2->Rand_=p4;
  p3->Rand_=p5;
  p4->Rand_=NULL;
  p5->Rand_=p1;
  cpl=p1;
  Print(cpl);
  pNode newl = CpComplexList(cpl);
  Print(newl);
}

int main()
{
  //TestPrint(); 
  TestCp();
  return 0;
}
