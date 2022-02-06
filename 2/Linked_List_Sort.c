#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
  int data;
  struct nodes *next;
} node;

node *first = NULL;

node *get_node(int x){
  node *temp = (node *)malloc(sizeof(node));

  temp->data = x;
  temp->next = NULL;

  return temp;
}

void display(){
  node *temp = first;
  if(first==NULL){
    printf("List is empty.\n");
    return;
  }

  printf("The list is -> ");
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void insert(int x){
  node *curr = first, *new_node = get_node(x);

  if(first == NULL){
    first = new_node;
    return;
  }


  while (curr->next != NULL)
  {
    if(curr->next->data >= x){
      new_node->next = curr->next;
      curr->next = new_node;
      return;
    }
    curr = curr->next;
  }

  if(curr->data > x){
    new_node->next = curr;
    first = new_node;
    return;
  }

  curr->next = new_node;
}

void delete_rear(){
  node *temp = first, *t;
  if(first==NULL){
    printf("List is empty.\n");
    return;
  }

  if(first->next == NULL){
    temp = first;
    first = NULL;
    free(temp);
    return;
  }

  while (temp->next->next != NULL)
    temp = temp->next;

  t = temp->next;
  temp->next = NULL;
  free(t);
}

void delete_front(){
  node *temp = first;
  if(first==NULL){
    printf("List is empty.\n");
    return;
  }

  first = first->next;

  free(temp);
}

int main(){
  int choice, data;

  while (1)
  {
    printf("\n1. Insert\t2. Display\t3. Delete rear\n4. Delete front\t5. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the number to be inserted at rear : ");
      scanf("%d", &data);
      insert(data);
      break;
      
    case 2:
      display();
      break;

    case 3:
      delete_rear();
      break;

    case 4:
      delete_front();
      break;

    case 5:
      printf("program terminated\n");
      exit(0);
      break;
    
    default:
      printf("Please choose a valid option.");
      break;
    }
  }
}