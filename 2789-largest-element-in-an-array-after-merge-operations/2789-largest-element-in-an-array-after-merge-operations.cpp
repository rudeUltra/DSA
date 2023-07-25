class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        stack<long long> st;
        
        //push all the elements into the stack
        for(int i=0;i<nums.size();i++){
             st.push(nums[i]);
        }
        
        //traverse the stack until one element is remaining
        while(st.size()!=1){
            long long temp1 = st.top();
            st.pop();
            long long temp2 = st.top();
            st.pop();
            
            if(temp2<=temp1){
                st.push(temp1+temp2);
            }
            else{
                st.push(temp2);
            }
        }
        
        //remaining element in the stack is our answer
        return st.top();
    }
};

//SABKO DHAAL DO BC BAADME JO HOGA WO HOGA XD