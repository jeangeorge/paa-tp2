#include <iostream>
#include <vector>

using namespace std;

bool canFold(vector<int>& inputTape, vector<int>& outputTape, int inputStart,
             int inputEnd, int outputStart, int outputEnd) {
    return true;
}

int main() {
    int inputTapeSize, outputTapeSize;
    vector<int> inputTape, outputTape;

    while (cin >> inputTapeSize) {
        inputTape.resize(inputTapeSize);
        for (int i = 0; i < inputTapeSize; i++) {
            cin >> inputTape[i];
        }

        cin >> outputTapeSize;
        outputTape.resize(outputTapeSize);
        for (int i = 0; i < outputTapeSize; i++) {
            cin >> outputTape[i];
        }

        if (canFold(inputTape, outputTape, 0, inputTapeSize, 0,
                    outputTapeSize)) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
