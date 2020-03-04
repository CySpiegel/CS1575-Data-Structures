#include "functions.h"

int main()
{

  std::vector<std::string> headder;
  std::vector<std::string> fromToCur;
  std::vector<float> bribeCost;
  std::vector<std::vector<float>> Matrix;
  Node answer;
  std::priority_queue<Node, std::vector <Node>, sortByBribe > pqAnswers;

  int startPos = 0;
  int endPos = 0;
  
  userInput(headder, Matrix, bribeCost);
  getQuestion(fromToCur);

  //setting start point
  for (int i = 0; i < headder.size(); i++)
  {
    if (fromToCur[0] == headder[i])
    {
      startPos = i;
    }

    if (fromToCur[1] == headder[i])
    {
      endPos = i;
    }

  }


  float vertCount = Matrix[0].size();
  Graph *MyGraph = new Graphm(vertCount);
  std::vector<Node> bribePath;



  for (int i = 0; i < vertCount; i++)
  {
    for (int k = 0; k < vertCount; k++)
    {
      MyGraph->setEdge(i, k, Matrix[i][k]);
    }
  }
 

  float Dist[MyGraph->n()];
  for (int i = 0; i < MyGraph->n(); i++)
  {
    Dist[i] = INFINITY;
  }


  dijkstraSort(MyGraph, Dist, bribeCost, bribePath, startPos);


  Node tempAnswer;
  for (int i = 0; i < bribePath.size(); i++)
  {
    if (bribePath[i].vertex == endPos && bribePath[i].distance == Dist[endPos])
    {
      pqAnswers.push(bribePath[i]);
    }
  }

  std::string curStart = headder[startPos].c_str();
  std::string curEnd = headder[endPos].c_str();
  curStart.push_back('s');
  curEnd.push_back('s');
  

  //Printing answer
  if (Dist[endPos] != INFINITY)
  {
    if (startPos != endPos)
    {
      answer = pqAnswers.top();
      cout << "The shortest path from " << curStart << " to " << curEnd << " is:" << endl;
      cout << curStart << ", " << curEnd << ", " << "with sum exchange cost of " << answer.distance << " and bribe cost of " << answer.bribeCost - bribeCost[endPos] << "." << endl;
    }
    else
    {
      answer = pqAnswers.top();
      cout << "The shortest path from " << curStart << " to " << curEnd << " is:" << endl;
      cout << curStart << ", " << curEnd << ", " << "with sum exchange cost of " << answer.distance << " and bribe cost of " << answer.bribeCost << "." << endl;
    }
  }
  else
  {
    cout << "There is no path from " << curStart << " to " << curEnd << "." << endl;
  }


  delete MyGraph;
  return 0;
}

