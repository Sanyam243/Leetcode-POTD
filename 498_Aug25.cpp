class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[0][0]= true;

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> ans;
        int level =0;

        while(!q.empty()){

            int sz = q.size();
            vector<int> temp;
            while(sz--){

                int x = q.front().first;
                int y = q.front().second;
                temp.push_back(mat[x][y]);
                q.pop();

                //Down 
                if(x+1<n && !vis[x+1][y]){
                    vis[x+1][y]=true;
                    q.push({x+1,y});
                }

                //Right
                if(y+1<m && !vis[x][y+1]){
                     vis[x][y+1]=true;
                    q.push({x,y+1});
                }
            }

            if(level%2==1){
                reverse(temp.begin(),temp.end());
            }
            level++;

            for(int i: temp){
                ans.push_back(i);
            }
        }

        return ans;
    }
};