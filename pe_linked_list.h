#include <stdlib.h>


typedef struct PeLinkedListNode
{
  struct PeLinkedListNode* next;
  void* data;
} PeLinkedListNode;

void peLinkedListNodeInit(PeLinkedListNode* node, PeLinkedListNode* next, void* data);


typedef struct
{
  PeLinkedListNode head;
} PeLinkedList;

void peLinkedListInit(PeLinkedList* list);
PeLinkedListNode* peLinkedListInsert(PeLinkedList* list, int index, void* data);
int peLinkedListLength(PeLinkedList* list);
void* peLinkedListRemove(PeLinkedList* list, int index);
void* peLinkedListGet(PeLinkedList* list, int index);
int peLinkedListIndexOf(PeLinkedList* list, void* data);
