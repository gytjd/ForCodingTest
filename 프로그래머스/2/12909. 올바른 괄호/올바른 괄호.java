import java.util.*;

class Solution {
    
    static Stack<Character> stk = new Stack<>();
    
    boolean solution(String s) {
        
        boolean answer = false;        
        for(int i=0;i<s.length();i++) {    
            if(stk.isEmpty()) {
                stk.push(s.charAt(i));
            } else {
                if(s.charAt(i)=='(') {
                    stk.push(s.charAt(i));
                } else {
                    if(stk.peek()=='(') {
                        stk.pop();
                    }
                }
            }
        }
        
        if(stk.size()==0) {
            answer=true;
        } else {
            answer=false;
        }

        return answer;
    }
}