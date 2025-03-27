/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int findLength(ListNode[] lists)
    {
        int length = 0;
        for (int i = 0; i < lists.length; i++) {
            ListNode currentListNode = lists[i];
            while (currentListNode != null) {
                length++;
                currentListNode = currentListNode.next;
            }
        }
        return length;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        int length = findLength(lists);
        if (length == 0) {
            return null;
        }

        HashMap<Integer, Integer> hashMap = new HashMap<>();

        for (int i = 0; i < lists.length; i++) {
            ListNode currentListNode = lists[i];
            while (currentListNode != null) {
                hashMap.put(currentListNode.val, hashMap.containsKey(currentListNode.val) ? hashMap.get(currentListNode.val) + 1 : 1);
                currentListNode = currentListNode.next;
            }
        }

        TreeMap<Integer, Integer> sortedMap = new TreeMap<>(hashMap);

        System.out.println(sortedMap);

        ListNode result = null;
        ListNode lastSeen = null;
        ListNode current = null;

        for (Map.Entry<Integer, Integer> entry : sortedMap.entrySet()) {
            Integer value = entry.getKey();
            Integer repeatTimes = entry.getValue();

            for (int i = 0; i < repeatTimes; i++) {
                if (result == null) {
                    result = new ListNode(value);
                    lastSeen = result;
                }
                else {
                    current = new ListNode(value);
                    lastSeen.next = current;
                    lastSeen = current;
                }
            }
        }

        return result;
    }
}
