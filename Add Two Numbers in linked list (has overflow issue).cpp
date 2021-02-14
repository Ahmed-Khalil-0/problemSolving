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
        if(l1 == nullptr && l2 == nullptr)
            return l1;
        unsigned long long sum = GetNumber(l1) + GetNumber(l2);
        ListNode* retValue = new ListNode();
        ListNode* wipper = retValue ;
        while(true){
            (wipper -> val) = (sum % 10);
            sum /= 10;
            if(sum > 0){
                wipper = wipper -> next = new ListNode();
            }
            else{
                break;
            }
                
        }    
        return retValue;
    }
private: 
    unsigned long long multiplyTen(unsigned long long n, int numberOfTimes) 
{ 
        while(numberOfTimes > 0){
            n = (n<<1) + (n<<3);
            numberOfTimes--;
        }
    return n; 
}
    unsigned long long GetNumber(ListNode* digits){
        unsigned long long number = 0;
        int numberOfTimes = 0;
        while(digits != nullptr){
            number += multiplyTen((digits -> val), numberOfTimes);
            digits = digits -> next;
            numberOfTimes++;
        }
        return number;
    }
};
