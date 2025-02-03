import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int N;
    static char arr[];
    static int visited[]=new int[10];

    static List<String> v = new ArrayList<>();

    static void DFS_recur(int start,int end,int curr,String num) {

        if(curr==N+1) {
            v.add(num);
            return;
        }

        for(int i=start;i<end;i++) {

            if(visited[i]==0) {
                visited[i]=1;

                if(curr==N) {
                    DFS_recur(start,end,curr+1,num+Integer.toString(i));
                } else {
                    if(arr[curr]=='<') {
                        DFS_recur(i+1,10,curr+1,num+Integer.toString(i));
                    } else {
                        DFS_recur(0,i,curr+1,num+Integer.toString(i));
                    }
                }
                visited[i]=0;
            }
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N=in.nextInt();
        arr=new char[N];

        for(int i=0;i<N;i++) {
            arr[i]=in.next().charAt(0);
        }
        DFS_recur(0,10,0,"");
        Collections.sort(v);
        System.out.println(v.get(v.size()-1));
        System.out.println(v.get(0));
    }
}
