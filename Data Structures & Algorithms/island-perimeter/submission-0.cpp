class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int &p){

        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size() ||
           grid[i][j] == 0){

            p++;
            return;
        }

        if(grid[i][j] == -1)
            return;

        grid[i][j] = -1;

        dfs(grid,i+1,j,p);
        dfs(grid,i-1,j,p);
        dfs(grid,i,j+1,p);
        dfs(grid,i,j-1,p);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int p = 0;

        for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[0].size();j++){

                if(grid[i][j]==1){

                    dfs(grid,i,j,p);

                    return p;
                }
            }
        }

        return 0;
    }
};