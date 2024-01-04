#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int temp_N;

bool cmp(string &a,string &b) {
    if(a[temp_N]==b[temp_N]) {
        return a<b;
    }
    return a[temp_N]<b[temp_N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    temp_N=n;
    
    sort(strings.begin(),strings.end(),cmp);
    for(string temp:strings) {
        answer.push_back(temp);
    }
    return answer;
}