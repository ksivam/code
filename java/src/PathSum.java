import java.util.Stack;

/**
 * Created by Aarthi on 8/20/15.
 */
public class PathSum {

    public Stack<Node> Path = new Stack<Node>();
    private int sum;

    public PathSum(int sum){
        this.sum = sum;
    }

    public void Run(Node root){
        if(root == null) {
            return;
        }

        this.Run1(root, this.sum, new Stack<Node>());
        this.Run(root.Left);
        this.Run(root.Right);

//        int computed = value - root.Data;
//
//        path.push(root);
//
//        if(computed == 0){
//            printPath(path);
//        }
//
//        this.Run(root.Left, computed, path);
//        this.Run1(root, this.sum, new Stack<Node>());
//        this.Run(root.Right, computed, path);
//        this.Run1(root, this.sum, new Stack<Node>());
//
//        path.pop();
    }

    public void Run1(Node root, int value, Stack<Node> path){
        if(root == null) {
            return;
        }

        int computed = value - root.Data;

        path.push(root);

        if(computed == 0){
            printPath(path);
        }

        this.Run1(root.Left, computed, path);
        this.Run1(root.Right, computed, path);

        path.pop();
    }

    private void printPath(Stack<Node> path) {
        System.out.print("\npath: ");
        for (Node node: path){
            System.out.print(node.Data + " ");
        }
        System.out.println();
    }
}
