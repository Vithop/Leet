class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
    	int m = grid.size();
    	int n = grid[0].size();
    	int communicate = 0;
    	std::vector<int> record(m+n);
      for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
    			record[i] 	+= grid[i][j];
    			record[m+j] += grid[i][j];
        }
      }
      for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
      		communicate += (grid[i][j] && (record[i] || record[m+j]));
        }
      }
      return communicate;
    }
};

