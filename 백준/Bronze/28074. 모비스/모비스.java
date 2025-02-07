import java.util.*;

public class Main {

    static String temp;
    static HashMap<Character,Integer> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        temp = in.next();

        for(int i=0;i<temp.length();i++) {
            map.put(temp.charAt(i),1);
        }

        if(map.getOrDefault('M',0)==1 && map.getOrDefault('O',0)==1 && map.getOrDefault('B',0)==1 && map.getOrDefault('I',0)==1 && map.getOrDefault('S',0)==1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
