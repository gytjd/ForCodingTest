import java.util.*;

class Solution {
    
    
    public String solution(int[] numbers) {
        String answer = "";
        
        List<String> arr = new ArrayList<>();
        for(int i=0;i<numbers.length;i++) {
            arr.add(Integer.toString(numbers[i]));
        }
        
        Collections.sort(arr,new Comparator<String>() {
            
            @Override
            public int compare(String a,String b) {
                String tempA=a+b;
                String tempB=b+a;
                return tempB.compareTo(tempA);
            }
        });
        
        for(String temp:arr) {
            answer+=temp;
        }
        
        if(answer.charAt(0)=='0') {
            return "0";
        } else {
            return answer;
        }
    }
}