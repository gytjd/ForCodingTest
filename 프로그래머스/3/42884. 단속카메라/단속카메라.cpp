#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, start = 0, end = 0;
    sort(routes.begin(),routes.end());
    
    start = routes[0][0];
    end = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(routes[i][0] <= end){
            start = routes[i][0];
            if(routes[i][1] <= end)
                end = routes[i][1];
        }
        else{
            answer++;
            start = routes[i][0];
            end = routes[i][1];
        }
    }
    answer++;
    
    return answer;
}