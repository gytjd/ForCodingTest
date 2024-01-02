#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++) {
        if(n%i==1) {
            if(answer==0) {
                answer=i;
            }
            else {
                min(answer,i);
            }
        }
    }
    return answer;
}