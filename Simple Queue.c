#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue (int item)
{
  if(rear == MAX_SIZE - 1)
  {
    printf("Queue Overflow \n");
    return;
  }
  if (front == -1)
  {
    front = 0;
  }
  rear++;
  queue[rear] = item;
  printf("Inserted %d into the queue", item);
}

int dequeue()
{
  if (front == -1 || front>rear)
  {
    printf("Queue Underflow \n");
    return -1;
  }
  int item =queue[front];
  front++;
  printf("Deleted %d from the queue \n", item);
  return item;
}

void display()
{
  if (front == -1 || front > rear)
  {
    printf("Queue is empty \n");
    return;
  }
  printf("Queue elements: ");
  for(int i = front; i<=rear; i++)
  {
    printf("%d", queue[i]);
  }
  printf("\n");
}

int main()
{
  int choice, item;
  while(1)
  {
    printf("\n----QUEUE OPERATIONS----\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      printf("Enter item to insert: ");
      scanf("%d", &item);
      enqueue(item);
      break;
      case 2:
      dequeue();
      break;
      case 3:
      display();
      break;
      case 4:
      printf("Existing program...\n");
      return 0;
      default:
      printf("Invalid Choice.....\n");
    }
  }
}
