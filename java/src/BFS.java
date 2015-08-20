import java.util.Queue;

/**
 * Created by Aarthi on 8/3/15.
 */
public class BFS {

    private Queue<Node> q;
    public BFS(Queue<Node> q){
        this.q = q;
    }

public void Run() {
        if(this.q.size() == 0){
            return;
        }

        Node n = this.q.remove();

        Node.Print(n);
        Node.Visit(n);

        if(n.Left != null) {
            this.q.add(n.Left);
        }

        if(n.Right != null) {
            this.q.add(n.Right);
        }

        this.Run();
    }
}
