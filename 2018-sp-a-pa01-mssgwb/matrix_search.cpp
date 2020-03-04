#include "matrix_search.h"


void get_identity(string my_id[])
{
  // Define your function here
  my_id[0] = "Matthew Stroble";
  my_id[1] = "_";
  return;
}

char ** build_matrix(int rows, int cols)
{
  // Define your function here
  char **matrix = 0;
  matrix = new char *[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new char[cols];
  }

  return matrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
  // Define your function here
  for (int i = 0; i < rows; i++)
  {
    for (int k = 0; k < cols; k++)
    {
      cin >> matrix[i][k];
    }
  }
  return;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{


  // Define your function here
  //Const number for when word is not found
  const short WORD_NOT_FOUND = -1;

  bool wordFound = false;

  //valid direction
  bool dir0 = true;
  bool dir1 = true;
  bool dir2 = true;
  bool dir3 = true;
  bool dir4 = true;
  bool dir5 = true;
  bool dir6 = true;
  bool dir7 = true;

  //Word lend minus the inital character
  short wordLength = word.length() - 1;
  
  //Controls the main searching loops.
  short posX = 0;
  short posY = 0;

  short minBoundry = 0;
  short maxBoundryX = cols - 1;
  short maxBoundryY = rows - 1;

  char firstLetter = word[0]; 

  do
  {
    posX = 0;
    do
    {
      if (matrix[posY][posX] == word[0])
      {
        //Reset direction check
        dir0 = true;
        dir1 = true;
        dir2 = true;
        dir3 = true;
        dir4 = true;
        dir5 = true;
        dir6 = true;
        dir7 = true;

        //Checking for valid direction
        if (((posX - wordLength) < minBoundry) || 
          ((posY - wordLength) < minBoundry))
        {
          dir0 = false;
        }
        if ((posY - wordLength) < minBoundry)
        {
          dir1 = false;
        }
        if (((posX + wordLength) > maxBoundryX) || 
          ((posY - wordLength) < minBoundry))
        {
          dir2 = false;
        }
        if (posX + wordLength > maxBoundryX)
        {
          dir3 = false;
        }
        if (posX + wordLength > maxBoundryX || 
          posY + wordLength > maxBoundryY)
        {
          dir4 = false;
        }
        if (posY + wordLength > maxBoundryY)
        {
          dir5 = false;
        }
        if (posX - wordLength < minBoundry || 
          posY + wordLength > maxBoundryY)
        {
          dir6 = false;
        }
        if (posX - wordLength < minBoundry)
        {
          dir7 = false;
        }

        //searching valid directions
        if (dir0 == true)
        {
          if (word[wordLength] == matrix[posY - wordLength][posX - wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY - k][posX - k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY - k;
                sol[3] = posX - k;
              }
            }
          }
        }

        if (dir1 == true)
        {
          if (word[wordLength] == matrix[posY - wordLength][posX])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY - k][posX])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY - k;
                sol[3] = posX;
              }
            }
          }
        }

        if (dir2 == true)
        {
          if (word[wordLength] == matrix[posY - wordLength][posX + wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY - k][posX + k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY - k;
                sol[3] = posX + k;
              }
            }
          }
        }

        if (dir3 == true)
        {
          if (word[wordLength] == matrix[posY][posX + wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY][posX + k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY;
                sol[3] = posX + k;
              }
            }
          }
        }

        if (dir4 == true)
        {
          if (word[wordLength] == matrix[posY + wordLength][posX + wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY + k][posX + k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY + k;
                sol[3] = posX + k;
              }
            }
          }
        }

        if (dir5 == true)
        {
          if (word[wordLength] == matrix[posY + wordLength][posX])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY + k][posX])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY + k;
                sol[3] = posX;
              }
            }
          }
        }

        if (dir6 == true)
        {
          if (word[wordLength] == matrix[posY + wordLength][posX - wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY + k][posX - k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY + k;
                sol[3] = posX - k;
              }
            }
          }
        }

        if (dir7 == true)
        {
          if (word[wordLength] == matrix[posY][posX - wordLength])
          {
            for (short k = 1; k <= wordLength; k++)
            {
              if (word[k] != matrix[posY][posX - k])
                break;

              if (k == wordLength)
              {
                wordFound = true;
                sol[0] = posY;
                sol[1] = posX;
                sol[2] = posY;
                sol[3] = posX - k;
              }
            }
          }
        }

      }//End of first letter check
      posX += 1;
    } while (!wordFound && posX < cols); //End of Col check
    posY += 1;
  } while (!wordFound && posY < rows);

  if (!wordFound)
  {
    sol[0] = WORD_NOT_FOUND;
    sol[1] = WORD_NOT_FOUND;
    sol[2] = WORD_NOT_FOUND;
    sol[3] = WORD_NOT_FOUND;
  }

  return;
}


void print_matrix(int rows, int cols, char **matrix)
{
  // Define your function here
  for (int i = 0; i < rows; i++)
  {
    for (int k = 0; k < cols; k++)
    {
      cout << matrix[i][k] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return;
}


void delete_matrix(int rows, char **matrix)
{
  // Define your function here
  for (short i = 0; i < rows; i++)
  {
    delete [] matrix[i];
  }
  delete[] matrix;
  matrix = NULL;
  return;
}
