import java.util.*;

class Solution {
    
    int cnt;
    char temp[]={'A','E','I','O','U'};
    HashMap<String,Integer> map = new HashMap<>();
    
    void DFS_recur(int curr,String str) {
        
        map.put(str,cnt++);
        
        if(curr==5) {
            return;
        }
        
        for(int i=0;i<5;i++) {
            DFS_recur(curr+1,str+temp[i]);
        }
    }
    public int solution(String word) {
        int answer = 0;
        
        DFS_recur(0,"");
        
        return map.get(word);
    }
}