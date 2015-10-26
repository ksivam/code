/**
 * Created by Aarthi on 10/23/15.
 */
public class ReverseSingleList {

    public ReverseSingleList(){

    }

    public Node Reverse(Node head){
        if(head == null){
            return null;
        }

        Node current = head;
        head = null;

        while(current != null){
            Node next = current.Right;

            current.Right = head;
            head = current;

            current = next;
        }

        return head;
    }
}
