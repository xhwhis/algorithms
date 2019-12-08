#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (!s) return 0;
    if (s->top + 1 == s->size) return 0;
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    s->top = -1;
    return 1;
}

void output(Stack *s) {
    printf ("Stack = [");
    for (int i = s->top; i>= 0; i--) {
        printf ("%d", s->data[i]);
        i && printf (", ");
    }
    printf ("]\n");
}

void clear(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0));
    Stack *s = init(20);
    int op, val;
    for (int i = 0; i < 20; i++) {
        op = rand() % 2;
        val = rand() % 100;
        switch (op) {
            case 0: {
                printf ("push %d to stack = %d\n", val, push(s, val));
                output(s);
                printf ("\n");
            } break;
            case 1: {
                printf ("pop %d from stack = %d\n", top(s), pop(s));
                output(s);
                printf("\n");
            } break;
        }
    }
    return 0;
}
