#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *data;
    int rear;
    int front;
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->data = (int *) malloc(capacity * sizeof(int));
    return q;
}

int isEmpty(Queue *q) {
    if (q->rear < q->front) {
        return 1;
    }
    return 0;
}

int isFull(Queue *q) {
    if (q->rear == q->capacity - 1) {
        return 1;
    }
    return 0;
}

void enQueue(Queue *queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

void deQueue(Queue *q) {
    //B1: Kiem tra hang doi trong
    if (isEmpty(q)) {
        printf("Queue is empty");
        exit(0);
    }
    //B2: Tang chi so cua phan tu dau tien
    q->front++;
}

//Xay dung ham xem phan tu dau hang doi
int getFront(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->front;
}

//Xay dung ham hien thi hang doi
void displayQueue(Queue *q) {
    for (int i = 0; i < q->capacity; i++) {
        printf("%d ", q->data[i]);
    }
}

int main() {
    int capacity;
    printf("nhap so luong phan tu: ");
    scanf("%d", &capacity);
    Queue *q = createQueue(capacity);
    if (q != NULL) {
        printf("Ham khoi tao thanh cong voi %d phan tu!", capacity);
    }else {
        printf("Ham chua duoc khoi tao");
    }
}
