#include "p15.h"

void gridNodeInit(GridNode* node)
{
  node->x = x;
  node->y = y;
  node->rightVisited = 0;
  node->leftVisited = 0;
  node->upVisited = 0;
  node->downVisited = 0;
}

int main()
{
  GridNode node;
  gridNodeInit(&node);   

  return 0;
}
