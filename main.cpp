#include<fstream>
#include"heap.h"

bool getFileData(heap* list, bool* valid);
bool getConsoleData(heap* list, bool* valid);

int main()
{
  heap list;
  char readChoice1[10];
  char readChoice2[10];
  bool valid = true;
  bool repeat = true;
  
  cout << "Max Heap:\n";

  do
    {
      cout << "Input data using FILE or CONSOLE.\n";
      cin.getline(readChoice1, 10);
      
      for(int i = 0; i < strlen(readChoice1); i++)
	{
	  readChoice1[i] = toupper(readChoice1[i]);
	}
      
      if(strcmp(readChoice1, "FILE") == 0)
	{
	  getFileData(&list, &valid);
	}
      
      else if(strcmp(readChoice1, "CONSOLE") == 0)
	{
	  getConsoleData(&list, &valid);
	}
      else
	{
	  cout << "Invalid command, try again.\n";
	  valid = false;
	}
    }while (valid == false);
  cin.ignore();
  cout << "Display:\n";
  list.display();

  while(repeat == true)
    {
      int number = 0;
      cout << "\nINSERT into heap, REMOVE from heap, DISPLAY the heap, or QUIT.\n";
      cin.getline(readChoice2, 10);
      
      for(int i = 0; i < strlen(readChoice2); i++)
	{
	  readChoice2[i] = toupper(readChoice2[i]);
	}
      
      if(strcmp(readChoice2, "INSERT") == 0)
	{
	  cout << "Add a number into the heap: ";
	  cin >> number;
	  cin.ignore();
	  list.insert(number);
	}
      else if(strcmp(readChoice2, "REMOVE") == 0)
	{
	  cout << "Delete a number from the heap: ";
	  cin >> number;
	  cin.ignore();
	  list.remove(number);
	}
      else if(strcmp(readChoice2, "DISPLAY") == 0)
	{
	  list.display();
	}
      else if(strcmp(readChoice2, "QUIT") == 0)
	{
	  repeat = false;
	}
      else
	{
	  cout << "Invalid command, try again.\n";
	}
    }  
  return 0;
  
}


bool getFileData(heap* list, bool* valid)
{
  char fileName[50];
  int value;
  ifstream file;

  cout << "Enter the name of the file to use: ";
  cin.getline(fileName, 50);
  file.open(fileName);

  if(!file.is_open())
    {
      cout << "Cannot find file.\n";
      *valid = false;
      return valid;
    }
  else
    {
      if(file)
	{
	  file >> value;
	  file.ignore();
	}
      while(!file.eof() && file)
	{
	  list->insert(value);
	  file >> value;
	  file.ignore();
	}
      file.close();
      *valid = true;
      return valid;
    }
}

bool getConsoleData(heap* list, bool* valid)
{
  int temp[100];
  int i = 0;
  bool terminate = false;
  cout << "Enter data, separated by spaces (end using '-1'):\n";
  while(i < 100 && terminate == false)
  {
    cin >> temp[i];
    list->insert(temp[i]);
    if(temp[i] == -1)
      {
	terminate = true;
	list->remove(i);
      }
    i++;
  }
  *valid = true;
  return valid;
}
