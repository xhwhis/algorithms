#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size *= 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
}

int insert(Vector *vector, int loc, int val) {
    if (loc < 0 || loc > vector->length) {
        return 0;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = val;
    vector->length++;
    return 1;
}

int search(Vector *vector, int val) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == val) return i;
    }
    return -1;
}

int delete_node(Vector *vector, int ind) {
    if (ind < 0 || ind >= vector->length) {
        return 0;
    }
    for (int i = ind + 1; i < vector->length; i++) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
    return 1;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
        i && printf (" ");
        printf ("%d", vector->data[i]);
    }
    printf ("\n");
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int m;
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int t;
        scanf ("%d", &t);
        switch (t) {
            case 1: {
                int loc, val;
                scanf ("%d%d", &loc, &val);
                int flag = insert(a, loc, val);
                printf ("%s\n", flag ? "success" : "failed");
            } break;
            case 2: {
                int ind;
                scanf ("%d", &ind);
                int flag = delete_node(a, ind);
                printf ("%s\n", flag ? "success" : "failed");
            } break;
            case 3: {
                int val;
                scanf ("%d", &val);
                int flag = search(a, val);
                printf ("%s\n", (flag + 1) ? "success" : "failed");
            } break;
            case 4: {
                print(a);
            } break;
            default: break;
        }
    }
    clear(a);
    return 0;
}
