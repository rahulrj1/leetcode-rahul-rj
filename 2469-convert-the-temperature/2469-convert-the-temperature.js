/**
 * @param {number} celsius
 * @return {number[]}
 */
var convertTemperature = function(celsius) {
    var kel = celsius + 273.15;
    var far = celsius*1.8 + 32;
    return [kel, far];
};