import java.util.Stack;

/**
 * Created by Aarthi on 8/3/15.
 */
public class DFS {

    private Stack<Node> s;


    public DFS(Stack<Node> s) {
        this.s = s;
    }

    public void RunStack(){
        if(this.s.size() == 0){
            return;
        }

        Node n = this.s.pop();

        Node.Print(n);
        Node.Visit(n);

        if(n.Right != null) {
            this.s.push(n.Right);
        }

        if(n.Left != null) {
            this.s.push(n.Left);
        }

        this.RunStack();
    }

    public void RunRecursive(Node root){
        if(root == null){
            return;
        }

        Node.Print(root);
        Node.Visit(root);

        this.RunRecursive(root.Left);
        this.RunRecursive(root.Right);
    }
}
