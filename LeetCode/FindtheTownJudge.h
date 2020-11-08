class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, set<int>> trustMap;
        for (int i = 0; i < trust.size(); ++i)
        {
        	trustMap[trust[i][0]].insert(trust[i][1]);
        }
        for(auto it: trustMap){
        	if (it.second.size() == 0)
        	{
        		int numTrust = 0;
        		for(auto it2: trustMap){
        			numTrust += (it2.second.find(it.first) != it2.second.end());
        		}
        		if (numTrust == N-1)
        		{
        			return it.first;
        		}
        	}
        }
        return -1;
        
    }
};