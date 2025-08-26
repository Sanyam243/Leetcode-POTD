class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int area =0;
        int diagonal =0;

        for(auto i: dimensions){
            int l =i[0];
            int w = i[1];

            if(diagonal==(l*l+w*w)){
                area = max(area,l*w);
            }else if(diagonal<(l*l+w*w)){
                diagonal = l*l+w*w;
                area = l*w;
            }
        }
        return area;
    }
};