#include<fstream>
#include"heap.h"

bool getFileData(heap* list, bool* valid);
bool getConsoleData(heap* list, bool* valid);

int main()
{
  heap list; //constructor builds an array and initializes length
  char readChoice1[10]; //choice for Phase 1
  char readChoice2[10]; //choice for Phase 2
  bool valid = true; //loop status for Phase 1
  bool repeat = true; //loop status for Phase 2
  
  cout << "Max Heap:\n";

  //Phase 1
  //Purpose: Get inputs from user using a file or console
  do
    {
      cout << "Input data using FILE or CONSOLE.\n"; //prompts user input to use a file or directly input through the console
      cin.getline(readChoice1, 10);
      
      for(int i = 0; i < strlen(readChoice1); i++) //ignore case-sensitivity
	{
	  readChoice1[i] = toupper(readChoice1[i]);
	}
      
      if(strcmp(readChoice1, "FILE") == 0) //if choose file
	{
	  getFileData(&list, &valid);
	}
      
      else if(strcmp(readChoice1, "CONSOLE") == 0) //if choose console
	{
	  getConsoleData(&list, &valid);
	  cin.ignore();
	}
      else //if none of the above, loop back
	{
	  cout << "Invalid command, try again.\n";
	  valid = false; //set valid to false to repeat
	}
    }while (valid == false); //loops when valid is false
  
  cout << "Display:\n";
  list.display(); //display the tree

  //Phase 2
  //Purpose: Gets additional user input to insert, remove, or display
  while(repeat == true)
    {
      int number = 0;
      cout << "\nINSERT into heap, REMOVE from heap, DISPLAY the heap, or QUIT.\n";
      cin.getline(readChoice2, 10);
      
      for(int i = 0; i < strlen(readChoice2); i++) //ignore case-sensitivity
	{
	  readChoice2[i] = toupper(readChoice2[i]);
	}
      
      if(strcmp(readChoice2, "INSERT") == 0) //if insert
	{
	  cout << "Add a number into the heap: ";
	  cin >> number;
	  cin.ignore();
	  list.insert(number); //insert number into tree
	}
      else if(strcmp(readChoice2, "REMOVE") == 0) //if remove
	{
	  cout << "Delete a number from the heap: ";
	  cin >> number;
	  cin.ignore();
	  list.remove(number); //remove number
	}
      else if(strcmp(readChoice2, "DISPLAY") == 0)
	{
	  list.display(); //display tree
	}
      else if(strcmp(readChoice2, "QUIT") == 0)
	{
	  repeat = false; //end while loop
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
  cin.getline(fileName, 50); //user input file name
  file.open(fileName);

  if(!file.is_open()) //if file doesn't exist
    {
      cout << "Cannot find file.\n";
      *valid = false; //loop in main
      return valid;
    }
  else
    {
      if(file) //if there is a file
	{
	  file >> value;
	  file.ignore();
	}
      while(!file.eof() && file) //if not the end of the file, and it exists
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
  bool terminate = false; //end input early
  cout << "Enter data, separated by spaces (end using '-1'):\n";
  while(i < 100 && terminate == false) //maximum of 100 numbers
  {
    cin >> temp[i]; //user input
    list->insert(temp[i]); //insert into tree
    if(temp[i] == -1) //if the user inputs '-1', exit loop
      {
	terminate = true; //exits loop
	list->remove(-1); //removes -1 from the tree
      }
    i++; //repeats input session
  }
  *valid = true;
  return valid;
}
