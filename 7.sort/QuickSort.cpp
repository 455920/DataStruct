#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;


//挖坑法
int PartSort1(int a[],int left,int right)
{
  int tmp = a[left]; 
  while(left < right)
  {
    while(left < right && a[right] >= tmp ) right--;
    a[left] = a[right];
    while(left < right && a[left] <= tmp ) left++;
    a[right]  = a[left];
  }
  a[left] = tmp;
  return left;
}

//左右指针法
int PartSort2(int a[],int left ,int right)
{
  //保存基准值的下标
  int index = left;
  while(left < right)
  {
    //最后一次交换完成后right肯定会指向比index位置小的值
      while(left < right && a[right] >= a[index] ) right--;
      while(left < right && a[left] <= a[index] ) left++;
      std::swap(a[left],a[right]);
  }
  std::swap(a[left],a[index]);
  return left;
}


//左右指针法
int PartSort3(int a[],int left ,int right)
{
  //保存基准值的下标
  int index = right;
  int pre = left-1;
  int cur = left;
  while(cur < right) 
  {
    //满足条件表示遇到一个可以添坑的值
    if(a[cur] < a[index])
    {
      ++pre;
      if(pre != cur)//如果pre++后等于cur,说明没有必要挖坑
      std::swap(a[cur],a[pre]);
    }
    //cur++的过程就好想留了许许多多的坑一样,pre++就相对于挖了这么多坑，能填多少坑
    //最后填的那个坑的位置就是index应该所在的位置
    cur++;
  }
  std::swap(a[pre+1],a[cur]);
  return pre+1;
}

void QuickSort1(int a[],int left,int right)
{
  if(left < right)
  {
    int div  = PartSort1(a,left,right); 
    QuickSort1(a,left,div-1);
    QuickSort1(a,div+1,right);
  }
}

void QuickSort2(int a[],int left, int right)
{
  if(left < right)
  {
    int div = PartSort2(a,left,right);
    QuickSort2(a,left,div-1);
    QuickSort2(a,div+1,right);
  }
}

void QuickSort3(int a[],int left, int right)
{
  if(left < right)
  {
    int div = PartSort3(a,left,right);
    QuickSort3(a,left,div-1);
    QuickSort3(a,div+1,right);
  }
}

int main()
{
  int a[]={5,2,6,8,13,62,7,64,3};
  int len = sizeof(a)/sizeof(a[0]);
//  QuickSort1(a,0,len-1);
 // QuickSort2(a,0,len-1);
  QuickSort3(a,0,len-1);
  for(int i=0;i < len; i++)
  {
   cout<<a[i]<<" "; 
  }
  cout<<endl;
  return 0;
}
