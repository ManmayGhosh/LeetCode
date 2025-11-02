class Solution {
public:

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int &a: nums){
            s.insert(a);
        } 
        ListNode* temp = head;
        ListNode* newHead = head;
        ListNode*  prev;
        while(temp && s.count(temp->val)){
            temp = temp->next;
           
        }
        newHead = temp;
            if (!newHead) return nullptr; 

        prev = newHead;
        temp = newHead->next;
        while(temp){
            
            if(temp && s.count(temp->val)){
                temp = temp->next;
                prev->next = temp;
            }else{
              prev = temp;
              temp= temp->next;
     
            }
    
            
          
        }
        return newHead;
    }
};