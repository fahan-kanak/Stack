/* 
 * File:   stack.c
 * Author: farhan
 *
 * Created on April 14, 2021, 8:22 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int x;
    struct node *next;
};

typedef struct node Stack;

void push(int val, Stack *head) {
    if (head->next == NULL) {
        head->next = (Stack *)malloc(sizeof(Stack));
        head->next->x = val;
        head->next->next = NULL;
        return;
    }
    push(val, head->next);
}

int pop(Stack *head) {    
    if (head->next->next == NULL) {
        int c = head->next->x;
        free(head->next);
        head->next = NULL;
        return c;
    }
    return pop(head->next);
}

int peek(Stack *head) {
    if (head == NULL) return -1;
    if (head->next == NULL) return head->x;
    return peek(head->next);
}

int isEmpty(Stack *head) {
    if (head == NULL) return 1;
    else return 0;
}

int getSize(Stack *head) {
    int var = 0;
    for(;head != NULL; head = head->next) var++;
    return var;
}

void printStack(Stack *head) {
    printf("%d ", head->x);
    if (head->next == NULL) return;    
    printStack(head->next);
}

int main(int argc, char** argv) {
    Stack *head = NULL;
    int choice, c;
    while(1) {
        printf("\n1 -> push\n2 -> pop\n3 -> peek\n4 -> size\n5 -> print Stack\n6 -> quit\n");
        printf("\nEnter operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter value: ");
                scanf("%d", &c);                
                if (head == NULL) {
                    head = (Stack *)malloc(sizeof(Stack));
                    head->x = c;
                    head->next = NULL;
                } else push(c, head);
                break;
            case 2:                
                if (isEmpty(head)) printf("\nEmpty Stack Exception!!!\n");
                else if (head->next == NULL) {
                    printf("\n%d is popped\n", head->x);
                    free(head);
                    head = NULL;
                }
                else printf("\n%d is popped\n", pop(head));
                break;
            case 3:
                c = peek(head);
                if (c == -1) printf("\nEmpty Stack Exception!!!\n");
                else printf("\n%d is on the top\n", c);
                break;
            case 4:
                printf("\nStack size => %d\n", getSize(head));
                break;
            case 5:
                if (isEmpty(head)) printf("\nEmpty Stack Exception!!!\n");
                else {
                    printf("\nStack => ");
                    printStack(head);
                    printf("\n");
                }
                break;
            default:
                printf("\nBye!!\n");
                goto exit;
        }
    }

    exit: return 0;
}

