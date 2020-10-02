class Solution {
public:
    #define mod 1000000007
    vector<vector<int>> pathMap = vector(501, vector(501, -1));
	long long countPaths(int index, int steps, int arrLen){
		if (index < 0 || index > arrLen-1 || index > steps)
		{
			return 0;
		}else if(index == steps){
			return 1;
		}else{
            
            if(pathMap[index][steps] != -1){
                return pathMap[index][steps];
            }
            
			long long numPaths = 0;
			numPaths += countPaths(index-1, steps-1, arrLen);
			numPaths += countPaths(index+1, steps-1, arrLen);
			numPaths += countPaths(index, steps-1, arrLen);
            numPaths = numPaths%mod;
            pathMap[index][steps] = numPaths;
            
			return numPaths;
		}

	}
    
    int numWays(int steps, int arrLen) {
        
    	return countPaths(0, steps, arrLen) % mod;

    }
};