import java.util.*;

class Node {
    int x;
    int y;

    Node(int x,int y) {
        this.x=x;
        this.y=y;
    }
}

class Solution {
    public int solution(int[][] sizes) {
        

        List<Node> arr = new ArrayList<>();

        for(int i=0;i<sizes.length;i++) {
            if(sizes[i][0]>sizes[i][1]) {
                arr.add(new Node(sizes[i][0],sizes[i][1]));
            } else {
                arr.add(new Node(sizes[i][1],sizes[i][0]));
            }
        }
        
        int tempA=0;
        int tempB=0;
        for(int i=0;i<arr.size();i++) {
            tempA=Math.max(tempA,arr.get(i).x);
            tempB=Math.max(tempB,arr.get(i).y);
        }
        
        return tempA*tempB;
    }
}