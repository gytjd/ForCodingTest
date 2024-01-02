#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer = {0, 0};
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            answer[0]++;
            continue;
        }
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                answer[1]++;
                break;
            }
        }
    }
    return answer = {7 - answer[0] - answer[1] > 6 ? 6 : 7 - answer[0] - answer[1], 7 - answer[1] > 6 ? 6 : 7 - answer[1]};
}