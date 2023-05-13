#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[3] = {a, b, c};
    sort(arr, arr + 3); // 입력받은 세 변의 길이를 오름차순으로 정렬합니다.

    if (arr[0] + arr[1] > arr[2]) { // 삼각형을 만들 수 있는 경우
        cout << a + b + c << endl; // 세 변의 합이 삼각형의 둘레가 됩니다.
    } else { // 삼각형을 만들 수 없는 경우
        cout << (arr[0] + arr[1]) * 2-1 << endl; // 가장 긴 변을 다른 두 변의 합으로 대체하여 둘레를 구합니다.
    }

    return 0;
}
