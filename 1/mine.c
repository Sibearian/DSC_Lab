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

void insert_end(int x){
  node *temp = first, *new_node = get_node(x);

  if(first == NULL){
    first = new_node;
    return;
  }

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = new_node;
}

void insert_front(int x){
  node *new_node = get_node(x);

  if(first == NULL){
    first = new_node;
    return;
  }

  new_node->next = first;
  first = new_node;
}

void display(){
  node *temp = first;
  if(first==NULL){
    printf("List is empty.\n");
    return;
  }

  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void delete_rear(){
  node *temp = first, *t;

  if(first==NULL){
    printf("List is empty.\n");
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

  if(first->next == NULL){
    first = NULL;
    free(temp);
    return;
  }

  printf("The node deleted is : %d\n", first->data);

  first = first->next;
  free(temp);
}

void delete_data(int x){
  node *curr = first, *temp;

  if(first == NULL){
    printf("List is empty.\n");
    return;
  }

  if(first->data == x){
    delete_front();
    return;
  }

  while ( curr->next != NULL){
    if(curr->next->data == x){
      temp = curr->next;
      curr->next = temp->next;
      free(temp);

      return;
    }
    curr=curr->next;
  }
  
  printf("No such element found");

}

int main(){
  int choice, data;

  while (1)
  {
    printf("\n1. Insert rear\t2. Insert front\t3. Display\n4. Delete rear\t5. Delete front\t6. Delete node\n7. Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the number to be inserted at rear : ");
      scanf("%d", &data);
      insert_end(data);
      break;
    
    case 2:
      printf("Enter the number to be inserted at front : ");
      scanf("%d", &data);
      insert_front(data);
      break;
      
    case 3:
      display();
      break;

    case 4:
      delete_rear();
      break;

    case 5:
      delete_front();
      break;

    case 6:
      printf("Enter the value to be deleted : ");
      scanf("%d", &data);
      delete_data(data);
      break;

    case 7:
      printf("program terminated\n");
      exit(0);
      break;
    
    default:
      printf("Please choose a valid option.");
      break;
    }
  }
}