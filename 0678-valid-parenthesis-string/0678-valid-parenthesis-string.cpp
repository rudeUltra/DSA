class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);;
            }
            else {
                if(s[i]==')'){
                    if(!open.empty()){
                        open.pop();
                    }
                    else if(!star.empty()){
                        star.pop();
                    }
                    else return false;
                }
            }

        }
        while(!open.empty() && !star.empty() && open.top() < star.top()){
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};