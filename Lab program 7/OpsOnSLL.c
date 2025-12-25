#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node;

node *create_node(int val) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

node *sort_list(node *head) {
    int swapped;
    node *ptr1;
    node *lptr = NULL;
    if (head == NULL)
        return head;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                int temp = ptr1->val;
                ptr1->val = ptr1->next->val;
                ptr1->next->val = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return head;
}
node *concatenate_lists(node *head1, node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}

node *reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


int main(void) {

    node *head = create_node(10);
    head->next = create_node(20);
    head->next->next = create_node(30);


    node *head1 = create_node(5);
    head1->next = create_node(1);
    head1->next->next = create_node(3);

    printf("Original lists:\n");
    print_list(head);
    print_list(head1);


    head1 = sort_list(head1);
    printf("After sorting head1:\n");
    print_list(head1);


    head = concatenate_lists(head, head1);
    printf("After concatenation (head):\n");
    print_list(head);

    head = reverse_list(head);
    printf("After reversing concatenated list (head):\n");
    print_list(head);


    return 0;
}
