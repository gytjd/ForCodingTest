import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        List<Integer> arr = new ArrayList<>();
        for(int i=0;i<citations.length;i++) {
            arr.add(citations[i]);
        }
        Collections.sort(arr);
        
        for(int i=0;i<=1000;i++) {
            int tempA=0;
            for(int j=0;j<citations.length;j++) {
                if(i<=citations[j]) {
                    tempA+=1;
                }
            }
            answer=Math.max(answer,Math.min(i,tempA));
        }
        
        return answer;
    }
}