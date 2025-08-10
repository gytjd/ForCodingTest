

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int N,M;

    static int ret;
    static List<Integer> v[];
    static int visited[]=new int[504];

    public static void init_() {

        v=new LinkedList[N+1];
        for(int i=1;i<=N;i++) {
            v[i]=new LinkedList<>();
        }
    }

    public static void BFS_iter(int start) {
        Queue<Integer> q=new LinkedList<>();
        q.add(start);
        visited[start]=1;

        while(!q.isEmpty()) {
            start=q.poll();

            for(int temp:v[start]) {
                if(visited[temp]==0) {
                    visited[temp]=visited[start]+1;

                    if(visited[temp]==2 || visited[temp]==3) {
                        ret += 1;
                    }
                    q.add(temp);
                }
            }
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();

        init_();

        for (int i = 0; i < M; i++) {
            int start, end;
            start = in.nextInt();
            end = in.nextInt();
            v[start].add(end);
            v[end].add(start);
        }

        BFS_iter(1);

        System.out.println(ret);
    }
}
