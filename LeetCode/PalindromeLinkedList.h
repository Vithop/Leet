/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverse(ListNode* head) 
    { 
        // Initialize current, previous and 
        // next pointers 
        ListNode* current = head; 
        ListNode* prev = nullptr;
        ListNode* next = nullptr; 

        while (current != nullptr) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
   		return prev; 

    } 
    bool isPalindrome(ListNode* head) {
    	int size = 0;
    	ListNode* it = head;
    	ListNode* it2 = nullptr;
    	while(it != nullptr){
    		++size;
    		it = it->next;
    	}
        if(size<2)return true;


    	int mid = size/2;
    	int i = 0;
    	it = head;
    	while(i < mid-1){
    		++i;
    		it = it->next;
    	}


    	if (size%2 == 1)
    	{
    		it = it->next;
    	}
    	it2 = it;
    	it = it->next;
    	it2->next = nullptr;
    	it = reverse(it);


    	it2 = it;
        it = head;
    	while((it != nullptr) && (it2 != nullptr)){
    		if (it->val != it2->val)
    		{		
    			return false;
    		}
    		it = it->next;
    		it2 = it2->next;
    	}
    	return true;
        
    }

    // bool isPalindrome(ListNode* head) {
    //     if (head == nullptr || head ->next == nullptr)
    //     {
    //     	return true;
    //     }        
    //     return mathuFunc(head, head->next) != nullptr;

    // }
    // ListNode* mathuFunc(ListNode* head, ListNode* butt){
    // 	if (butt->next == nullptr)
    // 	{
    // 		return (head->val == butt->val)? head->next: nullptr;
    // 	}
    // 	head = mathuFunc(head, butt->next);
    // 	if ((head == nullptr) || (head->val != butt->val))
    // 	{
    // 		return nullptr;
    // 	}
    // 	if (head->next == nullptr)
    // 	{
    // 		return head;
    // 	}
    // 	return head->next;
    // }
};