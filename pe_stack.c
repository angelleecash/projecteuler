#include "pe_stack.h"

void peStackInit(PeStack* stack)
{
  peLinkedListInit(&(stack->list));
}

void peStackPush(PeStack* stack, void* data)
{
  peLinkedListInsert(&(stack->list), peLinkedListLength(&(stack->list)), data);
}

void* peStackPop(PeStack* stack)
{
  return peLinkedListRemove(&(stack->list), peLinkedListLength(&(stack->list))-1);
}

int peStackEmpty(PeStack* stack)
{
  return peLinkedListLength(&(stack->list)) <= 0;
}

void* peStackPeek(PeStack* stack)
{
  return peLinkedListGet(&(stack->list), peLinkedListLength(&(stack->list))-1);
}

void peStackDestroy(PeStack* stack)
{
  while(!peStackEmpty(stack))
  {
    peStackPop(stack);
  }
}
