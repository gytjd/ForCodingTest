import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    static int N;
    static int arr[][];
    static int visited[][];
    static int dir[][]={{0,1},{1,0},{0,-1},{-1,0}};

    public static void init_() {

        arr=new int[1004][1004];
        visited=new int[1004][1004];

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                visited[i][j]=-1;
            }
        }
    }

    public static void display_() {

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                System.out.print(visited[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    public static int dfs_(int x,int y) {

        if(visited[x][y]!=-1) {
            return visited[x][y];
        }

        visited[x][y]=0;
        int dx,dy;
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];

            if(dx<0 || dx>=N || dy<0 || dy>=N) {
                continue;
            }
            if(arr[dx][dy]==arr[x][y]+1) {
                visited[x][y]=Math.max(visited[x][y],dfs_(dx,dy)+1);
            }
        }
        return visited[x][y];
    }

    public static void go_(int test_case) {

        for(int i=0;i<N;i++) {
            for (int j = 0; j < N; j++) {
                dfs_(i, j);
            }
        }

        int minRet=arr[0][0];
        int maxVisited=0;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(visited[i][j]>=maxVisited) {
                    if(visited[i][j]>maxVisited) {
                        maxVisited=visited[i][j];
                        minRet=arr[i][j];
                    } else {
                        minRet = Math.min(minRet, arr[i][j]);
                    }
                }
            }
        }

        System.out.println("#"+test_case+" "+minRet+" "+(maxVisited+1));
    }

    public static void main(String args[]) throws Exception
    {

        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();

        for(int test_case = 1; test_case <= T; test_case++)
        {
            N=sc.nextInt();
            init_();

            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    arr[i][j]=sc.nextInt();
                }
            }

            go_(test_case);
        }
    }
}