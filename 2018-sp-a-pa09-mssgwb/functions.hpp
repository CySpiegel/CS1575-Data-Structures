#include "functions.h"

void userInput(std::vector<std::string> &headder, std::vector<std::vector<float>> &Matrix, std::vector<float> &bribeCost)
{
  std::string line;
  std::string myDigit;
  std::string word = "";
  std::vector<std::string> matrixLine;
  int count = 0;

  std::getline(cin, line);

  //Reding in Headder 
  for (long long i = 0; i < line.length(); i++)
  {
    if (line[i] != ',' && line[i] != '(' && line[i] != ')'
      && !isdigit(line[i]) && line[i] != ' ' && line[i] != '.')
    {
      word.push_back(line[i]);
    }

    if (isdigit(line[i]) || line[i] == '.')
    {
      myDigit.push_back(line[i]);
    }
    if (line[i] == ')')
    {
      bribeCost.push_back(std::stof(myDigit));
      myDigit = "";
    }

    if (line[i] == ',')
    {
      headder.push_back(word);
      count++;
      word = "";
    }
  }
  headder.push_back(word);
  word = "";

  //Printing Headder
  headder.erase(headder.begin());
  line = "";


  //Matrix numbers
  for (int i = 0; i < count; i++)
  {
    std::string row;
    std::getline(cin, row);

    for (int j = 0; j < row.length(); j++)
    {
      if (row[j] != ',')
        word.push_back(row[j]);

      if (row[j] == ',')
      {
        matrixLine.push_back(word);
        word = "";
      }
    }
    matrixLine.push_back(word);
    word = "";
    matrixLine.erase(matrixLine.begin());

    std::vector<float>column;
    for (auto it = matrixLine.begin(); it != matrixLine.end(); it++)
    {
      column.push_back(std::stof(*it));
    }
    Matrix.push_back(column);
    matrixLine.clear();
  }//end of for loop
  std::getline(cin, line);
}

void getQuestion(std::vector<std::string> &fromTo)
{
  std::string temp;
  std::string line;
  std::getline(cin, line);
  for (int i = 31; i < line.length(); i++)
  {
    if (line[i] != ' ')
    {
      temp.push_back(line[i]);
    }

    if (line[i + 1] == ' ' || line[i + 1] == '?')
    {
      temp.pop_back();
      fromTo.push_back(temp);
      temp = "";
    }
  }


  fromTo.erase(fromTo.begin() + 1);

}



//Add another vector for bribecosts
//change void to float to return bribe costs
//push nodes to priority que for sort by bribe cost

void dijkstraSort(Graph *G, float *Distance, const std::vector<float>&Bribecost, std::vector<Node> &bribePath, int start)
{
  int i, v, w;
  float tempBribeArr[G->n()];
  std::vector<float> tempBribe = Bribecost;

  Distance[start] = 0;
  tempBribe[start] = Bribecost[start];

  //Stores current node and weight
  Node temp;
  temp.distance = 0;
  temp.vertex = start;
  temp.bribeCost = 0;


  std::priority_queue<Node, std::vector <Node>, comparitor > pq;
  pq.push(temp);

  for (i = 0; i < G->n(); i++)
  {
    do
    {
      if (pq.size() == 0)
      {
        return;
      }
      temp = pq.top();
      v = temp.vertex;
      pq.pop();
      //bribePath.push_back(temp);

    } while (G->getMark(v) == VISITED);

    G->setMark(v, VISITED);

    if (Distance[v] == INFINITY)
    {
      return;
    }

    for (w = G->first(v); w < G->n(); w = G->next(v, w))
    {
      if (Distance[w] >= (Distance[v] + G->weight(v, w)))
      {
        Distance[w] = Distance[v] + G->weight(v, w);
        temp.distance = Distance[w];
        temp.vertex = w;
        //updating bribecosts
        tempBribe[w] = tempBribe[v] + Bribecost[w];
        temp.bribeCost = tempBribe[w];
        pq.push(temp);
        bribePath.push_back(temp);
      }
    }
  }
}

void Gprint(Graph *G)
{
  int i, j;

  cout << "==========Starting to print out your matrix==========\n\n";
  cout << "The number of vertices in your graph is:\n" << G->n() << "\n\n";
  cout << "The number of edges in your graph is:\n" << G->e() << "\n\n";

  cout << "A matrix view of your graph follows \n(even if it's a list backend):\n";
  for (i = 0; i < G->n(); i++)
  {
    for (j = 0; j < G->n(); j++)
    {
      cout << G->weight(i, j) << " ";
    }
    cout << "\n";
  }
  cout << "\n==========Finishing printing out your matrix==========\n\n";
}