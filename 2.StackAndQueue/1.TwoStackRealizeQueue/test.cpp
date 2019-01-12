#include "TwoStackRealizeQueue.hpp"
#include <iostream>

using namespace std;


void Test1()
{
  TwoStackToQueue<int> q1;
  cout<<q1.Front()<<endl;
  cout<<q1.Back()<<endl;
  q1.Push(1);
  q1.Push(2);
  q1.Push(3);
  q1.Push(4);
  q1.Push(5);
  cout<<q1.Front()<<endl;
  cout<<q1.Back()<<endl;
  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();
  q1.Pop();

  q1.Pop();
  
}

int main()
{
  Test1();
  return 0;
}
