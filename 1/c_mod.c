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

void delete_max(){
  node *curr = head, *prev_max = NULL;
  
  if(head == NULL){
    printf("List is empty.\n");
    return;
  }

  int max = head->data;

  if(head->next == NULL){
    head = NULL;
    printf("%d is deleted from the list.\n", curr->data);
    free(curr);
    return;
  }

  while (curr->next != NULL)
  {
    if(curr->next->data > max){
      prev_max = curr;
      max = curr->data;
    }
    curr = curr->next;
  }

  if (prev_max == NULL)
  {
    curr = head;
    head = head->next;
    printf("%d is deleted from the list.\n", curr->data);
    free(curr);
    return;
  }
  

  curr = prev_max->next;
  prev_max->next = curr->next;

  printf("%d is deleted from the list.\n", curr->data);

  free(curr);
}

int main(){
    int choice, data, pos;
  
  while (1)
  {
    printf("Enter a choice : \n1. Insert Rear\t2. Delete Max\t3. Display\t4. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case  1:
      printf("Enter the number to be inserted : ");
      scanf("%d", &data);
      insert_rear(data);
      break;
    
    case 2:
      delete_max();
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
