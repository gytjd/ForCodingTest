import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int N,findNum,ret;
    static List<Integer> v = new ArrayList<>();
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        for(int i=0;i<N;i++) {
            v.add(in.nextInt());
        }
        findNum=in.nextInt();
        for(int temp:v) {
            if(temp==findNum) {
                ret+=1;
            }
        }
        System.out.println(ret);
    }
}