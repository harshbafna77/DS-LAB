/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head, *prev = NULL, *temp;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;

        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast != NULL)
        slow = slow->next;

    while (prev != NULL && slow != NULL) {
        if (prev->val != slow->val)
            return false;

        prev = prev->next;
        slow = slow->next;
    }

    return true;
}
