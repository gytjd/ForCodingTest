import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int N,M;
    static List<Integer> v = new ArrayList<>();

    static void display_() {
        for(int temp:v) {
            System.out.print(temp+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        M=in.nextInt();
        for(int i=1;i<=N;i++) {
            v.add(i);
        }
        for(int i=0;i<M;i++) {
            int first=in.nextInt();
            int second=in.nextInt();
            Collections.reverse(v.subList(first-1,second));
        }
        display_();
    }
}