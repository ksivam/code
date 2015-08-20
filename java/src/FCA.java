import java.util.Stack;

/**
 * Created by Aarthi on 8/4/15.
 * First Common Ancestor
 */
public class FCA {
    private Node root;
    private Stack<Node> stack1;
    private Stack<Node> stack2;
    private  Node result;

    public FCA(Node root){
        this.root = root;
    }

    public int RunWithoutDS(int v1, int v2){
        this.result = null;
        if(this.DFSWithoutDS(root, v1, v2)){
            return result.Data;
        }
        return -1;
    }

    public boolean DFSWithoutDS(Node root, int v1, int v2){
        if(root == null){
            return false;
        }

        // leaf node
        if(root.Data == v1 && root.Data == v2){
            this.result = root;
            return true;
        }

        // v1 and v2 in the same path
        if(root.Data == v1 || root.Data == v2){
            this.result = root;
            return true;
        }

        boolean left = this.DFSWithoutDS(root.Left, v1, v2);
        boolean right = this.DFSWithoutDS(root.Right, v1, v2);

        // v1 and v2 in different path merging at a common node
        if(left && right) {
            this.result = root;
            return true;
        }
        return left || right;
    }

    public int Run(int v1, int v2){
        this.stack1 = new Stack<Node>();
        this.stack2 = new Stack<Node>();

        boolean path1 = this.DFS(this.stack1, this.root, v1);
        boolean path2 = this.DFS(this.stack2, this.root, v2);

        if(!path1 || !path2) {
            // no common ancestor found for v1 and v2
            return -1;
        }

        // trim the two stacks to have same height.
        this.TrimStacks();

        // return the first ancestor.
        return this.FirstAncestor();
    }

    private boolean DFS(Stack<Node> result, Node root, int v) {
        if(root == null){
            // final stage.
            return false;
        }

        result.push(root);

        if(root.Data == v) {
            // found the matching value.
            return true;
        }

        boolean left = this.DFS(result, root.Left, v);
        boolean right = this.DFS(result, root.Right, v);

        if(!left && !right){
            // failed to find a matching value in both subtrees.
            result.pop();
            return false;
        }

        // found a matching value in at least one subtree.
        return true;
    }

    private  void TrimStacks() {
        int len1 = this.stack1.size();
        int len2 = this.stack2.size();

        if(len1 > len2) {
            // stack1 is higher than stack2. so remove the diff from
            // stack1
            int diff = len1 - len2;
            while(diff > 0) {
                this.stack1.pop();
                diff--;
            }
        } else {
            // stack2 is higher than stack1. so remove the diff from
            // stack2
            int diff = len2 - len1;
            while(diff > 0) {
                this.stack2.pop();
                diff--;
            }
        }
    }

    private int FirstAncestor() {
        // pop the nodes from two stack
        while (!this.stack1.isEmpty()){
            Node n1 = this.stack1.pop();
            Node n2 = this.stack2.pop();

            if(n1.Data == n2.Data) {
                // the first matching node
                // is the first common ancestor.
                return n1.Data;
            }
        }

        return -1;
    }
}
