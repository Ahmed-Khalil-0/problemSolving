/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        
        ListInfo list1 = GetListInfo(headA);         
        ListInfo list2 = GetListInfo(headB);
        
        if(list1.Tail != list2.Tail) return null;
        
        if(list1.Length > list2.Length)
            headA = GetShiftList(headA, list1.Length - list2.Length); 
        else if(list2.Length > list1.Length)
            headB =  GetShiftList(headB, list2.Length - list1.Length); 
        
        while(headA != null && headB != null){
            if(headA == headB)
                return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
    
    private ListInfo GetListInfo(ListNode l)
    {
        int length = 0; 
        while(l != null){
            length++;
            l = l.next;
        }
        return new ListInfo(length,l);
    }
    
    private ListNode GetShiftList(ListNode l, int shiftBy){
        for(int i = 0; i < shiftBy;i++){
            l = l.next;
        }
        return l;
    }
}

public class ListInfo{
    public int Length;
    public ListNode Tail;
    public ListInfo(int length, ListNode tail){
        Length = length;
        Tail = tail;
    }
}
