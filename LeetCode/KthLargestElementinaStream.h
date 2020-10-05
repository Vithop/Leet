class KthLargest {
public:
    list<int> stream;
    list<int>::iterator kIt;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        sort(nums.begin(), nums.end());
        kIt = stream.begin();
        for(int i = 0; i<nums.size(); ++i){
            stream.push_back(nums[i]);
            if(i <= nums.size()-k)++kIt;
        }        
    }
    
    int add(int val) {
        if(stream.size()== 0){
            stream.push_front(val);
            kIt = stream.begin();
        }else if(stream.size() < kth){
            auto pos = lower_bound(kIt, stream.end(), val);
            stream.insert(pos, val); 
            kIt = stream.begin();
            //cout<<"fizz";

        }else if (val > *kIt){
            auto pos = lower_bound(kIt, stream.end(), val);
            stream.insert(pos, val); 
            ++kIt;
         
        }else{
            stream.push_front(val);
            
        }


        
        return *kIt;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */