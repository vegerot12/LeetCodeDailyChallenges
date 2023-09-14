class ParkingSystem {
    private:
    vector<int> slots = {0,0,0};
public:
    ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;


    }
    
    bool addCar(int carType) {
        slots[carType-1]--;
        return slots[carType-1] >=0;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */