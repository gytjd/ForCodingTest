#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<string> c1;
queue<string> c2;
queue<string> g;

void convertQ(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    for(int i = 0; i < cards1.size(); ++i) {
        c1.push(cards1[i]);
    }

    for(int i = 0; i < cards2.size(); ++i) {
        c2.push(cards2[i]);
    }

    for(int i = 0; i < goal.size(); ++i) {
        g.push(goal[i]);
    }
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    convertQ(cards1, cards2, goal);
    bool isSuccess = true;
    while(!g.empty()) {
        if(g.front().compare(c1.front()) == 0) {
            g.pop();
            c1.pop();
        } else if(g.front().compare(c2.front()) == 0) {
            g.pop();
            c2.pop();
        } else {
            isSuccess = false;
            break;
        }
    }

    if(isSuccess) answer += "Yes";
    else answer += "No";

    return answer;
}