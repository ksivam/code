/**
 * Created by Aarthi on 10/23/15.
 */
public class DetectCycleInLinedList {
    public DetectCycleInLinedList(){
    }

    public int HasCycle(Node root){
        if(root == null){
            return 0;
        }
        Node sp = root;

        if(sp.Right == null){
            return 0;
        }
        Node fp = sp.Right.Right;

        while(fp != null){
            if(sp.Data == fp.Data){
                return 1;
            }

            sp = sp.Right;
            fp = fp.Right;
        }

        return 0;
    }
}
