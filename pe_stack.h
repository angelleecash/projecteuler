typedef struct
{

} PeStack;

void peStackInit(PeStack* stack);
void peStackPush(PeStack* stack, void* item);
void* peStackPop(PeStack* stack);
int peStackEmpty(PeStack* stack);
void* peStackPeek(PeStack* stack);
