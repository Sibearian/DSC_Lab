#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
  int data;
  struct nodes *next;
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

void delete_at(int pos){
  node *curr = head, *prev = NULL;

  if(pos < 0){
    printf("Position value is negeative");
    return;
  }

  if(head == NULL){
    printf("Position out of bound. List is empty and available position is 0.\n");
    return;
  }

  if(pos == 0){
    printf("%d is poped at location %d.\n", head->data, pos);
    head = head->next;
    free(curr);
    return;
  }

  for (int i = 0; i < pos; i++)
  {
    if (curr == NULL)
    {
      printf("Position out of bound. Last Position is %d\n", i);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  
  printf("%d is poped at location %d.\n", curr->data, pos);
  prev->next = curr->next;
  free(curr);
}

int main(){
    int choice, data, pos;
  
  while (1)
  {
    printf("Enter a choice : \n1. Insert Rear\t2. Delete At\t3. Display\t4. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case  1:
      printf("Enter the number to be inserted : ");
      scanf("%d", &data);
      insert_rear(data);
      break;
    
    case 2:
      printf("Enter the position to be deleted : ");
      scanf("%d", &data);
      delete_at(data);
      break;
    
    case 3:
      display();
      break;

    case 4:
      printf("Process is terminated");
      exit(0);
      break;
    
    default:
      printf("Please input valid command\n");
      break;
    }
  }
}