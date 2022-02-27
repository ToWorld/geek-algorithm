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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* help = new ListNode(0);
        ListNode* tail = help;
        ListNode* next;
        while (list1 != NULL || list2 != NULL) {
            if (list2 == NULL || (list1 != NULL && list2 != NULL &&list1->val <= list2->val)) {
                next = list1->next;
                tail->next = list1;
                tail = list1;
                list1->next = NULL;
                list1 = next;
            } else {
                next = list2->next;
                tail->next = list2;
                tail = list2;
                list2->next = NULL;
                list2 = next;
            }
        }
        return help->next;
    }
};
