import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Node {
        int x,y,d,g;
        public Node(int x, int y, int d, int g) {
            this.x=x;
            this.y=y;
            this.d=d;
            this.g=g;
        }
    }
    
    static int N;
    static int tot;
    static int dir[][]={{0,1},{-1,0},{0,-1},{1,0}};
    static int arr[][]=new int[104][104];
    static List<Node> v=new ArrayList<>();
    
    public static void display_() {

        for(int i=0;i<100;i++) {
            for(int j=0;j<100;j++) {

                if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j]==1 && arr[i+1][j+1]==1) {
                    tot+=1;
                }
            }
        }
    }
    public static void draw_(int x,int y,int d,int g) {

        int dx,dy;
        List<Integer> ret=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();

        arr[x][y]=1;
        dx=x+dir[d][0];
        dy=y+dir[d][1];
        arr[dx][dy]=1;
        ret.add(d);

        for(int i=0;i<g;i++) {

            temp.clear();
            for (int j = ret.size() - 1; j >= 0; j--) {

                int temp_Dir=(ret.get(j)+1)%4;
                dx = dx + dir[temp_Dir][0];
                dy = dy + dir[temp_Dir][1];
                arr[dx][dy] = 1;
                temp.add(temp_Dir);
            }
            for (int j = 0; j < temp.size(); j++) {
                ret.add(temp.get(j));
            }
        }
    }
    public static void go_() {
        for(int i=0;i<N;i++) {
            draw_(v.get(i).y,v.get(i).x,v.get(i).d,v.get(i).g);
        }
        display_();
        System.out.println(tot);
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        N=in.nextInt();

        for(int i=0;i<N;i++) {
            int x,y,d,g;
            x=in.nextInt();
            y=in.nextInt();
            d=in.nextInt();
            g=in.nextInt();
            v.add(new Node(x,y,d,g));
        }

        go_();
    }
}
