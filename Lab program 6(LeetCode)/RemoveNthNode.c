/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *first = &dummy, *second = &dummy;

    for (int i = 0; i < n; i++) {
        first = first->next;
    }
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    struct ListNode *toDelete = second->next;
    second->next = second->next->next;

    return dummy.next;
}
