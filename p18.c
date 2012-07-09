#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pe_util.h"

typedef struct Node
{
  int childCost;
  int cost;
  int offset;
  int row;

  struct Node* next;
} Node;

int* triangles;
int numberCount =0;
const char* DATA_FILE_NAME = "triangles";

void readTriangles()
{
  FILE* fp = NULL;
  int* temp;
  temp = (int*)malloc(100000 * sizeof(int));
  fp = fopen(DATA_FILE_NAME, "r");
  if(!fp)
    {
      printf("Fail to read triangle data.\n");
      return;
    }
  char c;
  char buffer[8];
  memset(buffer, '\0', 8);
  int numberOfDigits=0, digitFound = 0;

  while((c=fgetc(fp)) != EOF)
    {
      int isDigit = c - '0' >= 0 && c - '0' <= 9;
      if(digitFound)
	{
	  if(!isDigit)
	    {
	      if(numberOfDigits > 0)
		{
		  int number = atoi(buffer);
		  temp[numberCount++]=number;

		  numberOfDigits = 0;
		  memset(buffer, '\0', 8);
		  digitFound = 0;
		}
	    }
	}
      else
	{
	  digitFound = isDigit && c - '0' > 0;
	}
      if(digitFound)
	{
	  buffer[numberOfDigits++] = c;
	}
    }
      if(digitFound && numberOfDigits > 0)
	{
	  int number = atoi(buffer);
	  temp[numberCount ++] = number;
	}
      triangles = (int*)malloc(numberCount*sizeof(int));
      int i=0;
      for(;i < numberCount;i++)
	{
	  triangles[i] = temp[i];
	}

}


int getRowCount(int numNodes)
{
  int numRows = 0;
  int nodeCount = 0;
   while(nodeCount != numNodes)
    {
      nodeCount += numRows + 1;
      numRows++;
    }
   return numRows;
}

void printTrace(Node* p)
{
  while(p)
    {
      printf("%d%s", p->cost, p->next ? "->": ".\n");
      p = p->next;
    }
}

void nodeInit(Node* p, int cost, int offset, int row, int childCost, Node* next)
{
  p->cost = cost;
  p->offset = offset;
  p->row = row;
  p->childCost = childCost;
  p->next = next;
}

int main()
{
  readTriangles();

  int numRows = getRowCount(numberCount);

  Node* nodes = (Node*)malloc(numberCount * sizeof(Node));
  int count = 0, i = 1;
  for(; i <= numRows; i++)
    {
      int j=0;
      for(;j < i;j++)
	{
	  int offset = count + j;
	  nodeInit(&nodes[offset], triangles[offset], offset, i, 0, NULL);
	}

      count += i;
    }

  for(i=numberCount-1; i > 0; i--)
    {
      Node* p = &nodes[i];
      int lpOffset = p->offset - p->row;
      int rpOffset = p->offset - p->row + 1;
      Node* lp = &nodes[lpOffset];
      Node* rp = &nodes[rpOffset];
      int pCost = p->cost + p->childCost;
      if(lp->row == p->row - 1 && lp->childCost <= pCost)
      {
	lp->childCost = pCost;
	lp->next = p;
      }

      if(rp->row == p->row - 1 && rp->childCost <= pCost)
      {
	rp->childCost = pCost;
	rp->next = p;
      }
    }

  printTrace(&nodes[0]);
  printf("Cost %d.\n", nodes[0].cost + nodes[0].childCost);
  return 0;
}
