/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */

var b, s, m;

var ParkingSystem = function(big, medium, small) {
    b = big;
    s = small;
    m = medium;
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(carType) {
    if(carType == 1 && b > 0) {
        b--;
        return true;
    }
    else if(carType == 2 && m > 0) {
        m--;
        return true;
    }
    else if(carType == 3 && s > 0) {
        s--;
        return true;
    }
    return false;
};

/** 
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */