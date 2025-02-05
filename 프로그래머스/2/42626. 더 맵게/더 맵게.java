import java.util.*;

class Solution {
    
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        for(int i=0;i<scoville.length;i++) {
            pq.add(scoville[i]);
        }
        
        
        while(pq.size()>=2) {
            int first=pq.poll();
            int second=pq.poll();
            // System.out.println(first+" "+second);
            if(first>=K) {
                return answer;
            }
            answer+=1;
            pq.add(first+second*2);
        }
        
        if(pq.poll()>=K) {
            return answer;
        } else {
            return -1;
        }
    }
}