
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    vector<int> v, w;

    while (cin >> N) {
        v.reserve(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        cin >> M;
        w.reserve(M);
        for (int i = 0; i < M; i++) {
            cin >> w[i];
        }
    }

    return 0;
}
