#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Point {
   public:
    int x, y;
};

double calculateDistance(const Point &point1, const Point &point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

double calculateMinimumDistance(const vector<Point> &points) { return 0; }

int main() {
    int instances, participants;

    cin >> instances;

    for (int i = 0; i < instances; i++) {
        cin >> participants;
        vector<Point> points(participants);

        for (int j = 0; j < participants; j++) {
            cin >> points[j].x >> points[j].y;
        }

        cout << fixed << setprecision(2) << calculateMinimumDistance(points)
             << endl;
    }

    return 0;
}
