#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    
    for(int i=food.size()-1;i>0;i--) {
        for(int j=1;j<=food[i]/2;j++) {
            answer=char(i+48)+answer+char(i+48);
        }
    }

    return answer;
}