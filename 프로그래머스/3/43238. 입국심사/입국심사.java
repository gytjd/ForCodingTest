import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 987654321;
        
        long low=1;
        long high=n*(long)times[times.length-1];
        
        // System.out.println(low+" "+high);
        
        while(low<=high) {
            // System.out.println(low+" "+high);
            long mid=(low+high)/2;
            long cnt=0;
            
            for(int i=0;i<times.length;i++) {
                cnt+=mid/times[i];
            }
            
            if(cnt>=n) {
                answer=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return answer;
    }
}