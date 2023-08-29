class Solution {
public:
    
    vector<string> res;
    
    void helper(string str, int target, int i, string curr, long long res_so_far, long long prev_num)
    {
        if(i == str.size())
        {
            if(res_so_far == target)
            {
                res.push_back(curr);
            }
            
            return;
        }
        
        for(int j = i; j < str.size(); j++)
        {
            if(j > i && str[i] == '0')
            {
                break;
            }
            
            string curr_str = str.substr(i, j - i + 1);
            
            long long curr_num = stoll(curr_str);
            
            if(i == 0)
            {
                helper(str, target, j + 1, curr + curr_str, curr_num, curr_num);
            }
            else
            {
                helper(str, target, j + 1, curr + "+" + curr_str, res_so_far + curr_num, curr_num);
                
                helper(str, target, j + 1, curr + "-" + curr_str, res_so_far - curr_num, -curr_num);
                
                helper(str, target, j + 1, curr + "*" + curr_str, res_so_far - prev_num + prev_num * curr_num, prev_num * curr_num);
            }
        }
    }
    
    vector<string> addOperators(string str, int target) {
        
        int n = str.size();
        
        helper(str, target, 0, "", 0, 0);
        
        return res;
    }
};