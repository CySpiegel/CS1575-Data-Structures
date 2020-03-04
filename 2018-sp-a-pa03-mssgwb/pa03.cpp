#include "maze.h"

int main()
{
  short mapCount = 0;
  int rows = 1;
  int cols = 1;
  int startRow = 0;
  int startCol = 0;
  string *matrixArray;

  cin >> rows;
  cin >> cols;

  while (rows != 0 && cols != 0)
  {

    //getting rows
    cin.clear();
    cin.ignore();

    matrixArray = build_matrix(rows);
    fill_matrix(matrixArray, rows);
    find_start(matrixArray, rows, startCol, startRow);
	cout << "Start Found at: "<< startRow << " " << startCol << endl;
    //Start recursion here
    if (find_exit(matrixArray, startCol, startRow))
    {
      cout << "Map " << mapCount << " -- Solution found:" << endl;
    }
    else
    {
      cout << "Map " << mapCount << " -- No solution found:" << endl;
    }
    print_matrix(matrixArray, rows);
    delete_matrix(matrixArray, rows);
    mapCount++;

    cin >> rows;
    cin >> cols;
  }

  return 0;
}

