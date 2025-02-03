
import java.util.*;

public class Main {

    static int ret;
    static int N,M;
    static char arr[] = new char[10];
    static int visited[] = new int[10];
    static List<String> v = new ArrayList<>();
    static Set<Character> s = new HashSet<>();

    static HashMap<Character,Integer> m = new HashMap<>();

    static void combi_Recur(int curr,int num) {

        if(curr==M) {
            int temp_Ret=0;
            for(int i=0;i<N;i++) {
                int temp=0;
                for(int j=0;j<v.get(i).length();j++) {
                    temp=temp*10+m.get(v.get(i).charAt(j));
                }
                temp_Ret+=temp;
            }
            if(ret<temp_Ret) ret=temp_Ret;
            return;
        }

        for(int i=0;i<M;i++) {
            if(visited[i]==0) {
                visited[i]=1;
                m.put(arr[i],num);
                combi_Recur(curr+1,num-1);
                visited[i]=0;
                m.remove(arr[i]);
            }
        }
    }
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        for(int i=0;i<N;i++) {
            v.add(in.next());
            for(int j=0;j<v.get(i).length();j++) {
                s.add(v.get(i).charAt(j));
            }
        }

        for(char temp:s) {
            arr[M++]=temp;
        }

        combi_Recur(0,9);
        System.out.println(ret);
    }
}
