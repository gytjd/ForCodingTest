import java.util.*;

class Solution {
    
    static int M;
    static int ret;
    static int visited[] = new int[10];
    static int temp[][];
    
    static void DFS_recur(int curr,int health) {
        
        ret=Math.max(ret,curr);
        
        for(int i=0;i<M;i++) {
            if(visited[i]==0 && temp[i][0]<=health) {
                visited[i]=1;
                DFS_recur(curr+1,health-temp[i][1]);
                visited[i]=0;
            }
        }
    }
    
    public int solution(int k, int[][] dungeons) {
        
        
        M=dungeons.length;
        temp=dungeons;
        
        DFS_recur(0,k);
        
        return ret;
    }
}