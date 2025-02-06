import java.util.*;

class Node {
    int first;
    int second;

    Node(int first,int second) {
        this.first=first;
        this.second=second;
    }
}

public class Main {

    static int N,M;
    static int cnt=0;
    static List<Node> arr = new ArrayList<>();

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();

        for(int i=0;i<N;i++) {
            int tempA = in.nextInt();
            int tempB = in.nextInt();

            if(tempA>tempB) {
                cnt+=1;
            } else {
                arr.add(new Node(tempA,tempB));
            }
        }

        Collections.sort(arr,new Comparator<Node>() {
            @Override
            public int compare(Node a,Node b) {
                return (a.second-a.first)-(b.second-b.first);
            }
        });

//        for(int i=0;i<arr.size();i++) {
//            System.out.println(arr.get(i).first+" "+arr.get(i).second);
//        }

        if(cnt>=M) {
            System.out.println(0);
        } else {
//            System.out.println(arr.get(M-cnt).second+" "+arr.get(M-cnt).first);
            System.out.println(arr.get(M-cnt-1).second-arr.get(M-cnt-1).first);
        }

    }
}
