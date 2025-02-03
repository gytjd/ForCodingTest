
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    static String temp;
    static List<Integer> v = new ArrayList<>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        temp=in.next();
        for(int i=0;i<temp.length();i++) {
            v.add(temp.charAt(i)-'0');
        }
        Collections.sort(v,Collections.reverseOrder());
        for(int a:v) {
            System.out.print(a);
        }
    }
}
