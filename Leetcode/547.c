// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

#include <stdio.h>
#include <stdbool.h>
void dfs(int **isConnected, int isConnectedSize, int index, bool *visited)
{
  visited[index] = true;
  for (int i = 0; i < isConnectedSize; i++)
  {
    if (isConnected[index][i] && !visited[i])
    {
      dfs(isConnected, isConnectedSize, i, visited);
    }
  }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
  int res = 0;
  bool *visited = (bool *)calloc(isConnectedSize, sizeof(bool));

  for (int i = 0; i < isConnectedSize; i++)
  {
    if (!visited[i])
    {
      res++;
      dfs(isConnected, isConnectedSize, i, visited);
    }
  }

  free(visited);
  return res;
}

void main()
{
  return;
}