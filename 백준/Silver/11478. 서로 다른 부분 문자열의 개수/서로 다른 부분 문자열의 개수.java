
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static String temp;
    static int ret;
    static HashMap<String,Boolean> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        temp=in.next();

        for(int i=0;i<temp.length()+1;i++) {
            for(int j=i+1;j<temp.length()+1;j++) {

                if(map.get(temp.substring(i,j))==null) {
                    map.put(temp.substring(i,j),true);
                    ret+=1;
                }
            }
        }
        System.out.println(ret);
    }
}
