#include "maze.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;


void get_identity(string my_id[])
{
  my_id[0] = "Matthew Stroble";
  my_id[1] = "_";
}


string * build_matrix(int rows)
{
  string *matrix;
  matrix = new string[rows];
  return matrix;
}


void fill_matrix(string *matrix, int rows)
{

  for (short i = 0; i < rows; i++)
  {
    std::getline(cin, matrix[i], '\n');
  }
}


void print_matrix(string *matrix, int rows)
{
  for (short i = 0; i < rows; i++)
  {
    cout << matrix[i] << endl;
  }
  cout << endl;
}


void delete_matrix(string *matrix, int rows)
{
  delete[] matrix;
}


void find_start(string *matrix, int rows, int &x, int &y)
{
  bool startFound = false;
  for (short searchRow = 0; searchRow < rows; searchRow++)
  {
    for (short searchCol = 0; searchCol < matrix[searchRow].length(); searchCol++)
    {
      if (matrix[searchRow][searchCol] == 'N')
      {
        y = searchRow;
        x = searchCol;
        startFound = true;
        break;
      }
    }
    if (startFound)
      break;
  }
}



bool find_exit(string *matrix, int x, int y)
{
  //Base condition
  if ((at_end(matrix, x, y)))
  {
    return true;
  }
  else
  {
    if(matrix[y][x] != 'N')
      matrix[y][x] = '@';

    //checking north
    if (valid_move(matrix, x, y - 1, NORTH))
    {
      if (find_exit(matrix, x, y - 1))
      {       
        return true;
      }
    }
    //Checking East
    if (valid_move(matrix, x + 1, y, EAST))
    {
      if (find_exit(matrix, x + 1, y))
      {
        return true;
      }
    }

    //Checking south
    if (valid_move(matrix, x, y + 1, SOUTH))
    {
      if (find_exit(matrix, x, y + 1))
      {  
        return true;
      }
    }
    //Checking west
    if (valid_move(matrix, x - 1, y, WEST))
    {
      if (find_exit(matrix, x - 1, y))
      {
        return true;
      }
    }
    //Backtrack
    if (matrix[y][x] != 'N')
      matrix[y][x] = ' ';
    return false;
  }
}


bool at_end(string *matrix, int x, int y)
{
  bool targetFound = false;
  if (matrix[y][x] == 'E')
    targetFound = true;
  return targetFound;
}

bool valid_move(string *matrix, int x, int y, direction d)
{
  switch (d)
  {
  case NORTH:
    if (matrix[y][x] != '|' && matrix[y][x] != 'N' && matrix[y][x] != '@')
      return true;
    return false;
    break;
  case EAST:
    if (matrix[y][x] != '|' && matrix[y][x] != 'N' && matrix[y][x] != '@')
      return true;
    return false;
    break;
  case SOUTH:
    if (matrix[y][x] != '|' && matrix[y][x] != 'N' && matrix[y][x] != '@')
      return true;
    return false;
    break;
  case WEST:
    if (matrix[y][x] != '|' && matrix[y][x] != 'N' && matrix[y][x] != '@')
      return true;
    return false;
    break;
  }
}

