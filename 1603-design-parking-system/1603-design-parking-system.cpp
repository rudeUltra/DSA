class ParkingSystem {
public:
    int b,m,c;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        c=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && b!=0){
            b--;
            return true;
        }
        else if(carType==2 && m!=0){
            m--;
            return true;
        }
        else if(carType==3 && c!=0){
            c--;
            return true;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */