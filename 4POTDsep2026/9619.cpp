//1401. Circle and Rectangle Overlapping
/* You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned 
rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left 
corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, 
check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest point on the rectangle to the circle's center.
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate the squared distance between the two points.
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        int distanceSquared = dx * dx + dy * dy;

        // The circle and rectangle overlap if the distance is within the radius.
        return distanceSquared <= radius * radius;
    }
};