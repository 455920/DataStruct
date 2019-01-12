#include "TwoQueueRealizeStack.hpp"
#include <iostream>
using namespace std;

void Test1()
{
  TwoQueueRealizeStack<int> s1;
  s1.Push(1);
  cout<<s1.Top()<<endl;
  s1.Push(2);
  cout<<s1.Top()<<endl;
  s1.Push(3);
  cout<<s1.Top()<<endl;
  s1.Push(4);
  cout<<s1.Top()<<endl;
  s1.Push(5);
  cout<<s1.Top()<<endl;
  s1.Push(6);
  cout<<s1.Top()<<endl;
  s1.Pop();
  cout<<s1.Top()<<endl;
  s1.Pop();
  cout<<s1.Top()<<endl;
  s1.Pop();
  cout<<s1.Top()<<endl;
  s1.Pop();
}

int main()
{ 
  Test1(); 
  return 0;
}
