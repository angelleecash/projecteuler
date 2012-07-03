#include <stdio.h>
#include "pe_util.h"

#define DATA_COUNT 2048

long long cache[DATA_COUNT];

long long travel_from_to(int x, int y)
{
  int key = x * 100 + y;

  if(cache[key] > 0)
  {
    return cache[key];
  }

  long long count = 0;
  if(x == 0 || y == 0)
  {
    count = 1;
  }
  else if(x == 1 || y == 1)
  {
    count = maxInt(x,y)+1;
  }
  else
  {
    int col=0;
    for(; col < x - 1; col++)
    {
      count += travel_from_to(col, y - 2) * travel_from_to(x - col, 1);
    }

    int row=0;
    for(; row < y - 1; row++)
    {
      count += travel_from_to(x - 2, row) * travel_from_to(1, y - row);
    }
  }
  
  cache[key] = count;
  return count;
}

int main(int argc, char** args)
{
  int i=0;
  for(;i < DATA_COUNT; i++)
  {
    cache[i] = 0;
  } 

  int row = atoi(args[1]);
  int col = atoi(args[2]);
    
  printf("path found %llu.\n", travel_from_to(row, col));

  return 0;
}
