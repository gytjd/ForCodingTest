import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int a=in.nextInt();

        for(int i=0;i<a;i++) {
            for(int j=a-i-1;j>0;j--) {
                System.out.print(" ");
            }
            for(int j=0;j<i+1;j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}