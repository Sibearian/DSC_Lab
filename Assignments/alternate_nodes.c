#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
  int data;
  struct nodes *next;
} node;

node *head = NULL;


node *get_node(int x){
  node *temp = (node *)malloc(sizeof(node));

  temp->data = x;
  temp->next = NULL;

  return temp;
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

  if(head == NULL){
    printf("List is Empty.\n");
    return;
  }
  printf("The first node is deleted and it's value was %d\n", head->data);

  if(head->next == NULL){
    head = NULL;
    free(first);
    return;
  }

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

void display_alternative(int even){
  node *curr = head;

  if(curr == NULL){
    printf("List is empty.\n");
    return;
  }

  if(even % 2 == 0) printf("The even number nodes -> ");
  else printf("The odd number nodes -> ");

  while (curr != NULL){
    if (even % 2 == 0)
    {
      printf("%d ", curr->data);
    }
    even++;
    curr = curr->next;
  }

  printf("\n");
}

int main(){
  int choice, data;

  while (1)
  {
    printf("Enter a choice : \n1. Insert Rear\t2. Delete Front");
    printf("\t3. Display\t4. Display alternative nodes\t5. Exit\n");
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
      printf("Please enter an even or odd number : ");
      scanf("%d", &data);
      display_alternative(data);
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