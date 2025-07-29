import java.util.*;

class Solution {
    
    static int N,M;
    static int[][]arr=new int[104][104];
    static int[][]visited=new int[104][104];
    static int[][] dir={{0,1},{1,0},{0,-1},{-1,0}};
    static Queue<int[]> q=new LinkedList<>();
    
    public void BFS_iter(int x,int y) {
        
        int dx,dy;
        q.add(new int[]{x,y});
        visited[x][y]=1;
        
        while(!q.isEmpty()) {
            int []temp=q.poll();
            x=temp[0];
            y=temp[1];
            
            for(int i=0;i<4;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(dx<0 || dx>=N || dy<0 || dy>=M || arr[dx][dy]==0) {
                    continue;
                }
                
                if(visited[dx][dy]==0) {
                    visited[dx][dy]=visited[x][y]+1;
                    q.add(new int[]{dx,dy});
                }
            }
        }
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        arr=maps;
        N=maps.length;
        M=maps[0].length;
        
        BFS_iter(0,0);
        answer=visited[N-1][M-1];
        
        
        return answer==0?-1:answer;
    }
}