import java.util.*;

class Solution {
    
    int arr[][] = new int[204][204];
    int visited[] = new int[204];
    Queue<Integer> q = new LinkedList<>();
    
    void BFS_iter(int start) {
        visited[start]=1;
        q.add(start);
        
        while(!q.isEmpty()) {
            start=q.poll();
            
            for(int i=0;i<arr[start].length;i++) {
                if(start==i) continue;
                
                if(arr[start][i]==1 && visited[i]==0) {
                    visited[i]=1;
                    q.add(i);
                }
            }
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        arr=computers;
        
        for(int i=0;i<n;i++) {
            if(visited[i]==0) {
                BFS_iter(i);
                answer+=1;
            }
        }
        return answer;
    }
}