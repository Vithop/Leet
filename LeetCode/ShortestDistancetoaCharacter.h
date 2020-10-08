class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> cmap;
        vector<int> ans(S.size());
        for(int i = 0; i<S.size(); ++i){
            if(S[i] == C)cmap.push_back(i);
        }
        int j = 0;
        for(int i = 0; i<S.size(); ++i){
            ans[i] = (j+1 < cmap.size() && abs(cmap[j] - i) > abs(cmap[j+1] - i))? abs(cmap[++j] - i): abs(cmap[j] - i);
        }
        return ans;
        
        
    }
};