#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    vector<int> temp;
    sort(d.begin(), d.end());

    temp.push_back(0);
    for (int i = 0; i < d.size(); i++) {
        temp.push_back(d[i]);
    }
    
    for(int i=1;i<temp.size();i++) {
        temp[i]+=temp[i-1];
    }

    int low = 0;
    int high = 1;

    while (high < temp.size()) { // Fix the loop condition
        if (temp[high] - temp[low] <= budget) {
            answer = max(answer, high - low);
            high += 1;
        } else {
            low += 1;
        }
    }

    return answer;
}
