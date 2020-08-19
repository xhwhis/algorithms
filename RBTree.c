#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    NIL->key = 0;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

void red_up(Node *root) {
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return ;
}

Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root;
        red_up(root);
    }
    if (root->lchild->color == RED && hasRedChild(root->lchild)) {
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->lchild->color == RED && hasRedChild(root->rchild)) {
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else {
        return root;
    }
    red_up(root);
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    root = insert_maintain(root);
    return root;
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    if (hasRedChild(root)) {
        root->color = RED;
        root = root->lchild->color ? left_rotate(root) : right_rotate(root);
        root->color = BLACK;
        if (root->lchild->color == RED) {
            root->lchild = erase_maintain(root->lchild);
        } else {
            root->rchild = erase_maintain(root->rchild);
        }
        return root;
    }
    if (root->lchild->color == DOUBLE_BLACK) {
        if (!hasRedChild(root->rchild)) {
            root->lchild->color--;
            root->rchild->color--;
            root->color++;
            return root;
        }
        if (root->rchild->rchild != RED) {
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
        }
        root->lchild->color--;
        root->rchild->color = root->color;
        root = left_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    } else {
        if (!hasRedChild(root->lchild)) {
            root->rchild->color--;
            root->lchild->color--;
            root->color++;
            return root;
        }
        if (root->lchild->lchild != RED) {
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
        }
        root->rchild->color--;
        root->lchild->color = root->color;
        root = right_rotate(root);
        root->rchild->color = root->lchild->color = BLACK;
    }
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = __erase(root->lchild, key);
    else if (root->key < key) root->rchild = __erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    root = erase_maintain(root);
    return root;
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void __output(Node *root) {
    if (root == NIL) return ;
    __output(root->rchild);
    printf ("%d(%d) [%d %d]\n", root->key, root->color, root->lchild->key, root->rchild->key);
    __output(root->lchild);
    return ;
}

void output(Node *root) {
    printf ("----RedBlack_Tree----\n");
    __output(root);
    printf ("---------------------\n");
    return ;
}

int main() {
    Node *root = NIL;
    int op, val;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: {
                printf ("insert %d to RedBlack_Tree\n", val);
                root = insert(root, val);
            } break;
            case 2: {
                printf ("erase %d from RedBlack_Tree\n", val);
                root = erase(root, val);
            } break;
            default: break;
        }
        output(root);
    }
    clear(root);
    return 0;
}
