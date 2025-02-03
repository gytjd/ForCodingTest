
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static class Node {
        int x;
        int y;

        // Node 객체 생성 시 초기화
        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int ret;
    static int N,M;
    static int dir[][]={{0,1},{1,0},{0,-1},{-1,0}};
    static int arr[][] = new int[1004][1004];
    static int visited[][] = new int[1004][1004];
    static Queue<Node> q = new LinkedList<>();

    static void display_() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                System.out.print(visited[i][j]+" ");
            }
            System.out.println();
        }
    }

    static int check_() {

        int max_Ret=0;
        boolean check_Flag=false;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(arr[i][j]==0 && visited[i][j]==0) {
                    check_Flag=true;
                } else {
                    if(max_Ret<visited[i][j]) {
                        max_Ret=visited[i][j];
                    }
                }
            }
        }

        if(check_Flag) {
            return -1;
        } else {
            return max_Ret-1;
        }
    }
    static void BFS_iter() {

        int x,y;
        int dx,dy;

        while(!q.isEmpty()) {
            Node temp=q.poll();
            x=temp.x;
            y=temp.y;

            for(int i=0;i<4;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];

                if(dx<0 || dx>=N || dy<0 || dy>=M) {
                    continue;
                }

                if(visited[dx][dy]==0 && arr[dx][dy]==0) {
                    visited[dx][dy]=visited[x][y]+1;
                    q.add(new Node(dx,dy));
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        M=in.nextInt();
        N=in.nextInt();

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                arr[i][j]=in.nextInt();
                if(arr[i][j]==1) {
                    q.add(new Node(i,j));
                    visited[i][j]=1;
                }
            }
        }

        BFS_iter();
        System.out.println(check_());
    }
}
