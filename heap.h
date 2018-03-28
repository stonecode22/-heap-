#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<string.h>
using namespace std;

class heap
{
 public:
  heap();
  ~heap();
  void swapData(int*, int*);
  int insert(int data);
  int remove(int data);
  void increaseElement(int data);
  int changeMax();
  void fixTree(int index);
  void display();
  int parent(int index);
  int right(int index);
  int left(int index);
  int getMax();
 private:
  int *array;
  int length;
};

#endif
