//using dsu
class Solution {
public:
    const static int N = 1e5;
    int parr[N];
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int findParr(int v){
        return parr[v] == v ? v : (parr[v] = findParr(parr[v]));
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        int isLand = 0;

        //counted every one as a single isLand
        for(int i=0; i<n*m;i++){
            parr[i] = i;
            int r = i/m;
            int c = i%m;
            isLand += (grid[r][c] == '1');
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0') continue;
                int p1 = findParr(i*m+j);
                for(auto &[dr, dc]: dir){
                    int r = i + dr;
                    int c = j + dc;
                    if(r>=n or c>=m or r<0 or c<0 or grid[r][c] == '0')
                        continue;
                    int p2 = findParr(r*m+c);
                    if(p1 != p2){
                        parr[p2] = p1;
                        isLand--;
                    }
                }
            }
        }
        return isLand;
    }
};

// using dfs
class Solution {
private:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& grid, int r, int c, int n, int m){
        grid[r][c] = '0';
        for(auto&[dr,dc]:dir){
            if(r+dr<0 or r+dr>=n or c+dc<0 or c+dc>=m or grid[r+dr][c+dc] == '0')
                continue;
            dfs(grid, r+dr, c+dc, n, m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 or grid[0].size() == 0)
            return 0;
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '0')
                    continue;
                cnt++;
                dfs(grid,i,j,n,m);
            }
        }
        return cnt;
    }
};