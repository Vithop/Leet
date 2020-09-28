class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        set<string> myList(products.begin(), products.end());
    	vector<vector<string>> ans(searchWord.size());
        string subString = "";
        auto endIt = myList.end();
        for (int i = 0; i < searchWord.size(); ++i)
        {
        	subString+= searchWord[i];
          	cout << subString << endl;
          	auto searchFunc = [subString](string prod){
        		return prod.find(subString) == 0;
        	};
        	auto first = find_if(myList.begin(), endIt, searchFunc);
        	if (first != myList.end())
        	{
        		ans[i].push_back(*first);
	        	auto second = find_if(next(first,1), endIt, searchFunc);
	        	if (second != myList.end())
	        	{
	        		ans[i].push_back(*second);
	        		auto third = find_if(next(second,1), endIt, searchFunc);
	        		if (third != myList.end())
	        		{
	        			ans[i].push_back(*third);
	        		}
	        	}
        	}else{
        		break;
        	}
        	
        }
        return ans;

    }
};