#include <iostream>
#include "Heap.hpp"



void PrintS( Heap<int,std::vector<int>,min<int> > h)
{
  while(h.Size() > 0)
  {
    std::cout<<h.Top()<<std::endl;
    h.Pop();
  }
}

int main()
{
 // Heap<int> h;
  Heap<int,std::vector<int>,min<int>> h;
  h.Insert(2);
  h.Insert(8);
  h.Insert(3);
  h.Insert(10);
  h.Insert(5);
  h.Insert(12);
  h.Insert(3);
  h.Insert(3);
  h.Insert(10);
  h.Insert(22);
//  h.Print();
  PrintS(h);
  return 0;
}
