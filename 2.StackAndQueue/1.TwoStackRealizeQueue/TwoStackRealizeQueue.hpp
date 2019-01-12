#include <stack>

using std::stack;

//两个栈实现一个队列 
template<class T>
class TwoStackToQueue
{
  private:
  stack<T>  s1;//用于放入数据，逆置的过程中要记得留一个
  stack<T>  s2;//用于把数据顺序逆置

  public:
  TwoStackToQueue()
  {
  }


  bool Empty()
  {
    if(s1.empty()&&s2.empty())
      return true;
    else 
      return false;
  }

  int Size()
  {
    return s1.size()+s2.size();
  }

  T Front()
  {
    //判断s2是否有数据，如果没有，就要进行一个数据的处理
    if(s2.empty())
    {
      while(!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    if(!s2.empty())
    return s2.top(); 
    else 
      return T();
  }

  T Back()
  {
    if(s1.empty())
    {
      while(!s2.empty())
      {
        s1.push(s2.top());
        s2.pop();
      }
    }
    if(!s1.empty())
      return s1.top();
    else 
      return T();
  }

  void Push(const T& value)
  {
      s1.push(value);
  }

  void Pop()
  {
    if(s2.empty()&&s1.empty())
      return;

    //如果s2为空就去s1搬数据到s2中，把s1中的数据逆置后放入s2中
    if(s2.empty())
    {
      while(!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    //经过上面的步骤如果s2不是空就直接删除s2的数据
    if(!s2.empty())
      s2.pop();
  }

};


