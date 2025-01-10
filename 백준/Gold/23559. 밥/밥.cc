#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, x;
int taste = 0;
vector<pair<int, int> > v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    int a = abs(p1.first - p1.second);
    int b = abs(p2.first - p2.second);
    if (a == b) {
        return p1.second > p2.second;
    }
    return a > b;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
        taste += b;
    }
    sort(v.begin(), v.end(), cmp);
    
    int money = n*1000;
    x -= money;
    for (int i = 0; i < n; i++) {
        if (x <= 0) {
            break;
        }
        if (v[i].first > v[i].second && x >= 4000) {
            taste += v[i].first - v[i].second;
            x -= 4000;
        }
    }
    cout << taste;
    return 0;
}
