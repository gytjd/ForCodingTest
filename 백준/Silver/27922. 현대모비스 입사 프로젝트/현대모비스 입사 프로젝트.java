import java.util.*;

public class Main {

    static int N,M;
    static List<Integer> arrA = new ArrayList<>();
    static List<Integer> arrB = new ArrayList<>();
    static List<Integer> arrC = new ArrayList<>();

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        M=in.nextInt();

        for(int i=0;i<N;i++) {
            int tempA = in.nextInt();
            int tempB = in.nextInt();
            int tempC = in.nextInt();
            arrA.add(tempA+tempB);
            arrB.add(tempA+tempC);
            arrC.add(tempB+tempC);
        }
        Collections.sort(arrA,Collections.reverseOrder());
        Collections.sort(arrB,Collections.reverseOrder());
        Collections.sort(arrC,Collections.reverseOrder());

        int retA=0;
        int retB=0;
        int retC=0;
        for(int i=0;i<M;i++) {
            retA+=arrA.get(i);
            retB+=arrB.get(i);
            retC+=arrC.get(i);
        }
        System.out.println(Math.max(Math.max(retA,retB),retC));
    }
}
