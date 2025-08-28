class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();

        vector<int> traffic(1002, 0);
 int maxi =0;

        for (auto i : trips) {
            int l = i[1];
            int r = i[2];
             maxi =max(maxi,i[0]);
            traffic[r] -= i[0];
            traffic[l] += i[0];
        }

       
        for(int i=1;i<=1000;i++){
            traffic[i]+=traffic[i-1];
            maxi =max(maxi,traffic[i]);
        }

        return maxi<=capacity;





    }
};