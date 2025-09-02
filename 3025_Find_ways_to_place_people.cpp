class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (j == i) {
                    continue;
                }
                bool flag = true;
                int topLeftX = points[i][0];
                int topLeftY = points[i][1];

                int bottomRightX = points[j][0];
                int bottomRightY = points[j][1];

                if (topLeftY < bottomRightY) {
                    continue;
                }
                if (topLeftX > bottomRightX) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (points[k][0] >= topLeftX &&
                        points[k][0] <= bottomRightX &&
                        points[k][1] <= topLeftY &&
                        points[k][1] >= bottomRightY) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    count++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return count;
    }
};