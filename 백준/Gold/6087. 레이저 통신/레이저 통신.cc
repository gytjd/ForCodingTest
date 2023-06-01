#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
pair<int,int> c_pos;
char map[100][100];
int mirror[100][100][4];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

struct Blank {
    int r, c, dir, cnt;
};

int BFS() {
    queue<Blank> q;
    int ans = 987654321;

    for (int i = 0; i < 4; i++) {
        q.push({ c_pos.first, c_pos.second, i, 0 });
        mirror[c_pos.first][c_pos.second][i] = 0;
    }

    while (!q.empty()) {
        int cur_r = q.front().r;
        int cur_c = q.front().c;
        int cur_dir = q.front().dir;
        int cur_cnt = q.front().cnt;
        q.pop();

        if (ans < cur_cnt)    continue;

        if (map[cur_r][cur_c] == 'C' && !(cur_r == c_pos.first && cur_c == c_pos.second))
            ans = cur_cnt;

        for (int i = 0; i < 4; i++) {
            if (i == (cur_dir + 2) % 4)
                continue;
            int rr = cur_r + dr[i];
            int cc = cur_c + dc[i];

            if (rr >= 0 && rr < N && cc >= 0 && cc < M) {
                if (map[rr][cc] != '*') {
                    if (cur_dir == i && cur_cnt < mirror[rr][cc][i]) {
                        mirror[rr][cc][i] = cur_cnt + 1;
                        q.push({ rr,cc,i,cur_cnt });
                    }
                    else if (cur_cnt + 1 < mirror[rr][cc][i]) {
                        mirror[rr][cc][i] = cur_cnt + 1;
                        q.push({ rr,cc,i,cur_cnt + 1 });
                    }
                }
            }
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++) {
            map[i][j] = input[j];
            if (map[i][j] == 'C') {
                c_pos = make_pair(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                mirror[i][j][k] = 987654321;
            }
        }
    }
    
    cout<<BFS()<<"\n";
}
