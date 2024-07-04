#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Stone {
   public:
    char size;
    int position;

    Stone(char size, int position) : size(size), position(position) {}
};

int calculateMaxJump(vector<Stone>& stones, int distance) {
    int maxJump = 0;

    for (int i = 0; i < stones.size(); i++) {
        if (i + 1 < stones.size() && stones[i + 1].size == 'B') {
            maxJump = max(maxJump, stones[i + 1].position - stones[i].position);
        } else if (i + 2 < stones.size()) {
            maxJump = max(maxJump, stones[i + 2].position - stones[i].position);
        }

        if (i + 2 < stones.size() && stones[i + 2].size == 'B') {
            maxJump =
                max(maxJump, stones[i + 2].position - stones[i + 1].position);
        } else if (i + 3 < stones.size()) {
            maxJump =
                max(maxJump, stones[i + 3].position - stones[i + 1].position);
        }
    }

    return maxJump;
}

int main() {
    int numberOfTestCases, numberOfStones, distance;

    cin >> numberOfTestCases;

    for (int testCase = 1; testCase <= numberOfTestCases; testCase++) {
        cin >> numberOfStones >> distance;
        vector<Stone> stones;

        stones.insert(stones.begin(), Stone('B', 0));

        for (int i = 0; i < numberOfStones; i++) {
            char size;
            int position;
            cin >> size;
            cin.ignore(1, '-');
            cin >> position;
            stones.push_back(Stone(size, position));
        }

        stones.push_back(Stone('B', distance));

        cout << "Case " << testCase << ": "
             << calculateMaxJump(stones, distance) << endl;
    }

    return 0;
}
