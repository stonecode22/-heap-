#include"heap.h"

heap::heap()
{
  array = new int[100]; //constructor to build a new array with 100 max elements
  length = 0; //sets length to 0 on default when array = NULL;
}

heap::~heap()
{
  delete[] array; //deconstructor to delete the array to prevent memory leak
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
      cout << "Out of storage!\n"; //post space warning message, do nothing
      return 0;
    }
  else //if array is not full
    {
      array[length] = data; //set array[length] to the user data input
      length++; //initially 0, increases with each element
      int number = length-1; //number = 0 for length = 1, as array[0] is length = 1
      while(number != 0 && array[number] > array[parent(number)]) //if array is not empty, and the array is larger than its parent...
	{
	  swapData(&array[number], &array[parent(number)]); //swap the data
	  number = parent(number); //swap the indexes
	}
      return 1;
    }
}

void heap::swapData(int* ele1, int *ele2) //swap function
{
  int temp = *ele1;
  *ele1 = *ele2;
  *ele2 = temp;
}

void heap::display() //incredibly inefficient, yet simple level display
{
  for(int i = 0; i < length; i++)
    {
      if(i == 0) //if index is 0
	{
	  cout << "1: " << array[i];
	}
      if(i < 3 && i > 0) //if index is within 1-2
	{
	  if(i == 1)
	    {
	      cout << "\n2: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
      if(i < 7 && i > 2) //if index is within 3-6
	{
	  if(i == 3)
	    {
	      cout << "\n3: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
      if(i < 15 && i > 6) //if index is within 7-14
	{
	  if(i == 7)
	    {
	      cout << "\n4: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
      if(i < 31 && i > 14) //if index is within 15-30
	{
	  if(i == 15)
	    {
	      cout << "\n5: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
      if(i < 63 && i > 30) //if index is within 31-62
	{
	  if(i == 31)
	    {
	      cout << "\n6: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
      if(i < 100 && i > 62) //if index is within 63-100 (max)
	{
	  if(i == 63)
	    {
	      cout << "\n7: " << array[i] << " ";
	    }
	  else
	  cout << array[i] << " ";
	}
    }
  cout << endl;
}

void heap::remove(int data)
{
  int index = 0;
  int duplicate = 0;
  while(index < length) //check all indexes in the array
    {
      if(array[index] == data && index < 100 && duplicate < 1) //find the index that hold the value
	{
	  increaseElement(index); //sets value in index to highest, swaps until it becomes array[0] (the top of the tree)
	  changeMax(); //
	  duplicate++; //only remove one index, not all indexes with matching "data"
	}
      index++;
    }
}

void heap::increaseElement(int index)
{
  array[index] = 1001; //make the value of array[index] the highest number in the tree (so it will be at array[0])
  while(index != 0 && array[index] > array[parent(index)]) //while index is not 0 and array[index] > than of its parent
    {
      swapData(&array[index], &array[parent(index)]); //swap the data and its parent's
      index = parent(index); //swap the index
    }
}

int heap::changeMax()
{
  if(length == 1) //if only one element in array (array[0])
    {
      length = length -1; //decrease length to have array hold no elements
      return 1;
    }
  else if(length <= 0) //if length is 0 or negative...
    {
      return 0; //do nothing
    }
  else //if length is positive and > 1...
    {
      array[0] = array[length-1]; //the number wanting to be deleted, now array[0] moves to the end of the array (array[length-1])
      length = length-1; //decrease the length, basically popping array[length-1] out of the array
      heapify(0); //orders array after deletion
    }
}

void heap::heapify(int index)
{
  int l = left(index);
  int r = right(index);
  int root = index;

  //for all cases, the indexes must be < length
  if(l < length && array[root] < array[l]) //if index's left child is greater than its parent
    {
      root = l; //set the index root to its left child
    }
  if(r < length && array[root] < array[r]) //if index's right child is greater than its parent
    {
      root = r; //set the index root to its right child
    }
  if(root != index) //if root doesn't = previous index
    {
      swapData(&array[root], &array[index]); //swap the data
      heapify(root); //recursively continue fixing the tree
    }
}
  
