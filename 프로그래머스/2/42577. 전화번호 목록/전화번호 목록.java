import java.util.*;

class Solution {
    
    static HashMap<String,Integer> map = new HashMap<>();
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        for(int i=0;i<phone_book.length;i++) {
            map.put(phone_book[i],i+1);
        }
        
        for(int i=0;i<phone_book.length;i++) {
            String temp="";
            
            for(int j=0;j<phone_book[i].length();j++) {
                temp+=phone_book[i].charAt(j);
                
                if(map.get(temp)==null) continue;
                if(map.get(temp)!=i+1) answer=false;
            }
        }
        return answer;
    }
}