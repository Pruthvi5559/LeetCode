//1344. Angle Between Hands of a Clock
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(30*hour-11.0*minutes/2);
        if(angle > 180){
            return (360 - angle);
        }else{
            return angle;
        }
    }
};