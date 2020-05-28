/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode * reverseList(ListNode * head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode * s = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;
    return s;
}
};
