
import java.util.Scanner;

public class Main {

    static int N,M;
    static int A[][]= new int[104][104];
    static int B[][]= new int[104][104];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        M=in.nextInt();
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                A[i][j]=in.nextInt();
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                B[i][j]=in.nextInt();
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                System.out.print(A[i][j]+B[i][j]+" ");
            }
            System.out.println();
        }
    }
}
