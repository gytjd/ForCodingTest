#include <vector>
#include <set>
using namespace std;

set<int> s;

int solution(vector<int> nums)
{
    for(int temp:nums) {
        s.insert(temp);
    }
    
    if(s.size()>nums.size()/2) {
        return nums.size()/2;
    } else {
        return s.size();
    }
    
    return s.size();
}