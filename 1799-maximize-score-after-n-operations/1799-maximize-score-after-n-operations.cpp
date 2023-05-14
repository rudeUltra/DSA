class Solution {
private:
    int solve(vector<int> &nums,string &visited,int k){
        // Base case (If we picked k pairs)
        if(k == 0){
            return 0;
        }

        if(dp[visited] != 0){
            return dp[visited];
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            // Checking if ith index is already visited or not
            if(visited[i] == '0'){
                // Marking it as visited
                visited[i] = '1';
                int temp = 0;
                for(int j=i+1;j<nums.size();j++){
                    // Checking if jth index is already visited or not
                    if(visited[j] == '0'){
                        // marking visited 
                        visited[j] = '1';
                        temp = max(k * gcd(nums[i],nums[j]) + solve(nums,visited,k-1),temp);
                        // Backtracking 
                        visited[j] = '0';
                    }
                }
                // Backtracking
                visited[i] = '0';
                ans = max(ans,temp);
            }
        }

        return dp[visited] = ans;
    }
public:
    unordered_map<string,int> dp;
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        string visited(n,'0');

        return solve(nums,visited,n/2);
    }
};