#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1000000
using namespace std;
int n, input[N], position[N] = { 0 }, before[N] = { -1, }, i, x, pointer, answer[N];
vector<int> list;
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++)scanf("%d", input + i);
    list.push_back(input[0]);
    for (i = 1; i < n; i++) {
        if (list[list.size() - 1] < input[i]) {
            position[list.size()] = i;
            before[i] = position[list.size() - 1];
            list.push_back(input[i]);
        }
        else {
            x = lower_bound(list.begin(), list.end(), input[i]) - list.begin();
            list[x] = input[i];
            position[x] = i;
            before[i] = x ? position[x - 1] : -1;
        }
    }
    printf("%d\n", list.size());
    pointer = position[list.size() - 1];
    x = 0;
    while (pointer > -1) {
        answer[x++] = input[pointer];
        pointer = before[pointer];
    }
    for (i = list.size() - 1; i > -1; i--) printf("%d ", answer[i]);
}