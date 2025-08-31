class Solution {
public:
    int mini =1e9;
    vector<int> best;

    void check(vector<int> curr ){
        sort(curr.begin(),curr.end());
        int val = (curr.back()-curr[0]);
        if(val<mini){
            mini =val;
            best = curr;
        }
      
    }
    void solve(int n,int k,int i,vector<int> curr,vector<int> &fac){

        if(k==0){
           
            if(n==1){
               check(curr);

            }
            return;
        }

        for(int j=i;j<fac.size();j++){
            if(n%fac[j]==0){
                curr.push_back(fac[j]);
                solve(n/fac[j],k-1,i,curr,fac);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
       
        vector<int> curr;
        vector<int> fac;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                fac.push_back(i);
                if(i*i!=n)
                fac.push_back(n/i);
            }
        }

        solve(n,k,0,curr,fac);
        return best;
      
    }
};