import java.nio.file.Path;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {

        Node ten = new Node(null, null, 10);
        Node eight = new Node(null, null, 8);

        Node six = new Node (null, eight, 6);
        Node seven = new Node (null, null, 7);
        Node three = new Node (six, seven, 3);

        Node four = new Node(null, null, 4);
        Node five = new Node(null, null, 5);
        Node two = new Node (four, five, 2);

        Node one = new Node (two, three, 1);

        // create list at each tree depth
        ListAtEachDepth(one);

        Queue<Node> q = new LinkedList<Node>();
        q.add(one);
        BFS bfs = new BFS(q);
        System.out.println("BFS");
        System.out.println("===");
        bfs.Run();

        Stack<Node> s = new Stack<Node>();
        s.push(one);
        DFS dfs = new DFS(s);
        System.out.println("RunStack");
        dfs.RunStack();
        System.out.println("RunRecursive");
        dfs.RunRecursive(one);


        FCA fca = new FCA(one);
        System.out.println("FCA(4, 7): " + fca.Run(4,7));
        System.out.println("FCA(6, 3): " + fca.Run(6, 3));
        System.out.println("FCA(4, 5): " + fca.Run(4, 5));
        System.out.println("FCA(5, 8): " + fca.Run(5, 8));
        System.out.println("FCA(3, 3): " + fca.Run(3, 3));

        System.out.println("FCA-NoDS(4, 7): " + fca.RunWithoutDS(4, 7));
        System.out.println("FCA-NoDS(6, 3): " + fca.RunWithoutDS(6, 3));
        System.out.println("FCA-NoDS(4, 5): " + fca.RunWithoutDS(4, 5));
        System.out.println("FCA-NoDS(5, 8): " + fca.RunWithoutDS(5, 8));
        System.out.println("FCA-NoDS(3, 3): " + fca.RunWithoutDS(3, 3));

        CheckBST();

        RunAnimalShelter();

        PrintPathSum();
    }

    private static void PrintPathSum() {
        Node two2 = new Node(null, null, 2);
        Node three2 = new Node(null, null, 3);
        Node eight = new Node(null, null, 8);

        Node six = new Node (null, eight, 6);
        Node seven = new Node (null, null, 7);
        Node three = new Node (six, seven, 3);

        Node four = new Node(null, null, 4);
        Node five = new Node(two2, three2, 5);
        Node two = new Node (four, five, 2);

        Node one = new Node (two, three, 1);

        int sum = 11;
        System.out.println("PrintPathSum: " + sum);
        System.out.println("============");
        PathSum pathSum = new PathSum(sum);
        pathSum.Run(one);
    }

    private static void ListAtEachDepth(Node one) {
        ListAtLevel level = new ListAtLevel();
        level.Run(one);

        LinkedList<LinkedList<Node>> ll = level.listAtLevel;

        System.out.println("ListAtEachDepth");
        for(LinkedList<Node> list : ll){
            System.out.println("=============");
            for(Node node : list){
                System.out.print(node.Data + " ");
            }
            System.out.println("");
        }
    }

    private static void CheckBST(){

        // left subtree - bottoms up
        Node two = new Node (null, null, 2);
        Node one = new Node (null, two, 1);

        Node four = new Node(null, null, 4);
        Node three = new Node (one, four, 3);

        // root
        Node five = new Node(three, null, 5);

        // right subtree - bottoms up
        Node ten = new Node(null, null, 10);
        Node nine = new Node(null, ten, 9);

        Node six = new Node (null, null, 6);
        Node seven = new Node (six, null, 7);

        Node eight = new Node(seven, nine, 8);

        IsBST isBst = new IsBST(five);
        System.out.println("isBST " + isBst.Run());
    }

    private static void RunAnimalShelter(){
        AnimalShelter s = new AnimalShelter();

        AnimalShelter.Cat c1 = s.new Cat("c1");
        AnimalShelter.Dog d2 = s.new Dog("d2");
        AnimalShelter.Dog d3 = s.new Dog("d3");
        AnimalShelter.Cat c4 = s.new Cat("c4");
        AnimalShelter.Cat c5 = s.new Cat("c5");
        AnimalShelter.Dog d6 = s.new Dog("d6");

        s.qAny(c1);
        s.qAny(d2);
        s.qDog(d3);
        s.qCat(c4);
        s.qAny(c5);
        s.qDog(d6);

        System.out.println("AnimalShelter");
        System.out.println("=============");

        AnimalShelter.Animal a;
        AnimalShelter.Cat c;
        AnimalShelter.Dog d;

        c = s.dCat();
        System.out.println("Get a cat: " +  (c != null ? c.name: "no cat"));

        a = s.dAny();
        System.out.println("Get any animal: " + (a != null ? a.name : "no animal"));

        a = s.dAny();
        System.out.println("Get any animal: " + (a != null ? a.name : "no animal"));

        d = s.dDog();
        System.out.println("Get a dog: " + (d != null ? d.name: "no dog"));

        a = s.dAny();
        System.out.println("Get any animal: " + (a != null ? a.name : "no animal"));

        c = s.dCat();
        System.out.println("Get a cat: " + (c != null ? c.name: "no cat"));



        d = s.dDog();
        System.out.println("Get a dog: " +  (d != null ? d.name: "no dog"));

        d = s.dDog();
        System.out.println("Get a dog: " +  (d != null ? d.name: "no dog"));

        a = s.dAny();
        System.out.println("Get any animal: " + (a != null ? a.name : "no animal"));

        c = s.dCat();
        System.out.println("Get a cat: " + (c != null ? c.name: "no cat"));

        d = s.dDog();
        System.out.println("Get a dog: " + (d != null ? d.name: "no dog"));

        a = s.dAny();
        System.out.println("Get any animal: " + (a != null ? a.name : "no animal"));

        c = s.dCat();
        System.out.println("Get a cat: " +  (c != null ? c.name: "no cat"));

        d = s.dDog();
        System.out.println("Get a dog: " +  (d != null ? d.name: "no dog"));
    }
}
