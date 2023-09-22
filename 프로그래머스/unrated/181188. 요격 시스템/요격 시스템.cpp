#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a,vector<int> &b) {
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int temp=-1;
    sort(targets.begin(),targets.end(),cmp);
    
    for(int i=0;i<targets.size();i++) {
        if(temp<=targets[i][0]) {
            temp=targets[i][1];
            answer+=1;
        }
    }
    return answer;
}