#include "matrix_search.h"
#include <stdio.h>
#include <fstream>

int main()
{

  // Write your main here.
  //output to txt file
  const bool OUTPUT_TO_FILE = false;
  const short WORD_NOT_FOUND = -1;
  string input;
  int solutionLocations[4] = { -1, -1, -1, -1};
  int programLoop = 0;
  int rowCount = 0;
  int columCount = 0;
  char** matrixArray = 0;
  string keyWord;


  std::ofstream fout;

  if (OUTPUT_TO_FILE)
  {
    fout.open("my_output.txt");
  }
 
  cin >> programLoop;
  
  for (short i = 0; i < programLoop; i++)
  {
    //taking in row count
    cin >> rowCount;

    //taking in colum count
    cin >> columCount;

    //Building 2darray for matrix
    matrixArray = build_matrix(rowCount, columCount);

    //Filling matrix with data
    fill_matrix(rowCount, columCount, matrixArray);

    //Getting keyword
    cin >> keyWord;

    //Printing matrix
    //print_matrix(rowCount, columCount, matrixArray);

    //Searching matrix
    matrix_search(solutionLocations, keyWord, rowCount,
      columCount, matrixArray);


    cout << "Searching for " << "\"" << keyWord << "\" " 
      << "in matrix " << i + 1 << " yields:" << endl;

    if (solutionLocations[0] > WORD_NOT_FOUND)
    {
      cout << "Start pos:(" << solutionLocations[0] << ", " 
        << solutionLocations[1] << ") to End pos:(" << solutionLocations[2] 
        << ", " << solutionLocations[3] << ")" << endl << endl;
    }
    else
    {
      cout << "The pattern was not found." << endl << endl;
    }

    //Writing to file
    if (OUTPUT_TO_FILE == true)
    {
      fout << "Searching for " << "\"" << keyWord << "\" " 
        << "in matrix " << i + 1 << " yields:" << endl;
      if (solutionLocations[0] > WORD_NOT_FOUND)
      {
        fout << "Start pos:(" << solutionLocations[0] << ", " 
          << solutionLocations[1]
          << ") to End pos:(" << solutionLocations[2] << ", " 
          << solutionLocations[3] << ")" << endl << endl;
      }
      else
      {
        fout << "The pattern was not found." << endl << endl;
      }
    }
    //Deleting Array
    delete_matrix(rowCount, matrixArray);

  }

  if (OUTPUT_TO_FILE)
  {
    fout.close();
  }

  return 0;
}
