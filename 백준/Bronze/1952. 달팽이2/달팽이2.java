
import java.util.*;

class Node {
    int x;
    int y;

    Node(int x,int y) {
        this.x=x;
        this.y=y;
    }
}

public class Main {

    static int ret;
    static int N,M;
    static int dir[][]={{0,1},{1,0},{0,-1},{-1,0}};
    static int visited[][] = new int[104][104];
    static Queue<Node> q = new LinkedList<>();

    static void BFS_iter(int x,int y) {

        int dx,dy;
        int curr_dir=0;
        visited[0][0]=1;
        q.add(new Node(x,y));

        while(!q.isEmpty()) {
            Node temp=q.poll();
            x=temp.x;
            y=temp.y;
//            System.out.println(x+" "+y);

            dx=x+dir[curr_dir][0];
            dy=y+dir[curr_dir][1];

            if(dx<0 || dx>=N || dy<0 || dy>=M || visited[dx][dy]==1) {
                ret+=1;
//                System.out.println();
                curr_dir=(curr_dir+1)%4;
            }

            dx=x+dir[curr_dir][0];
            dy=y+dir[curr_dir][1];

            if(visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.add(new Node(dx,dy));
            }
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();

        BFS_iter(0,0);

        System.out.println(ret-1);
    }
}
