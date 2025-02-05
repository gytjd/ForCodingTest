import java.util.*;


class Solution {

    static int arr[][] = new int[104][104];
    static int visited[] = new int[104];
    static Queue<Integer> q = new LinkedList<>();

    static void display_(int N) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    
    static int BFS_iter(int start,int M) {

        int num_Cnt=0;
        visited[start]=1;
        q.add(start);

        while(!q.isEmpty()) {
            start=q.poll();
            // System.out.println(start);
            num_Cnt+=1;

            for(int i=1;i<=M;i++) {
                if(arr[start][i]==1 && visited[i]==0) {
                    visited[i]=1;
                    q.add(i);
                }
            }
        }

        return num_Cnt;
    }


    public int solution(int n, int[][] wires) {
        int answer = 987654321;

        for(int i=0;i<wires.length;i++) {
            arr[wires[i][0]][wires[i][1]]=1;
            arr[wires[i][1]][wires[i][0]]=1;
        }

        for(int i=0;i<wires.length;i++) {

            Arrays.fill(visited,0);

            arr[wires[i][0]][wires[i][1]]=0;
            arr[wires[i][1]][wires[i][0]]=0;
            
            // System.out.println(wires[i][0]+" "+wires[i][1]);
            // display_(n);
            
            int tempA=0;
            int tempB=0;
            q.clear();
            for(int j=1;j<=n;j++) {
                if(visited[j]==0) {
                    tempA=BFS_iter(j,n);
                    break;
                }
            }
            q.clear();
            for(int j=1;j<=n;j++) {
                if(visited[j]==0) {
                    tempB=BFS_iter(j,n);
                }
            }

            // System.out.println(tempA+" "+tempB);
            answer=Math.min(answer,Math.abs(tempA-tempB));

            arr[wires[i][0]][wires[i][1]]=1;
            arr[wires[i][1]][wires[i][0]]=1;
        }

        return answer;
    }
}