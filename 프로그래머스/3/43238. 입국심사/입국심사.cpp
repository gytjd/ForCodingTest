#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer =0;
    
    long long low=1;
    long long high=n * (long long)times.back();
    
    while(low<=high) {
        long long mid=(low+high)/2;
        long long curr_Cnt=0;
        for(long long temp:times) {
            curr_Cnt+=mid/temp;
        }
        // cout << low << " " << mid << " " << high << " " << curr_Cnt << "\n";
        
        if(curr_Cnt<n) {
            low=mid+1;
        }
        else { // 4개를 찾아야하는데 4개보다 많음
            answer=mid;
            high=mid-1;
        }
    }
    
    // cout << answer << "\n";
    
    return answer;
}