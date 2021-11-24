// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

//삽질풀이 : node값+1 한 value랑 node값 하나하나 비교해서 node값 중에 최대 node 찾음. 나머지 하나가 센터값준
#include <stdio.h>

int findCenter(int **edges, int edgesSize, int *edgesColSize)
{
  if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
    return edges[0][0];
  return edges[0][1];
}

void main()
{
  return;
}