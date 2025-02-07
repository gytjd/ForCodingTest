import java.util.*;
class Node {
    long x;
    long y;

    Node(long x,long y) {
        this.x=x;
        this.y=y;
    }
}

public class Main {

    static long N;
    static long Sx,Sy,Ex,Ey;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextLong();
        Sx = in.nextLong();
        Sy = in.nextLong();
        Ex = in.nextLong();
        Ey = in.nextLong();


        long ret_Idx=0;
        long ret_Min=Long.MAX_VALUE;
        for(int i=0;i<N;i++) {
            long temp_N=in.nextLong();
            List<Node> arr = new ArrayList<>();

            arr.add(new Node(Sx,Sy));
            for(int j=0;j<temp_N;j++) {
                arr.add(new Node(in.nextLong(),in.nextLong()));
            }
            arr.add(new Node(Ex,Ey));

            long temp_Num=0;
            for(int j=1;j<temp_N+2;j++) {
                temp_Num+=Math.abs(arr.get(j-1).x-arr.get(j).x)+Math.abs(arr.get(j-1).y-arr.get(j).y);
            }

            if(temp_Num<ret_Min) {
                ret_Min=temp_Num;
                ret_Idx=i+1;
            }
        }

        System.out.println(ret_Idx);
    }
}
