#ifndef TSM_H
#define TSM_H
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

void rewriteMatrix (int G[30][30], int n);
void DP (int G[30][30], int start, int current, int mask, int n,
        vector<vector<int>>& prevVertex, vector<vector<int>>& minCost);
string Traveling(int G[30][30], int N, char start);
#endif