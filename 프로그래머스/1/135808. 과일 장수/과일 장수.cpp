#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int end=score.size()-m;
    sort(score.begin(),score.end());
    
    while(end>=0) {
        answer+=score[end]*m;
        end-=m;
    }
    return answer;
}