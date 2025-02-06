import java.util.*;

public class Main {

    static int N;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();

        for(int i=0;i<N;i++) {
            int temp = in.nextInt();
            if(((temp+1)%(temp%100))==0) {
                System.out.println("Good");
            } else {
                System.out.println("Bye");
            }
        }
    }
}
