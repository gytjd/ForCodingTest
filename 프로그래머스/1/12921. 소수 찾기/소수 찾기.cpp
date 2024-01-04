#include <string>
#include <vector>
#define MAX_SIZE 1000004

using namespace std;

int visited[MAX_SIZE];
void init_() {
    visited[0]=1;
    visited[1]=1;
    for(int i=2;i*i<=MAX_SIZE;i++) {
        if(visited[i]==0) {
            for(int j=i*i;j<=MAX_SIZE;j+=i) {
                visited[j]=1;
            }
        }
    }
}
int solution(int n) {
    int answer = 0;
    
    init_();
    
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            answer+=1;
        }
    }
    return answer;
}