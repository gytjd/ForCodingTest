import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static int N,ret;
    static HashMap<Character,Boolean> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        N=in.nextInt();
        for(int i=0;i<N;i++) {
            boolean check_Flag=false;
            map.clear();
            String temp=in.next();
            map.put(temp.charAt(0),true);

            for(int j=1;j<temp.length();j++) {
                if(temp.charAt(j)==temp.charAt(j-1)) continue;
                if (map.getOrDefault(temp.charAt(j), false)) {
                    check_Flag = true;
                    break;
                }
                map.put(temp.charAt(j),true);
            }

            if(!check_Flag) ret+=1;
        }
        System.out.println(ret);
    }
}
