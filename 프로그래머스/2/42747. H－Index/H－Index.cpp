#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<=1000;i++) {
        int tempA=0;
        for(int j=0;j<citations.size();j++) {
            if(i<=citations[j]) {
                tempA+=1;
            }
        }
        answer=max(answer,min(i,tempA));
    }
    return answer;
}