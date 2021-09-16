public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n){
        ListNode fastPointer = head;
        ListNode slowpointer = head;
        for(int i = 0; i < n; i++){
            fastPointer = fastPointer.next;
        }
        if(fastPointer == null){
            head = head.next;
            return head;
        }


        while (fastPointer.next != null){
            fastPointer = fastPointer.next;
            slowpointer = slowpointer.next;
        }
        slowpointer.next = slowpointer.next.next;
        return head;
    }
}


