#include <queue>


//两个队列实现一个栈
//插入的时候插入已经有数据的队列
//Pop的时候就把有数据的队列的数据都放入另一个队列，最后要留下一个数据，就是应该被Pop的数据
template<class T>
class TwoQueueRealizeStack
{
    private:
      std::queue<T> q1;
      std::queue<T> q2;
    public:
      void Push(const T& value)
      {
        if(!q1.empty()) 
        {
          q1.push(value);
        }
        else 
        {
          q2.push(value);
        }
      }

      void Pop()
      {
        if(!q1.empty())
        {
          while(q1.size()>1) 
          {
            q2.push(q1.front());
            q1.pop();
          }
          //q1留下的最后一个数据就是最先插入的一个数据
          q1.pop();
        }
        else if(!q2.empty())
        {
          while(q2.size()>1)
          {
            q1.push(q2.front());
            q2.pop();
          }
          q2.pop();
        }
        else 
        {

        }
      }

      T Top()
      {
        if(!q1.empty())
        {
          return q1.back();
        }
        else if(!q2.empty())
        {
          return q2.back();
        }
        else 
        {
          return T();
        }
      }
        
      void Size()
      {
        return q1.size()+q2.size();
      }

      bool Empty()
      {
        if(q1.empty()&&q2.empty())
        {
          return true;
        }
        else 
        {
          return false;
        }
      }
};
