import java.util.*;

class Solution {
    
    int visited[] = new int[34];
    int lost_visited[] = new int[34];
    
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        for(int i=0;i<lost.length;i++) {
            lost_visited[lost[i]]=1;
        }
        
        for(int i=1;i<=n;i++) {
            if(lost_visited[i]==1) continue;
            visited[i]=1;
        }
        
        for(int i=0;i<reserve.length;i++) {
            if(lost_visited[reserve[i]]==1) {
                lost_visited[reserve[i]]=0;
                visited[reserve[i]]=2;
            }
        }
        Arrays.sort(reserve);
        
        for(int i=0;i<reserve.length;i++) {
            
            if(visited[reserve[i]]==2) continue;
            
            if(lost_visited[reserve[i]]==1) {
                lost_visited[reserve[i]]=0;
                visited[reserve[i]]=1;
                continue;
            }
            
            if(reserve[i]==1) {
                if(lost_visited[reserve[i]+1]==1) {
                    lost_visited[reserve[i]+1]=0;
                    visited[reserve[i]+1]=1;
                }
            } else if(reserve[i]==n) {
                if(lost_visited[reserve[i]-1]==1) {
                    lost_visited[reserve[i]-1]=0;
                    visited[reserve[i]-1]=1;
                }
            } else {
                if(lost_visited[reserve[i]-1]==1) {
                    lost_visited[reserve[i]-1]=0;
                    visited[reserve[i]-1]=1;
                } else {
                    if(lost_visited[reserve[i]+1]==1) {
                        lost_visited[reserve[i]+1]=0;
                        visited[reserve[i]+1]=1;
                    }
                }
            }
        }
        
        for(int i=1;i<=n;i++) {
            if(visited[i]==1 || visited[i]==2) {
                answer+=1;
            }
        }
        return answer;
    }
}