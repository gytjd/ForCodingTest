import java.util.*;

class Node {
    int score;
    String name;

    Node(int score,String name) {
        this.score=score;
        this.name=name;
    }
}

public class Main {

    static List<Integer> retA = new ArrayList<>();
    static List<Node> retB = new ArrayList<>();

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        for(int i=0;i<3;i++) {
            int tempA=in.nextInt();
            int tempB=in.nextInt();
            String tempC=in.next();

            retA.add(tempB%100);
            retB.add(new Node(tempA,tempC));
        }

        Collections.sort(retA);
        Collections.sort(retB, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o2.score-o1.score;
            }
        });

        for(int i=0;i<3;i++) {
            System.out.print(retA.get(i));
        }
        System.out.println();
        for(int i=0;i<3;i++) {
            System.out.print(retB.get(i).name.charAt(0));
        }
        System.out.println();
    }
}
