#include <iostream>
#include <vector>

using namespace std;

const int INFINITY = 1000001;

int calculateMinimumNumberOfBlocks(int numberOfBlocks, int length,
                                   vector<int>& blocks) {
    vector<int> dp(length + 1, INFINITY);
    dp[0] = 0;

    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < numberOfBlocks; j++) {
            int remainingLength = i - blocks[j];
            bool canUseBlock = remainingLength >= 0;
            bool hasSolutionForRemainingLength =
                canUseBlock && dp[remainingLength] != INFINITY;

            if (hasSolutionForRemainingLength) {
                dp[i] = min(dp[i], dp[remainingLength] + 1);
            }
        }
    }

    return dp[length];
}

int main() {
    int instancesNumber, numberOfBlocks, length;
    cin >> instancesNumber;

    while (instancesNumber--) {
        cin >> numberOfBlocks >> length;

        vector<int> blocks(numberOfBlocks);
        for (int i = 0; i < numberOfBlocks; ++i) {
            cin >> blocks[i];
        }

        cout << calculateMinimumNumberOfBlocks(numberOfBlocks, length, blocks)
             << endl;
    }

    return 0;
}
