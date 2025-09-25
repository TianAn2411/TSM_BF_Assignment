
#include <iostream>
#include <string>

using namespace std;

void BF(int G[30][30], int numberOfVertices, char startVertex, int Label[30],int Prev[30]);
string BF_Path(int G[30][30], int numberOfVertices, char startVertex,char goalVertex);
