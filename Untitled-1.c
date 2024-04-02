#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct stack {
    int top;
    char items[MAX_SIZE];
} Stack;

void push(Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++s->top] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

bool isBalanced(char str[]) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = -1;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(s) || !match(pop(s), str[i])) {
                free(s);
                return false;
            }
        }
    }

    if (isEmpty(s)) {
        free(s);
        return true;
    }

    free(s);
    return false;
}

int main() {
    char str[MAX_SIZE];
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}