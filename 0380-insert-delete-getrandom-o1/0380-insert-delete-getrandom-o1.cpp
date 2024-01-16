class RandomizedSet {
public:
    vector<int>a;
    unordered_map<int,int>m1;
    RandomizedSet() {
        //siuu
    }
    
    bool insert(int val) {
        if(m1.find(val)==m1.end()){
            a.push_back(val);
            //always insert at the end so easy to index
            m1[val]=a.size()-1;
            return true;
        }
        //already exists siu
        return false;
    }
    
    bool remove(int val) {
        //tricy hm
        if(m1.find(val)!=m1.end()){
            int temp=a.back(); //O(1)
            a[m1[val]]=temp;
            m1[temp]=m1[val];
            a.pop_back();
            m1.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */