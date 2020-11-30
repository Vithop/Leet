class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto sum = 0;
        unordered_map<int, int> sum_count;
        auto count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if( sum == k ){
                ans++;
            }else if(sum_count.find(k-sum) != sum_count.end()){
                count+= sum_count[k-sum];
            }
            sum_count[sum]++;
        }
        return count;
        
    }
};