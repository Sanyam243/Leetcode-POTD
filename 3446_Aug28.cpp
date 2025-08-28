class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        q.push({0,m-1});

        vector<vector<int>> vis(n,vector<int>(m,false));
        vis[0][m-1]=true;

        int level =1;

        while(!q.empty()){

            int sz =q.size();

            vector<pair<int,int>> index;
            vector<int> temp;

            while(sz--){

                int x = q.front().first;
                int y = q.front().second;
                temp.push_back(grid[x][y]);
                index.push_back({x,y});
                q.pop();

                if(y-1>=0 && !vis[x][y-1]){
                    vis[x][y-1]=true;
                    q.push({x,y-1});
                }

                if(x+1<n && !vis[x+1][y]){
                    vis[x+1][y]=true;
                    q.push({x+1,y});
                }


            }

            if(level<n){
                sort(temp.begin(),temp.end());
            }else{
                 sort(temp.rbegin(),temp.rend());
            }
            level++;
            

            for(int i=0;i<temp.size();i++){
                grid[index[i].first][index[i].second]=temp[i];
            }
        }


        return grid;
    }
};