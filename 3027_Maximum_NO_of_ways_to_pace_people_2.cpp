class Solution {
public:

    static bool check(vector<int> a,vector<int> b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),check);

        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int top = points[i][1];
            int bottom = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int y = points[j][1];
                if (bottom < y && y <= top) {
                    ans++;
                    bottom = y;
                    if (bottom == top) break;
                }
            }
        }
        return ans;
    }
};