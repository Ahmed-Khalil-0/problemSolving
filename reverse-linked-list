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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head; 
        if(head  == nullptr || head -> next == nullptr)
            return head;
        ListNode* current = head -> next; 
        ListNode* temp = head;
        prev -> next = nullptr;
        while(temp != NULL){
            temp = current -> next;
            current -> next = prev;
            prev = current; 
            current = temp;
        }
        return prev; 
    }
};
