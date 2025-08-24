class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n+1,0);
        vector<int> right(n+2,0);

        for(int i=1;i<=n;i++){
            if(nums[i-1]==1){
                left[i]=left[i-1]+1;
            }
        }
         for(int i=n;i>=1;i--){
            if(nums[i-1]==1){
                right[i]=right[i+1]+1;
            }
        }

        if(left[n]==n){
            return n-1;
        }

        int maxi =0;

        for(int i=1;i<=n;i++){
            if(nums[i-1]==0){
                maxi =max(maxi,left[i-1]+right[i+1]);
            }
        }
        return maxi;
    }
};