
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Stone {
   public:
    char size;
    int position;
};

int calculateMaxDistance() { return 1; }

int main() {
    int numberOfTestCases, numberOfStones, distance;

    cin >> numberOfTestCases;

    for (int testCase = 1; testCase <= numberOfTestCases; testCase++) {
        cin >> numberOfStones >> distance;
        vector<Stone> stones(numberOfStones);

        for (int i = 0; i < numberOfStones; i++) {
            cin >> stones[i].size;
            cin.ignore(1, '-');
            cin >> stones[i].position;
        }

        cout << "Case " << testCase << ": " << calculateMaxDistance();
    }

    return 0;
}
