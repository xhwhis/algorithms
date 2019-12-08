#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length, count;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->count = 0;
    q->length = n;
    return q;
}

int empty(Queue *q) {
    return q->count == 0;
}

int push(Queue *q, int val) {
    if (!q) return 0;
    if (q->count == q->length) return 0;
    q->data[q->tail] = val;
    q->tail++;
    if (q->tail == q->length) q->tail = 0;
    q->count++;
    return 1;
}

int front(Queue *q) {
    if(empty(q)) return 0;
    return q->data[q->head];
}

int pop(Queue *q) {
    if (!q) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->length) q->head = 0;
    q->count--;
    return 1;
}

void output(Queue *q) {
    printf ("Queue = [");
    for (int i = 0, j = q->head; i < q->count; i++) {
        i && printf (", ");
        printf ("%d", q->data[(i + j) % q->length]);
    }
    printf ("]\n");
    return ;
}

void clear(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    Queue *q = init(20);
    int op, val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 2;
        val = rand() % 100;
        switch (op) {
            case 0: {
                printf ("push %d to queue = %d\n", val, push(q, val));
                output(q);
                printf ("\n");
            } break;
            case 1: {
                printf ("pop %d from queue = %d\n", front(q), pop(q));
                output(q);
                printf ("\n");
            } break;
        }
    }
    return 0;
}
