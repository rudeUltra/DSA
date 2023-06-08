class Solution {
public:
    bool sign(int x,int y){
        if((x<0 && y<0) || (x>0 && y>0)){
            //same sign 
            return true;
        }
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //keep same sign values as it is siu

        stack<int>st; //stack problem beacuse cancelling out xD we have to caNCEl some previous elements so to store them in the correct order we use a stack hm interesting
        int n=asteroids.size();
        for(int i=0;i<n;++i){
            if(st.empty()){
                st.push(i);
            }
            else if(sign(asteroids[st.top()],asteroids[i])){
                //same sign so just push
                st.push(i);
            }
            else{
                //fight xD
                int flag=1;
                while(!st.empty() && !sign(asteroids[st.top()],asteroids[i])){
                    int x=abs(asteroids[st.top()]);
                    int y=abs(asteroids[i]);

                    //different signs but wont collide beacuse of direction left and right hm
                    if(asteroids[st.top()]<0 && asteroids[i]>0){
                        break;
                    }
                    if(x<y){
                        st.pop();
                    }
                    else if(x==y){
                        st.pop();
                        flag=0;
                        break;
                    }
                    else{
                        break;
                        
                    }
                }
                if(st.empty() && flag==1){
                    st.push(i);
                    continue;
                }
                if(!st.empty() && asteroids[st.top()]<0 && asteroids[i]>0 && flag==1){
                        st.push(i);
                    }
                else if(!st.empty() && sign(asteroids[st.top()],asteroids[i]) && flag==1){
                    st.push(i);
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};