#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data;
  struct _node *next;
} node;

node *head = NULL;


node* get_node(int data){
  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->next = NULL;
  return new;
}

void insert_rear(int data){
  node *new = get_node(data), *curr = head;
  if(head == NULL){
    head = new;
    return;
  }
  while (curr->next != NULL)
    curr = curr->next;

  curr->next = new;
}

void delete_front(){
  node *first = head;
  int data = head->data;

  if(head == NULL){
    printf("List is Empty");
    return;
  }

  if(head->next == NULL){
    head = NULL;
    free(first);
    return;
  }

  printf("The first node is deleted and it's value was %d", data);
  head = head->next;
  free(first);
}

void display(){
  node *curr = head;

  if(head == NULL){
    printf("Empty list.\n");
    return;
  }

  printf("Displaying the list -> ");
  
  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }

  printf("\n");
}

void insert_at(int data, int pos){
  node *curr = head, *new_node = get_node(data), *prev = head;

  if(pos < 0){
    printf("Position value is negeative");
    return;
  }
  
  if(head == NULL && pos != 0){
    printf("Position out of bound. List is empty and available position is 0.\n");
    return;
  }

  if(pos == 0){
    new_node->next = head;
    head = new_node;
    return;
  }

  for (int i = 0; i < pos; i++)
  {
    if(curr == NULL){
      printf("Position out of bound. Last Position is %d\n", i);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  prev->next = new_node;
  new_node->next = curr;
}

int main(){
    int choice, data, pos;
  
  while (1)
  {
    printf("Enter a choice : \n1. Insert Rear\t2. Delete Front\t3. Display\t4. Insert in a position\t5. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case  1:
      printf("Enter the number to be inserted : ");
      scanf("%d", &data);
      insert_rear(data);
      break;
    
    case 2:
      delete_front();
      break;
    
    case 3:
      display();
      break;

    case 4:
      printf("Enter the position and data to be inserted : ");
      scanf("%d %d", &pos, &data);
      insert_at(data, pos);
      break;

    case 5:
      printf("Process is terminated");
      exit(0);
      break;
    
    default:
      printf("Please input valid command\n");
      break;
    }
  }
}