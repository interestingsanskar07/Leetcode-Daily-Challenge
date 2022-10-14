2095. Delete the Middle Node of a Linked List


// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *a=head, *b=head, *c=head;
        if(head==NULL || head->next==NULL)
            return NULL;
        while(c and c->next){
            b = a;
            a = a->next;
            c = c->next->next;
        }
        b->next = a->next;
        delete a;
        return head;
    }
};