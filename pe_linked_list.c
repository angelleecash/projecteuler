#include "pe_linked_list.h"

void peLinedListNodeInit(PeLinkedListNode* node, PeLinedListNode* next, void* data)
{
  node->next = next;
  node->data = data;
}

void peLinkedListInit(PeLinkedList* list)
{
  peLinkedListNodeInit(&(list->head), NULL, NULL);
}


PeLinkedListNode* peLinkedListInsert(PeLinkedList* list, int index, void* data)
{
  PeLinkedListNode* node = (PeLinkedListNode*)malloc(sizeof(PeLinkedListNode));
  peLinkedListNodeInit(node, NULL, data);

  PeLinkedListNode* previous = &(list->head);

  while(index > 0)
  {
    previous = previous->next;
    index--;
  }
  node->next = previous->next;
  previous->next = node;
  return node;
}

int peLinkedListNodeLength(PeLinkedList* list)
{
  PeLinkedListNode* node = list->head.next;

  int length = 0;  
  while(node)
  {
    length ++;
    node = node->next;
  }
  return length;
}

void peLinkedListRemove(PeLinkedList* list, int index)
{
  PeLinkedListNode* previous = &(list->head);
  PeLinkedListNode* node = previous->next;


  while(index > 0)
  {
    previous = node;
    node = node->next;
    index--;
  }

  if(node->next)
  {
    previous->next = node->next;
  }
  else
  {
    previous->next = NULL;
  }

  delete node;
}

int peLinkedListIndexOf(PeLinkedList* list, void* data)
{
  return 0;
}
