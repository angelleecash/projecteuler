#include <stdlib.h>
#include <stdio.h>
#include "pe_util.h"

typedef struct Node
{
  int childCost;

  int cost;
  int offset;
  int row;
  struct Node* next;
} Node;

int triangles[]={
75,
95,64,
17,47,82,
18,35,87,10,
20,04,82,47,65,
19,01,23,75,03,34,
88,02,77,73,07,63,67,
99,65,04,28,06,16,70,92,
41,41,26,56,83,40,80,70,33,
41,48,72,33,47,32,37,16,94,29,
53,71,44,65,25,43,91,52,97,51,14,
70,11,33,28,77,73,17,78,39,68,17,57,
91,71,52,38,17,14,91,43,58,50,27,29,48,
63,66,04,68,89,53,67,30,73,16,69,87,40,31,
04,62,98,27,23,9,70,98,73,93,38,53,60,04,23,
};


int main(int argc, char** args)
{
  int numNodes = sizeof(triangles) / sizeof(int);

  int numRows = 1;
  int nodeCount = 0;
  while(nodeCount != numNodes)
    {
      nodeCount += numRows;
      numRows++;
    }

  Node* nodes = (Node*)malloc(numNodes * sizeof(Node));
  int count = 0;
  int i = 1;
  for(; i <= numRows; i++)
    {
      int j=0;
      for(;j < i;j++)
	{
	  int offset = count + j;
	  Node* p = &nodes[offset];
	  p->cost = triangles[offset];
	  p->offset = offset;
	  p->row = i;
	  p->childCost = 0;
	  p->next = NULL;
	}

      count += i;
    }

  for(i=numNodes-1; i > 0; i--)
    {
      Node* p = &nodes[i];
      int lpOffset = p->offset - p->row;
      int rpOffset = p->offset - p->row + 1;
      Node* lp = &nodes[lpOffset];
      Node* rp = &nodes[rpOffset];
      if(lp->row == p->row - 1 && lp->childCost <= p->cost)
      {
	lp->childCost = p->cost;
      }

      if(rp->row == p->row - 1 && rp->childCost <= p->cost)
      {
	rp->childCost = p->cost;
      }
    }
  int cost = 0;
  Node* p = &nodes[0];
  while(p)
    {
      cost += p->cost;

      int lcOffset = p->offset + p->row;
      int rcOffset = p->offset + p->row + 1;
      if(lcOffset >= numNodes || rcOffset >= numNodes)
	{
	  break;
	}

      if(nodes[lcOffset].cost + nodes[lcOffset].childCost >= nodes[rcOffset].cost + nodes[rcOffset].childCost)
	{
	  p = &nodes[lcOffset];
	}
      else
	{
	  p = &nodes[rcOffset];
	}
    }
  printf("Cost %d.\n", cost);
  return 0;
}
