import java.util.*;

class Solution {
    
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        int low=0;
        int high=people.length-1;
        
        while(low<=high) {
            if(people[high]+people[low]<=limit) {
                low+=1;
            } 
            high-=1;
            answer+=1;
        }
        
        return answer;
    }
}