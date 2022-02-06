#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int top = 0;
int array[SIZE];

void push(int data){
  if(top == SIZE){
    printf("Reached top of the stack. The size of the stack is %d.\n", SIZE);
    return;
  }

  array[top++] = data;
  return;
}

void pop(){
  if(top <= 0){
    printf("Reached the bottom.\n");
    return;
  }

  printf("%d is poped", array[--top]);
}

void display(){
  if(top <= 0){
    printf("Empty Stack.\n");
    return;
  }

  printf("The stack consists -> ");
  for(int i = 0; i < top; i++)
    printf("%d ", array[i]);
}

int main(){
  int choice, data, size;

  for(int i = 0; i < SIZE; i++)
    array[i] = -1;

  while(1){
    printf("\n1. Push\t2. Pop\t3. Display\t4. Exit\n");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to be inserted : ");
        scanf("%d", &data);
        push(data);
        break;

      case 2:
        pop();
        break;
      
      case 3:
        display();
        break;
      
      case 4:
        printf("program terminated\n");
        exit(0);
        break;
    }
  }

}

