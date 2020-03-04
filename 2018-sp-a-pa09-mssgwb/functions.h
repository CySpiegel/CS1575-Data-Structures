#ifndef FUNCTIONS_HEADDER
#define FUNCTIONS_HEADDER



#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>



using std::cin;
using std::endl;
using std::cout;

#include "grmat.h"
#define INFINITY 9999





/*
Pre: (Vertex, distance)

*/

class Node
{
public:
  int vertex;
  float distance;
  float bribeCost;

  Node()
  {
    vertex = -1;
    distance = -1;
  }

  Node(int vert, float dist, float bribe)
  {
    vertex = vert;
    distance = dist;
    bribeCost = bribe;
  }

};

struct comparitor
{
public:
  bool operator()(Node& lhs, Node& rhs)
  {
    return lhs.distance > rhs.distance;
  }
};

struct sortByBribe
{
public:
  bool operator()(Node& lhs, Node& rhs)
  {
    return lhs.bribeCost > rhs.bribeCost;
  }
};



/*
Prereq: Must have an empty matrix and headder vectors and data piped via cin
Post: Will have filled the vectors with the data
*/
void userInput(std::vector<std::string> &headder, std::vector<std::vector<float>> &Matrix, std::vector<float> &bribeCost);

void getQuestion(std::vector<std::string> &fromTo);


void dijkstraSort(Graph *G, float *Distance, const std::vector<float> &Bribecost, std::vector<Node> &bribePath, int start);


void Gprint(Graph *G);

#include "functions.hpp"

#endif // !FUNCTIONS_HEADDER