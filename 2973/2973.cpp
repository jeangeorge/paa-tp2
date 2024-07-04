#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_POSSIBLE_TIME = 1000000000;

bool canDivide(const vector<int>& popcornBags, long long maxTime,
               int competitors, int maxPopcornPerSecond) {
    long long popcornsBeingEaten = 0,
              maxPopcorns = maxTime * maxPopcornPerSecond;
    int requiredCompetitors = 1;

    for (int popCornBag : popcornBags) {
        if (popcornsBeingEaten + popCornBag <= maxPopcorns) {
            popcornsBeingEaten += popCornBag;
            continue;
        }

        bool exceededCompetitorsNumber = requiredCompetitors + 1 > competitors;
        bool exceededMaxPopcorns = popCornBag > maxPopcorns;
        if (exceededCompetitorsNumber || exceededMaxPopcorns) {
            return false;
        }

        requiredCompetitors++;
        popcornsBeingEaten = popCornBag;
    }

    return true;
}

int calculateMinTime(int competitors, int maxPopcornsPerSecond,
                     vector<int>& popcorns) {
    int left = 1, right = MAX_POSSIBLE_TIME, answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canDivide(popcorns, mid, competitors, maxPopcornsPerSecond)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    int popcornBagsNumber, competitors, maxPopcornsPerSecond;
    cin >> popcornBagsNumber >> competitors >> maxPopcornsPerSecond;

    vector<int> popcornBags(popcornBagsNumber);
    for (int i = 0; i < popcornBagsNumber; i++) {
        cin >> popcornBags[i];
    }

    cout << calculateMinTime(competitors, maxPopcornsPerSecond, popcornBags)
         << endl;

    return 0;
}
