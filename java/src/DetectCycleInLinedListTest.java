import junit.framework.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Aarthi on 10/23/15.
 */
public class DetectCycleInLinedListTest {

    @Test
    public void testHasCycle() {
        DetectCycleInLinedList cycle = new DetectCycleInLinedList();

        Node head = new Node(null, null, 1);
        head.Right = new Node(null, null, 2);
        head.Right.Right = new Node(null, null, 3);
        head.Right.Right.Right = new Node(null, null, 4);
        head.Right.Right.Right.Right = head.Right.Right;

        int shdHaveCycle = cycle.HasCycle(head);
        Assert.assertEquals(shdHaveCycle, 1);


        head.Right.Right.Right.Right = null;
        int shdNotHaveCycle = cycle.HasCycle(head);
        Assert.assertEquals(shdNotHaveCycle, 0);
    }
}