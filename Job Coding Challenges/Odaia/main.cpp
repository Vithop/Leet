#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>

using namespace std;


class BracketValidator
{
private:
	map<char, char> bracketMap;	
public:
	BracketValidator(){
		//initialize bracket map to easily find end bracket
		this->bracketMap['('] = ')';
		this->bracketMap['['] = ']';
		this->bracketMap['{'] = '}';
	};
	bool isValid(string s){
	    stack<char> bracketOrder;
		for (int i = 0; i < s.size(); ++i)
		{
			for(auto it: bracketMap){
				if (s[i] == it.first)
				{
					bracketOrder.push(s[i]);
					
				}else if (s[i] == it.second)		
				{
					if (bracketOrder.top() == it.first)
					{
						bracketOrder.pop();
					}else{
						return false;
					}
				}
			}
		}
		return bracketOrder.empty();
	}
};

class maxProfitSolution
{
public:
	int maxProfit(vector<int> prices){
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			profit += (prices[i] > prices[i-1])*(prices[i]-prices[i-1]);
		}
		return profit;

	}		
};
int main()
{
    cout<< "Hello Odaia! \n";
    cout<< "\n Bracket Validation Solution \n";
    BracketValidator BV;
    cout<<"Input: () \n";
    cout<<"Output: "<< BV.isValid("()") <<endl;
    cout<<"Input: ()[]{} \n";
    cout<<"Output: "<< BV.isValid("()[]{}") <<endl;
    cout<<"Input: (] \n";
    cout<<"Output: "<< BV.isValid("(]") <<endl;
    cout<<"Input: ([)] \n";
    cout<<"Output: "<< BV.isValid("([)]") <<endl;
    cout<<"Input: {[]} \n";
    cout<<"Output: "<< BV.isValid( "{[]}" ) <<endl;
    cout<<"Input: {[ \n";
    cout<<"Output: "<< BV.isValid("{[") <<endl;
    
    cout<< "\n Max Profit Solution \n";
    maxProfitSolution MP;
    vector<int> input = {7,1,5,3,6,4};
    cout<<"Input:  [7,1,5,3,6,4] \n";
    cout<<"Output: "<< MP.maxProfit(input) <<endl;
    input = {1,2,3,4,5};
    cout<<"Input:  [1,2,3,4,5] \n";
    cout<<"Output: "<< MP.maxProfit(input) <<endl;
    input = {7,6,4,3,1};
    cout<<"Input:  [7,6,4,3,1] \n";
    cout<<"Output: "<< MP.maxProfit(input) <<endl;

  return 0;
}
