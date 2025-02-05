import java.util.*;

public class Solution {
    
    static Stack<Integer> s = new Stack<>();
    
    public int[] solution(int []arr) {
        int[] answer = {};
        
        s.push(arr[0]);
        for(int i=1;i<arr.length;i++) {
            if(s.peek()!=arr[i]) {
                s.push(arr[i]);
            }
        }
        
        answer = new int[s.size()];
        while(!s.empty()) {
            answer[s.size()-1]=s.peek();
            s.pop();
        }
        return answer;
    }
}