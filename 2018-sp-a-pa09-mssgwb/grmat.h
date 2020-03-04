// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Include this file to access Graph representation implemented using an
// Adjacency Matrix.

#include <stdio.h>
#include <ctype.h>

// Used by the mark array
#define UNVISITED 0
#define VISITED 1
#include "functions.h"
#include "graph.h"


using std::cin;
using std::endl;
using std::cout;

// Implementation for the adjacency matrix representation
class Graphm : public Graph
{
private:
  int numVertex;
  int numEdge; // Store number of vertices, edges
  float **matrix;           // Pointer to adjacency matrix
  int *mark;              // Pointer to mark array

public:
  // Constructor
  Graphm(int numVert)
  {
    Init(numVert);
  }

  // Destructor
  ~Graphm()
  {
    for (int i = 0; i < numVertex; i++)
    {
      delete[] matrix[i];
    }

    delete[] matrix;
    delete[] mark; // Return dynamically allocated memory
  }

  // Initialize the graph
  void Init(int n)
  {
    int i;
    numVertex = n;
    numEdge = 0;
    mark = new int[n];     // Initialize mark array

    for (i = 0; i < numVertex; i++)
    {
      mark[i] = UNVISITED;
    }

    // Make matrix
    // Do we really need to typecast here?
    // It does not obviously break anything...
    matrix = new float *[numVertex];

    for (i = 0; i < numVertex; i++)
    {
      matrix[i] = new float[numVertex];
    }

    for (i = 0; i < numVertex; i++) // Initialize to 0 weights
    {
      for (int j = 0; j < numVertex; j++)
      {
        matrix[i][j] = 0;
      }
    }
  }

  // Number of vertices
  int n()
  {
    return numVertex;
  }

  // Number of edges
  int e()
  {
    return numEdge;
  }

  // Return first neighbor of "v"
  int first(int v)
  {
    for (int i = 0; i < numVertex; i++)
    {
      if (matrix[v][i] != 0)
      {
        return i;
      }
    }
    return numVertex;           // Return n if none
  }

  // Return v's next neighbor after w
  int next(int v, int w)
  {
    for (int i = w + 1; i < numVertex; i++)
    {
      if (matrix[v][i] != 0)
      {
        return i;
      }
    }
    return numVertex;           // Return n if none
  }

  // Set edge (v1, v2) to "wt"
  void setEdge(int v1, int v2, float wt)
  {
    //Assert(wt > 0, "Illegal weight value");

    if (matrix[v1][v2] == 0)
    {
      numEdge++;
    }

    matrix[v1][v2] = wt;
  }

  void delEdge(int v1, int v2)
  { // Delete edge (v1, v2)
    if (matrix[v1][v2] != 0)
    {
      numEdge--;
    }
    else
      cout << "Edge did not exist" << endl;

    matrix[v1][v2] = 0;
  }

  bool isEdge(int i, int j) // Is (i, j) an edge?
  {
    return matrix[i][j] != 0;
  }

  float weight(int v1, int v2)
  {
    return matrix[v1][v2];
  }

  int getMark(int v)
  {
    return mark[v];
  }

  void setMark(int v, int val)
  {
    mark[v] = val;
  }




};
