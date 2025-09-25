#include "../inc/tsm.h"

const int INF = numeric_limits<int>::max();
void rewriteMatrix (int G[30][30], int n){
    for (int i=0; i<n; i++){
        for (int j =0; j< n; j++){
            if (i != j && G[i][j] == 0){
                G[i][j] = INF/2;
            }
        }
    }
}
void DP (int G[30][30], int start, int current, int mask, int n,
        vector<vector<int>>& prevVertex, vector<vector<int>>& minCost){
  int is_Visited_all = (1<<n)-1;
  
  if (mask == is_Visited_all){
    minCost[mask][current] = G[current][start];
    return;
  }
  if (minCost[mask][current] != -1){
      return;
  }
  int min_cost = INF/2;
  for (int i = 0; i< n; i++){
    if ((mask&(1<<i))== 0 && G[current][i] > 0 && G[current][i] != INF/2){
        int next_mask = mask|(1<<i);
        DP(G, start, i, next_mask, n, prevVertex, minCost);
        int predict_min_cost = G[current][i] + minCost[next_mask][i];
        if (predict_min_cost < min_cost){
            min_cost= predict_min_cost;
            prevVertex[mask][current]= i;
        }
    }
  }
  minCost[mask][current] = min_cost;
}

string Traveling(int G[30][30], int N, char start) {
  // TODO Implement
  rewriteMatrix (G, N);
  int start_index = start -'A';
  vector<vector<int>> minCost ((1<<N), vector<int>(N, -1));
  vector<vector<int>> prevVertex ((1<<N), vector<int>(N, -1));
  int mask = (1<<(start_index));
  DP(G, start_index, start_index, mask, N, prevVertex, minCost);
  string result;
  int visitedMask = mask;
  result += start;
  for (int i = 0; i < N - 1; i++) { 
    int next = prevVertex[visitedMask][start_index];
    result += " ";
    result += char(next + 'A');
    visitedMask |= (1 << next); 
    start_index = next;
  }
    return result + " " + start; 
}
