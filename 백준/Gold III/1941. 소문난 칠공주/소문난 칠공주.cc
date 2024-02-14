#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include <tuple>

using namespace std;

int map[5][5], answer;
bool sel[25];

bool visited[5][5];
bool cmap[5][5];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool more4() {
    int cnt = 0;
    for (int i = 0; i < 25; i++) { // 배열을 순회한다.
        if (sel[i]) {
            int x = i / 5; //행
            int y = i % 5; //열
            if (map[x][y] == 2) cnt++;
        }
    }
    if (cnt >= 4) return true;
    else return false;
}

bool adjacency() {
    memset(cmap, false, sizeof(cmap));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    bool flag = false;

    bool firstFlag = 0;
    for (int i = 0; i < 25; i++) {
        if (sel[i]) { // 만약 선택 되면
            int x = i / 5; // 행
            int y = i % 5; // 열
            visited[x][y] = true; //방문 표시

            if (!firstFlag) { //시작을 정해 준다.
                q.push(make_pair(x, y));
                cmap[x][y] = true;
                firstFlag = 1;
            }
        }
    }
    
    

    int cnt = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (cnt == 7) return true; // 종료 조건
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny] && !cmap[nx][ny]) {
                cmap[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt += 1;
            }
        }
    }

    return false;
}

void go(int index, int cnt) {
    if (cnt == 7) {  // 종료조건
        if (more4() && adjacency()) answer += 1; //문제 조건 4이상이고 근접해야 한다.
        return;
    }
    if (index >= 25) return; // 25이상이면 종료한다.

    //조합을 구성하는 방법
    sel[index] = true;
    go(index + 1, cnt + 1);
    sel[index] = false;

    go(index + 1, cnt);
}

int main(void) {

    for (int i = 0; i < 5; i++) { // string 으로 입력을 받는다.
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'Y') map[i][j] = 1; // Y 이면 1
            if (s[j] == 'S') map[i][j] = 2; // S 이면 1
        }
    }

    go(0, 0); // 재귀 시작
    cout << answer << '\n';

    return 0;
}
