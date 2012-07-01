#ifndef P15_H
#define P15_H

typedef struct
{
  int x;
  int y;
  int rightVisited;
  int leftVisited;
  int upVisited;
  int downVisited;
} GridNode;

void gridNodeInit(GridNode* node, int x, int y);

#endif
