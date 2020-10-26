class ParkingSystem {
public:
    int numParkingSpots[4];
    ParkingSystem(int big, int medium, int small) {
        numParkingSpots[1] = big;
        numParkingSpots[2] = medium;
        numParkingSpots[3] = small;
    }
    
    bool addCar(int carType) {
        if(numParkingSpots[carType] > 0){
            --numParkingSpots[carType];
            return true;
        }
        return false;
    }
};
