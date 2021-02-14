/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    
public:
    Node* flatten(Node* head) {
        static int functionCall = 0;
       // bool lock = false;
        Node* wipper = head;
        if(head == nullptr)
            return head;
        
        while(true){
            if((wipper -> child) != nullptr){
                functionCall++;
                Node* childishPointer = flatten(wipper -> child);
                if(childishPointer != nullptr){
                    childishPointer -> next = wipper -> next;
                    if(childishPointer -> next != nullptr)
                        (childishPointer -> next) -> prev = childishPointer;
                    wipper -> next = wipper -> child;
                    (wipper -> child)->prev = wipper;
                    
                    wipper -> child = nullptr;
                }
            }
            if(wipper -> next != nullptr)
                wipper = wipper -> next;
            else if(wipper -> next == nullptr)
                break;
        }
        if(functionCall > 0){
            functionCall--;
           return wipper;
        }
        else
            return head;
    }
};
