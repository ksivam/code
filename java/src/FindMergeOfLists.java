/**
 * Created by Aarthi on 10/23/15.
 */
public class FindMergeOfLists {

    public FindMergeOfLists(){

    }

    public Node GetMergeNode(Node headA, Node headB){
        ReverseSingleList reverse = new ReverseSingleList();
        Node a = reverse.Reverse(headA);
        Node b = reverse.Reverse(headB);

        /* method 3:
        - reverse both nodes
        - start from reverse and return the node whose next element diverge.
        */

        Node prev = null;

        // if node a data and node b data are different,
        // then the list has diverged and the prev node
        // is the diverge point.
        while(a != null &&
                b != null &&
                a.Data == b.Data){

            prev = a;
            a = a.Right;
            b = b.Right;
        }

        return prev;
    }
}
