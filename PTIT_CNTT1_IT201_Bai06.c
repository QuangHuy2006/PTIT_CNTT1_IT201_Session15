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

int deQueue(Queue *q) {
    //B1: Kiem tra hang doi trong
    if (isEmpty(q)) {
        printf("Queue is empty");
        exit(0);
    }
    //B2: Tang chi so cua phan tu dau tien
    q->front++;
    return q->data[q->front];
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
    printf("queue = {\n");
    printf("arr = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d,", q->data[i]);
    }
    printf("]\n");
    printf("front = %d\n", q->front);
    printf("rear = %d\n", q->rear);
    printf("capacity = %d\n", q->capacity);
    printf("};\n");
}

int checkIfIncrement(Queue *q) {
    for (int i = q->front; i <= q->rear - 1; i++) {
        if (q->data[i] + 1 != q->data[i + 1]) {
            return 0;
        }
    }
}
int main() {
    int capacity;
    printf("nhap so luong phan tu: ");
    scanf("%d", &capacity);
    Queue *q = createQueue(capacity);
    if (q != NULL) {
        printf("Ham khoi tao thanh cong voi %d phan tu!\n", capacity);
    }else {
        printf("Ham chua duoc khoi tao");
    }
    for (int i = 1; i <= capacity; i++) {
        int value;
        printf("Vui long nhap phan tu thu %d : ", i);
        scanf("%d", &value);
        printf("\n");
        enQueue(q,value);
    }
    displayQueue(q);
    if (checkIfIncrement(q) == 0) {
        printf("False");
    }else {
        printf("True");
    }

}
