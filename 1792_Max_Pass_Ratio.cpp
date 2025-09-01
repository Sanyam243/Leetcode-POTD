class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double,pair<double,double>>> q;

        for(auto i: classes){
             double pass = i[0];
             double total = i[1];

             double gain = (pass+1.0)/(total+1.0) - pass/total;

             q.push({gain,{pass,total}});
        }

        for(int i=1;i<=extraStudents;i++){

            double gain = q.top().first;
            double pass = q.top().second.first;
            double total = q.top().second.second;

            q.pop();

            pass++;
            total++;

            double newGain =  (pass+1.0)/(total+1.0) - pass/total;

            q.push({newGain,{pass,total}});
        }
        double ans =0;
        while(!q.empty()){
             double pass = q.top().second.first;
            double total = q.top().second.second;
            ans+= (pass/total);
            q.pop();
        }

        return ans/classes.size();
    }
};