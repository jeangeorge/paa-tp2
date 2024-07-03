#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> fold(vector<int> tape, int position) {
    vector<int> left(tape.begin(), tape.begin() + position);
    vector<int> right(tape.begin() + position, tape.end());

    reverse(right.begin(), right.end());

    if (right.size() > left.size()) {
        for (int i = 0; i < left.size(); i++) {
            right[right.size() - i - 1] += left[left.size() - i - 1];
        }
        return right;
    }

    for (int i = 0; i < right.size(); i++) {
        left[left.size() - i - 1] += right[right.size() - i - 1];
    }

    return left;
}

bool canFold(vector<int> inputTape, vector<int> outputTape) {
    if (inputTape.size() == outputTape.size()) {
        if (inputTape == outputTape) {
            return true;
        }

        vector<int> reversedOutputTape = outputTape;
        reverse(reversedOutputTape.begin(), reversedOutputTape.end());
        return inputTape == reversedOutputTape;
    }

    if (inputTape.size() < outputTape.size()) {
        return false;
    }

    for (int i = 1; i < inputTape.size(); i++) {
        vector<int> foldedTape = fold(inputTape, i);

        if (canFold(foldedTape, outputTape)) {
            return true;
        }
    }

    return false;
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

        if (canFold(inputTape, outputTape)) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
