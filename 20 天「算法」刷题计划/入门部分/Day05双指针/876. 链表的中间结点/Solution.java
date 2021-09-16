public class Solution {

    public ListNode middleNode(ListNode head) {
        ListNode fastPointer = head;
        ListNode slowPointer = head;

        while(fastPointer.next != null){
            fastPointer = fastPointer.next;
            if(fastPointer.next != null){
                fastPointer = fastPointer.next;
            }
            slowPointer = slowPointer.next;
        }

        return slowPointer;
    }
}
