#include "p15.h"
#include "pe_stack.h"
#include <stdio.h>

void gridNodeInit(GridNode* node, int x, int y)
{
  node->x = x;
  node->y = y;
  node->rightVisited = 0;
  node->leftVisited = 0;
  node->upVisited = 0;
  node->downVisited = 0;
}

int numRows = 20;
int numCols = 20;

int hasRightNode(GridNode* node)
{
  return node->x < numCols;
}

int hasDownNode(GridNode* node)
{
  return node->y < numRows;
}

void pushNewNode(PeStack* stack, int x, int y)
{
  GridNode* node = (GridNode*)malloc(sizeof(GridNode));
  gridNodeInit(node, x, y);

  peStackPush(stack, node);
}

int main()
{
  PeStack stack;
  peStackInit(&stack);

  pushNewNode(&stack, 0, 0);
  int count = 0;
  
  while(!peStackEmpty(&stack))
  {
    GridNode* node = peStackPeek(&stack);

    if(hasRightNode(node) && !node->rightVisited)
    {
      pushNewNode(&stack, node->x + 1, node->y);
      node->rightVisited = 1;
    }
    else if(hasDownNode(node) && !node->downVisited)
    {
      pushNewNode(&stack, node->x, node->y + 1);
      node->downVisited = 1;
    }
    else
    {
      node = peStackPop(&stack);
      if(node->x == numCols && node->y == numRows)
      {
	  count ++;
      }
      free(node);
      node = NULL;
    }
  }

  printf("Total %d.\n", count);
  return 0;
}
