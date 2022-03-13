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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists);
    }
    ListNode* merge(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        vector<ListNode*> left;
        vector<ListNode*> right;
        // step1: 拆
        for (int i = 0; i < lists.size(); i++) {
            if (i <lists.size()/2) {
                left.push_back(lists[i]);
            } else {
                right.push_back(lists[i]);
            }
        }
        // step2: 左合并, 右合并
        ListNode* new1 = mergeKLists(left);
        ListNode* new2 = mergeKLists(right);
        ListNode* help = new ListNode(0);
        ListNode* tail = help;
        // step3: 合并左右
        while (new1 != nullptr || new2 != nullptr) {
            if (new2 == nullptr || (new1 != nullptr && new1->val <= new2->val)) {
                tail->next = new1;
                tail = new1;
                new1 = new1->next;
                continue;
            }
            if (new1 == nullptr || (new2 != nullptr && new2->val <= new1->val)) {
                tail->next = new2;
                tail = new2;
                new2 = new2->next;
            }
        }
        return help->next;
    }
};
