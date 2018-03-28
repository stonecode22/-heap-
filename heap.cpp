#include"heap.h"

heap::heap()
{
  array = new int[100]; //constructor to build a new array with 100 max elements
  length = 0; //sets length to 0 on default when array = NULL;
}

heap::~heap()
{
  delete[] array;
  length = 0;
}

int heap::parent(int index)
{
  return ((index-1)/2); //returns the parent of a child "index"
}

int heap::right(int index)
{
  return (2*index + 2); //returns the right child of a parent "index"
}

int heap::left(int index)
{
  return (2*index + 1); //returns the left child of a parent "index"
}

int heap::getMax()
{
  return array[0]; //returns first value (max value in max heap)
}

int heap::insert(int data)
{
  if(length >= 100) //if length of array surpasses 100 int limit
    {
      cout << "Out of storage!\n";
      return 0;
    }
  else //if array is not full
    {
      array[length] = data;
      length++;
      int number = length-1;
      while(number != 0 && array[number] > array[parent(number)])
	{
	  swapData(&array[number], &array[parent(number)]);
	  number = parent(number);
	}
      return 1;
    }
}

void heap::swapData(int* ele1, int *ele2)
{
  int temp = *ele1;
  *ele1 = *ele2;
  *ele2 = temp;
}
  
void heap::display()
{
  for(int i = 0; i < length; i++) //prints data in array
    {
      cout << array[i] << " ";
    }
}
 
int heap::remove(int data)
{
  increaseElement(data);
  changeMax();
}

void heap::increaseElement(int data)
{
  array[data] = INT_MAX;
  while(data != 0 && array[data] > array[parent(data)])
    {
      swapData(&array[data], &array[parent(data)]);
      data = parent(data);
    }
}

int heap::changeMax()
{
  if(length == 1)
    {
      length = length -1;
      return 1;
    }
  else if(length <= 0)
    {
      return 0;
    }
  else
    {
      array[0] = array[length-1];
      length = length-1;
      fixTree(0);
    }
}

void heap::fixTree(int index)
{
  int l = left(index);
  int r = right(index);
  int root = index;
  
  if(l < length && array[root] < array[l])
    {
      root = l;
    }
  if(r < length && array[root] < array[r])
    {
      root = r;
    }
  if(root != index)
    {
      dataSwap(&array[root], &array[index]);
      fixTree(root);
    }
}
