/**
 * Created by Aarthi on 8/6/15.
 * Check if binary tree is binary search tree.
 */
public class IsBST {

    private Node root;

    public IsBST(Node root){
        this.root = root;
    }

    public boolean Run(){
        int[] result = this.BST(this.root);

        for(int i = 0; i < result.length-1; i++){
            if(result[i] > result[i+1]){
                return false;
            }
        }

        return true;
    }

    private int[] BST(Node root) {
        if(root == null){
            return new int[0];
        }

        int[] arrL = this.BST(root.Left);
        int[] arrR = this.BST(root.Right);

        int[] result = new int[arrL.length + 1 + arrR.length];
        this.Append(0, result, arrL);
        this.Append(arrL.length, result, new int[]{root.Data});
        this.Append(arrL.length + 1, result, arrR);

        return result;
    }

    private void Append(int startIndex, int[] arr1, int[] arr2){

        for(int i = startIndex, j =0; j < arr2.length; i++, j++){
            arr1[i] = arr2[j];
        }
    }
}
