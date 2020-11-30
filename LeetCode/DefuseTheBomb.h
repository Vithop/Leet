class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum = 0;
        vector<int> decrypt(code.size(), 0);
        function<int(int)> diff;
        int start, end;
        if(k < 0){
            start = code.size() + k;
            end = start - k - 1;
            for(int i = start; i<code.size(); i++){
                sum+=code[i];
            }
        }else if(k > 0){
            start = 1;
            end = start + k - 1;
            for(int i = start; i<k+1; i++){
                sum+=code[i];
            }
        }else{
            return decrypt;
        }
        cout << start << ", " << end <<endl;
        for(int i = 0; i< code.size(); i++){
            decrypt[i] = sum;
            sum -= code[start++];
            ++end;
            end = (end==code.size())?0:end;
            start = (start==code.size())?0:start;
            sum += code[end];  
        }
        return decrypt;
    }
};