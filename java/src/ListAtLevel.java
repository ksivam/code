import com.sun.tools.javac.util.List;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Aarthi on 8/19/15.
 * Create a list at every level of binary tree
 * ie. if a binary tree has m levels, then create m list at each level.
 */
public class ListAtLevel {

    public LinkedList<LinkedList<Node>> listAtLevel = new LinkedList<LinkedList<Node>>();
    private Queue<Node> q = new LinkedList<Node>();
    private Node marker = new Node(null, null, -1);

    public ListAtLevel() {
    }

    public void Run(Node root) {
        q.add(root);
        q.add(marker);

        Node current;
        LinkedList<Node> level = new LinkedList<Node>();

        while(!q.isEmpty()){
            current = q.remove();

            if(current.Data != -1){
                level.add(current);
            }

            if(current.Left != null){
                q.add(current.Left);
            }

            if(current.Right != null) {
                q.add(current.Right);
            }

            if(current.Data == -1){
                listAtLevel.add(level);
                level = new LinkedList<Node>();

                if(q.size() > 0) {
                    q.add(current);
                }
            }
        }
    }
}
