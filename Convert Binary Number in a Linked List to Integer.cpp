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
    int getDecimalValue(ListNode* head) {
        return getIt(head,0);
    }
    int getIt(ListNode* head, int prev){
        if(head == nullptr)
            return prev;
        return getIt(head->next,(prev << 1)|head->val); 
    }
};
