#include <iostream>

using namespace std;

int N, M, R;
int arr[304][304];

void display_() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate_(int startN, int startM, int endN, int endM, int rotations) {
    int perimeter = 2 * (endN - startN) + 2 * (endM - startM) - 4;
    rotations %= perimeter;

    for (int r = 0; r < rotations; r++) {
        int start_Num = arr[startN][startM];

        
        for (int i = startM; i < endM - 1; i++) {
            arr[startN][i] = arr[startN][i + 1];
        }
        
        for (int i = startN; i < endN - 1; i++) {
            arr[i][endM - 1] = arr[i + 1][endM - 1];
        }
        
        for (int i = endM - 1; i > startM; i--) {
            arr[endN - 1][i] = arr[endN - 1][i - 1];
        }
        
        for (int i = endN - 1; i > startN; i--) {
            arr[i][startM] = arr[i - 1][startM];
        }

        arr[startN + 1][startM] = start_Num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int startN = 0, startM = 0, endN = N, endM = M;
    while (startN < endN && startM < endM) {
        rotate_(startN, startM, endN, endM, R);
        startN++;
        startM++;
        endN--;
        endM--;
    }

    display_();
    return 0;
}

