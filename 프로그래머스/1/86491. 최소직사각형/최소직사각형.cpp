#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int retA=0,retB=0;
    
    for(vector<int> temp:sizes) {
        if(temp[0]<temp[1]) {
            retA=max(retA,temp[0]);
            retB=max(retB,temp[1]);
        }
        else {
            retA=max(retA,temp[1]);
            retB=max(retB,temp[0]);
        }
    }
    answer=retA*retB;
    return answer;
}