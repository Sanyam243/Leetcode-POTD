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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* nextListNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextListNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        int count = 1;
        ListNode* temp = head;
        ListNode* reverseHead = head;
        ListNode* lastEnd = NULL;
        ListNode* newHead = head;

        while (temp != NULL) {
            if (count % k == 0) {

                ListNode* nextListNode = temp->next;
                temp->next = NULL;
                ListNode* h = reverse(reverseHead);
                if (lastEnd != NULL)
                    lastEnd->next = h;
                else
                    newHead = h;
                reverseHead->next = nextListNode;
                lastEnd = reverseHead;
                reverseHead = nextListNode;
                temp = nextListNode;
           

            } else {
                temp = temp->next;
            };
            count++;
        }

        return newHead;
    }
};