import java.util.*;

class Node {
    int idx;
    int gold;
    int silver;
    int brown;

    Node(int idx,int gold,int silver,int brown) {
        this.idx=idx;
        this.gold=gold;
        this.silver=silver;
        this.brown=brown;
    }
}

public class Main {

    static int N,M;
    static List<Node> arr = new ArrayList<>();
    static int ret[] = new int[1004];

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();

        for(int i=0;i<N;i++) {
            int idx,gold,silver,brown;
            idx=in.nextInt();
            gold=in.nextInt();
            silver=in.nextInt();
            brown=in.nextInt();
            arr.add(new Node(idx,gold,silver,brown));
        }

        Collections.sort(arr,new Comparator<Node>() {
            @Override
            public int compare(Node a,Node b) {
                if(a.gold==b.gold) {
                    if(a.silver==b.silver) {
                        return b.brown-a.brown;
                    }
                    return b.silver-a.silver;
                }
                return b.gold-a.gold;
            }
        });

        int cnt=1;
        ret[arr.get(0).idx]=cnt;
        for(int i=1;i<N;i++) {
//            System.out.println(arr.get(i).idx+" "+arr.get(i).gold+" "+arr.get(i).silver+" "+arr.get(i).brown);
            if(arr.get(i-1).gold==arr.get(i).gold && arr.get(i-1).silver==arr.get(i).silver && arr.get(i-1).brown==arr.get(i).brown) {
                ret[arr.get(i).idx]=ret[arr.get(i-1).idx];
            } else {
                ret[arr.get(i).idx]=i+1;
            }
        }

        System.out.println(ret[M]);
    }
}
