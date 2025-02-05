import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        int[] answer = {};
        List<Integer> arr = new ArrayList<>();
        List<Integer> temp_Arr = new ArrayList<>();
        
        for(int i=0;i<progresses.length;i++) {
            
            if((100-progresses[i])%speeds[i]!=0) {
                arr.add((100-progresses[i])/speeds[i]+1);
            } else {
                arr.add((100-progresses[i])/speeds[i]);
            }
            
        }
        
        
        int cnt=1;
        int max_Num=arr.get(0);
        for(int i=1;i<arr.size();i++) {
            if(arr.get(i)>max_Num) {
                temp_Arr.add(cnt);
                max_Num=arr.get(i);
                cnt=1;
            } else {
                cnt+=1;
            }
        }
        temp_Arr.add(cnt);
        answer = new int[temp_Arr.size()];
        
        for(int i=0;i<temp_Arr.size();i++) {
            answer[i]=temp_Arr.get(i);
        }
        
        return answer;
    }
}