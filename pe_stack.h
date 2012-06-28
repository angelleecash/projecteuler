#include "pe_linked_list.h"

typedef struct
{
  PeLinkedList list;
} PeStack;

void peStackInit(PeStack* stack);
void peStackPush(PeStack* stack, void* data);
void* peStackPop(PeStack* stack);
int peStackEmpty(PeStack* stack);
void* peStackPeek(PeStack* stack);
void peStackDestroy(PeStack* stack);
