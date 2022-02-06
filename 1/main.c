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

void delete_front(){
  node *first = head;
  int data = head->data;
  if(head == NULL){
    printf("List is Empty");
    return;
  }

  printf("The head node is deleted and it's value was %d", head->data);
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

int main(){
  int choice, data;
  
  while (1)
  {
    printf("Enter a choice : \n1. Insert Rear\t2. Delete Front\t3. Display\t4. Exit\n");
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
      printf("Process is terminated");
      exit(0);
      break;
    
    default:
      printf("Please input valid command\n");
      break;
    }
  }
  
}