#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

void push (int value);
int pop ();

struct ListNode *top = NULL;

void reorderList(struct ListNode* head) {
    //struct ListNode *pilha = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = head;
    int size = 0;

    while (temp != NULL) {
        push (temp->val);
        temp = temp->next;
        size++;
    }

    temp = head;

    struct ListNode  *newHead = NULL;
    struct ListNode *end = NULL;

    for (int i = 0; i < size/2; i++) {
        struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));

        a->val = temp->val;
        a->next = NULL;

        if (newHead == NULL) {
            newHead = a;
        } else {
            end->next = a; 
        }
        end = a;

        temp = temp->next;

        struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
        b->val = pop();
        b->next = NULL;

        end->next = b;
        end = b;
    }

    if (size % 2 == 1) {
        struct ListNode *mid = (struct ListNode *)malloc(sizeof(struct ListNode));
        mid->val = temp->val;
        mid->next = NULL;
        end->next = mid;
        end = mid;
    }

    end->next = NULL;

    struct ListNode *final = newHead;

    while (final != NULL) {
        printf ("%d\n", final->val);
        final = final->next;
    }

    /* if (size % 2 == 0) {
        while (top != NULL && n <= size/2) {
            newHead->val = temp->val;

            temp2 = temp2->next;
            new = new->next;
            new->val = pop();
            new = new->next;
            n++;
        }
        new->next = NULL;
    }
    if (size % 2 == 1) {
        while (top != NULL && n <= (size - 1)/2) {
            new = temp2;
            temp2 = temp2->next;
            new->next = new;
            new->val = pop();
            new = new->next;
            new->next = NULL;
            n++;
        }
        new = temp2;
        temp2 = temp2->next;
        new->next = NULL;
    }
    
    while (new != NULL) {
        printf ("%d\n", new->val);
        new = new->next;
    } */

}

void push (int value) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = value;
    temp->next = top;
    top = temp;
}

int pop () {
    if (top == NULL) {
        return 0;
    }
    int popped;

    popped = top->val;
    struct ListNode *temp = top;
    top = top->next;
    free(temp);

    return popped;
}

int main () {
    struct ListNode *n1 = malloc(sizeof(struct ListNode));
    struct ListNode *n2 = malloc(sizeof(struct ListNode));
    struct ListNode *n3 = malloc(sizeof(struct ListNode));
    struct ListNode *n4 = malloc(sizeof(struct ListNode));
    struct ListNode *n5 = malloc(sizeof(struct ListNode));
    struct ListNode *n6 = malloc(sizeof(struct ListNode));
    struct ListNode *n7 = malloc(sizeof(struct ListNode));

    n1->val = 1;
    n1->next = n2;
    n2->val = 2;
    n2->next = n3;
    n3->val = 3;
    n3->next = n4;
    n4->val = 4;
    n4->next = n5;
    n5->val = 5;
    n5->next = n6;
    n6->val = 6;
    n6->next = n7;
    n7->val = 7;
    n7->next = NULL;

    reorderList(n1);
}