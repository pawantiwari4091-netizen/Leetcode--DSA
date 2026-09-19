class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
/*
        CLAMP method => Parameters
        num      -    the value to clamp
        low, high  -    the boundaries to clamp num to


        Return value
        Reference to low if num is less than low,
        Reference to high if high is less than num,
        otherwise reference to num.

*/
        
        int xi = clamp(xCenter, x1, x2);
        int yi = clamp(yCenter, y1, y2);

        return sqrt((xi-xCenter)*(xi-xCenter) + (yi-yCenter)*(yi-yCenter)) <= radius;
    }
};