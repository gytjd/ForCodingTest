import java.util.*;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        List<Integer> ret = new ArrayList<>();
        
        for(int i=0;i<commands.length;i++) {
            List<Integer> temp = new ArrayList<>();
            for(int j=commands[i][0]-1;j<commands[i][1];j++) {
                temp.add(array[j]);
            }
            Collections.sort(temp);
            ret.add(temp.get(commands[i][2]-1));
        }
        return ret;
    }
}