#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    char **data;
    int rear;
    int front;
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->data = (char **) malloc(capacity * sizeof(char *));
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

void enQueue(Queue *queue, char *value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

char *deQueue(Queue *q) {
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
char *getFront(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->data[q->front];
}

//Xay dung ham hien thi hang doi
void displayQueue(Queue *q) {
    printf("guest = {\n");
    printf("arr = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s,", q->data[i]);
    }
    printf("]\n");
    printf("};\n");
}

int main() {
    int capacity;
    printf("nhap so luong phan tu: ");
    scanf("%d", &capacity);
    Queue *q = createQueue(capacity);
    if (q != NULL) {
        printf("Ham khoi tao thanh cong voi %d phan tu!", capacity);
    } else {
        printf("Ham chua duoc khoi tao");
    }
    int choice;
    do {
        printf("\n1. Add customer\n");
        printf("2. Serving\n");
        printf("3. Show customer list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                char value[100];
                printf("\nnhap ten khach hang vao mang: ");
                fgets(value, 100, stdin);
                value[strcspn(value, "\n")] = '\0';
                enQueue(q, value);
                break;
            case 2:
                printf("%s", getFront(q));
                deQueue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exit");
                break;
        }
    } while (choice != 4);
    exit(0);
}
