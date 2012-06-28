#include "pe_linked_list.h"

void peLinkedListNodeInit(PeLinkedListNode* node, PeLinkedListNode* next, void* data)
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

int peLinkedListLength(PeLinkedList* list)
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

void* peLinkedListRemove(PeLinkedList* list, int index)
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
  void* data = node->data;
  free(node);
  return data;
}

void* peLinkedListGet(PeLinkedList* list, int index)
{
  PeLinkedListNode* node = (list->head).next;
  while(index > 0)
  {
    node = node->next;
    index --;
  }
  return node->data;
}

int peLinkedListIndexOf(PeLinkedList* list, void* data)
{
  int index = -1;
  int current = 0;
  PeLinkedListNode* node = (list->head).next;
  while(node)
  {
    if(node->data == data)
    {
      index = current;
      break;
    }
    node = node->next;
    current++;
  }
  return index;
}

