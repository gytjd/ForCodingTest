import java.util.*;
public class Main {

    static int N,K;
    static List<Integer> arr = new ArrayList<>();
    static int visited[] = new int[2000004];

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        for(int i=0;i<N;i++) {
            int temp=in.nextInt();
            arr.add(temp);
            visited[temp]=1;
        }
        K = in.nextInt();

        int ret=0;
        for(int i=0;i<N;i++) {
            int temp=arr.get(i);
            if(temp>K) continue;
            if(visited[temp]==1 && visited[K-temp]==1) {
                ret+=1;
            }
        }

        System.out.println(ret/2);
    }
}
