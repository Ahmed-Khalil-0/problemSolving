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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if((l1 == nullptr) && (l2 == nullptr))
            return l1;
        
        int digitSum;
        int reminder = 0;
        int first = 0;  int second = 0;
        ListNode* sumList = new ListNode();
        ListNode* wipper = sumList;
        
        while(1){
            
            if(l1 != nullptr){
                first = l1->val; 
                l1 = l1->next;
            }
        
            if(l2 != nullptr){
                second = l2->val;
                l2 = l2->next; 
            }
            
            digitSum = first + second + reminder;
            reminder = 0;
            first = 0;
            second = 0;
            
            if(digitSum > 9){
                reminder++;
                digitSum %= 10; 
            }
            wipper -> val = digitSum;
             if((l1 != nullptr) || (l2 != nullptr) || (reminder > 0))
                wipper = wipper -> next = new ListNode();
            else 
                break;
        }
        return sumList;
    }
};
