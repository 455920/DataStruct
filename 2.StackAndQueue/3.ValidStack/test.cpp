#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class T>
bool IsValidStack(vector<T>& v1,vector<T>& v2)//v1是入栈顺序，v2是出栈顺序
{
  //长度不一样肯定不合法
  if(v1.size()!=v2.size())
    return false;
  int j=0;
  stack<int> s1;
  for(int i=0;i<v1.size();i++)
  {
    s1.push(v1[i]); 
    //每次先入栈，再判断是否有出栈可能
    while(!s1.empty()&&s1.top()==v2[j])
    {
      s1.pop();
      j++;
    }
  }  
  if(s1.empty())
    return true;
  else 
    return false;
}

int main()
{
  vector<int> v1;
  vector<int> v2;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(3);
  v2.push_back(1);
  v2.push_back(2);
  cout<<IsValidStack(v1,v2)<<endl;
  return 0;
}
