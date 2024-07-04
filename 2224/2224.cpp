#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Participant {
   public:
    int x, y;
};

const double MAX_POSSIBLE_DISTANCE = 10000.0;

double calculateDistance(Participant &participant1, Participant &participant2) {
    return sqrt(pow(participant1.x - participant2.x, 2) +
                pow(participant1.y - participant2.y, 2));
}

int findFirstUnpaired(int mask, int numberOfParticipants) {
    for (int i = 0; i < numberOfParticipants; i++) {
        bool isUnpaired = !(mask & (1 << i));
        if (isUnpaired) {
            return i;
        }
    }
    return -1;
}

double calculateMinimumDistance(vector<Participant> &participants,
                                int numberOfParticipants) {
    int size = 1 << numberOfParticipants;
    vector<double> dp(size, MAX_POSSIBLE_DISTANCE);
    dp[0] = 0;

    for (int mask = 0; mask < size; mask++) {
        int firstUnpaired = findFirstUnpaired(mask, numberOfParticipants);

        if (firstUnpaired == -1) {
            continue;
        }

        for (int j = firstUnpaired + 1; j < numberOfParticipants; j++) {
            bool isUnpaired = !(mask & (1 << j));
            if (isUnpaired) {
                int newMask = mask | 1 << firstUnpaired | 1 << j;
                double pairCost = calculateDistance(participants[firstUnpaired],
                                                    participants[j]);
                dp[newMask] = min(dp[newMask], dp[mask] + pairCost);
            }
        }
    }

    return dp[size - 1];
}

int main() {
    int instances, numberOfParticipants;

    cin >> instances;

    for (int i = 0; i < instances; i++) {
        cin >> numberOfParticipants;
        vector<Participant> participants(numberOfParticipants);

        for (int j = 0; j < numberOfParticipants; j++) {
            cin >> participants[j].x >> participants[j].y;
        }

        cout << fixed << setprecision(2)
             << calculateMinimumDistance(participants, numberOfParticipants)
             << endl;
    }

    return 0;
}
