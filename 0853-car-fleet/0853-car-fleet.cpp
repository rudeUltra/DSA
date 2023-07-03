class Solution {
public:
    class Cars{
        public:
        int pos;
        int speed;
        Cars(int p,int s){
            pos=p;
            speed=s;
        }
    };
    static bool mycom(Cars &a,Cars &b){
        return a.pos<b.pos;
    }
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<Cars> cars;
        for(int i=0;i<pos.size();i++){
            Cars car(pos[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),mycom);
        stack<float> st;
        for(auto car:cars){
            float time=(target-car.pos)/((float)car.speed);
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};