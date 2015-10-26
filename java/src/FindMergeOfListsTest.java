import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Aarthi on 10/23/15.
 */
public class FindMergeOfListsTest {

    @Test
    public void testGetMergeNode() {

        Node headA = new Node(null, null, 1);
        headA.Right = new Node(null, null, 2);
        headA.Right.Right = new Node(null, null, 3);
        headA.Right.Right.Right = new Node(null, null, 4);

        Node headB = new Node(null, null, 6);
        headB.Right = new Node(null, null, 7);
        headB.Right.Right = new Node(null, null, 8);
        headB.Right.Right.Right = new Node(null, null, 3);
        headB.Right.Right.Right.Right = new Node(null, null, 4);

        FindMergeOfLists merge = new FindMergeOfLists();


        Node result = merge.GetMergeNode(headA, headB);

        assertEquals(result.Data, 3);
    }
}