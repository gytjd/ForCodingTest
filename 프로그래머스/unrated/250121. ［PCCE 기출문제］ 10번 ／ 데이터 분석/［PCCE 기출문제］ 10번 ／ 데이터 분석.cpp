#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int ext_num;
int sort_num;

unordered_map<string, int> strToCom = {
    {"code", 0},
    {"date", 1},
    {"maximum", 2},
    {"remain",3}
};

bool cmp(vector<int> &a, vector<int> &b) {
    return a[sort_num] < b[sort_num];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    ext_num = strToCom[ext];
    sort_num = strToCom[sort_by];

    for (vector<int> temp : data) {
        if (temp[ext_num] < val_ext) {
            answer.push_back(temp);
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}