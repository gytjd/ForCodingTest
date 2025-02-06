import java.util.*;
public class Main {

    static int N;
    static List<Long> dist = new ArrayList<>();
    static List<Long> litter = new ArrayList<>();

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        for(int i=0;i<N-1;i++) {
            dist.add(in.nextLong());
        }
        for(int i=0;i<N;i++) {
            litter.add(in.nextLong());
        }

        long ret=0;
        long min_Litter=987654321;
        for(int i=0;i<N-1;i++) {
            min_Litter=Math.min(min_Litter,litter.get(i));
            ret+=min_Litter*dist.get(i);
        }

        System.out.println(ret);
    }
}
