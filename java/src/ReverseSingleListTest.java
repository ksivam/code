import org.junit.Test;
import sun.jvm.hotspot.utilities.Assert;

import static org.junit.Assert.*;

/**
 * Created by Aarthi on 10/23/15.
 */
public class ReverseSingleListTest {

    @Test
    public void testReverse() {
        Node head = new Node(null, null, 1);
        head.Right = new Node(null, null, 2);
        head.Right.Right = new Node(null, null, 3);
        head.Right.Right.Right = new Node(null, null, 4);

        ReverseSingleList r = new ReverseSingleList();
        Node result = r.Reverse(head);

        int[] rMatrix = {4,3,2,1};

        int count = 0;
        while(result != null){
            assertEquals(result.Data, rMatrix[count]);

            result = result.Right;
            count++;
        }
    }
}