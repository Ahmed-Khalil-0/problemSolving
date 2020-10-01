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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        ListNode* prevNode = head;
        ListNode* currentNode = head -> next;

        while(currentNode!= nullptr)
        {
            if(currentNode -> val == val){
                prevNode -> next = currentNode -> next;
                currentNode = currentNode -> next;
            }else{
                prevNode = currentNode;
                currentNode = currentNode -> next;
            }
        }
        if (head -> val == val){
            head = head -> next;
        }
        return head;
    }
};
