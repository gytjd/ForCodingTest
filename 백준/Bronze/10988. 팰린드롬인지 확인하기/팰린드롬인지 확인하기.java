import java.util.Scanner;

public class Main {

    static boolean check_Flag;
    static String temp;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        temp=in.next();
        for(int i=0;i<temp.length()/2;i++) {
            if(temp.charAt(i)!=temp.charAt(temp.length()-i-1)) {
                check_Flag=true;
            }
        }
        
        System.out.println(check_Flag?0:1);
    }
}
