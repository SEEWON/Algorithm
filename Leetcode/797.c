// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

#include <stdio.h>

//  sizeof(graph[i]) / sizeof(int) 를 하면 i번째 노드와 연결되어 있는 노드의 개수를 알 수 있음.
//  반복문을 몇 번 중첩하는지는 코드로 직접 짜야 하는데,
//  한 노드에 화살표 몇 번 연결되는 호출해서 

int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize, int *returnSize, int **returnColumnSizes)
{
  for (int i = 0; i < sizeof(graph[0]) / sizeof(int); i++)
  {
    for (int j = 0; j < sizeof(graph[i]) / sizeof(int); j++)
    {

    }
  }
}

void main()
{
  return;
}