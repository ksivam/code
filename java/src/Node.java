import java.io.Console;

/**
 * Created by Aarthi on 8/3/15.
 */
public class Node {
    public boolean Visited;
    public int Data;
    public Node Left;
    public Node Right;

    public Node(Node left, Node right, int data) {
        this.Data = data;
        this.Left = left;
        this.Right = right;
    }

    public static void Print(Node node) {
        System.out.println(node.Data);
    }

    public static void Visit(Node node){
        node.Visited = true;
    }
}
