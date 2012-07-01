#include <stdio.h>

int travel_from_to(int x, int y)
{
  if(x == 0 && y == 0)
  {
    return 1;
  }

  if(x == 1 && y == 1)
  {
    return 2;
  }

  if(x == 2 && y == 2)
  {
    return 6;
  }

  int count = 0;
  int col=0;
  for(; col <= x; col++)
  {
    count += travel_from_to(col, y - 1) * travel_from_to(x - col, 1);
  }
  int row=0;
  for(; row <= y - 1; row++)
  {
    count += travel_from_to(x - 1, row) * travel_from_to(1, y - row);
  }

  return count;
}

int main()
{
  printf("path found %d.\n", travel_from_to(20, 20));
  return 0;
}
