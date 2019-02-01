#pragma once 


#include <vector>
#include <iostream>

template<class T>
class max
{
  public:
    bool operator()(const T& t1,const T& t2)
    {
      
      return t1 < t2;
    }
};

template<class T>
class min
{
  public:
    bool operator()(const T& t1,const T& t2)
    {
      return t1 > t2;
    }
};



template<class T,class Container=std::vector<T>,class Cmp=max<T> >
class Heap
{
  private: 
    Container con;  
    Cmp cmp;
  public:
    void Insert(const T& d)
    {
      con.push_back(d);
      AjustUp(con.size()-1);
    }

    void Pop()
    {
      if(con.size() > 0)
      {
       con[0]=con[con.size()-1];
       con.pop_back();
       AjustDown(0);
      }               

    }

    //堆顶
    T Top()
    {
      if(con.size()!=0)
      return con[0];
        return T();
    }

    int Size()
    {
      return con.size();
    }

    void AjustDown(int index)
    {
        int parent = index;
        int child = parent*2+1;
        int size = con.size();
        while(child < size )
        {
          if(child + 1 < size && cmp(con[child+1],con[child]) )
          {
            child++;
          }
          if(cmp(con[child],con[parent]))
          {
            T tmp = con[child];
            con[child] = con[parent];
            con[parent] = tmp;
          }
          else 
          {
            break;
          }
          parent = child;
          child = parent*2+1;
        }
    }

    void AjustUp(int index)
    {
        int child = index;
        int parent = (child-1)/2;
        int size = con.size();
        //防止越界问题
        while(child > 0)
        {
          if(child + 1 < size && cmp(con[child+1],con[child]) )
          {
            child++;
          }
          if(cmp(con[child],con[parent]))
          {
            T tmp = con[child];
            con[child] = con[parent];
            con[parent] = tmp;
          }
          else 
          {
            break;
          }
          child = parent;
          parent = (child-1)/2;
        }
    }
    
    void Print()
    {
      auto it=con.begin();
      for(;it!=con.end();++it)
      {
          std::cout<<*it<<std::endl;
      }  
    }
};
