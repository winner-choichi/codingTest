#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int a[N][M];

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            int add;
            cin >> add;
            a[i][j] += add;
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cout << a[i][j] << " ";
        }

        cout << '\n';
    }



    return 0;
}