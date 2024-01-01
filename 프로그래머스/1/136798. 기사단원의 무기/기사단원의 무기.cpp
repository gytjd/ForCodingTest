#include <string>
#include <vector>

#define MAX_NUM 100004

using namespace std;

int count[MAX_NUM];

void init_() {
    for(int i=1;i<MAX_NUM;i++) {
        for(int j=i;j<MAX_NUM;j+=i) {
            count[j]+=1;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    init_();
    for(int i=1;i<=number;i++) {
        if(count[i]>limit) {
            answer+=power;
        }
        else {
            answer+=count[i];
        }
    }
    
    return answer;
}