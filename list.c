#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* List=malloc(sizeof(List));
  List->head=NULL;
  List->tail=NULL;
  List->current=NULL;

   return List;
}

void * firstList(List * list) {
  if(list->head!=NULL){
  list->current=list->head;
  }
  return (void*)list->current->data;
  
}

void * nextList(List * list) {
  if(list->current != NULL && list->current->next != NULL){
  list->current=list->current->next;
  return (void*)list->current->data;
  }
  else return NULL;
}


void * lastList(List * list) {
  list->current=list->tail;
  return (void*)list->tail->data;
}

void * prevList(List * list) {
  if(list->current != NULL && list->current->prev != NULL){
  list->current=list->current->prev;
  return (void*)list->current->data;
  }
  else return NULL;
}

void pushFront(List * list, const void * data) {
  Node* aux=createNode(data);
  if(list->head != NULL){
    aux->next=list->head;
    list->head->prev=aux;
    list->head=aux;
  }else{
    list->head=aux;
    list->tail=aux;
  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node* aux=createNode(data);
  if(list->current != NULL){
    if(list->current != list->tail){
    aux->next=list->current->next;
    list->current->next->prev=aux;
    }
    if(list->current==list->tail)
    list->tail=aux;
    list->current->next=aux;
    aux->prev=list->current;
    list->current=aux;
  }else{
  list->current=aux;
  list->head=aux;
  list->tail=aux; 
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}