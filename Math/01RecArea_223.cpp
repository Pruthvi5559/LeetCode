//223. Rectangle Area
/*
Given the coordinates of two rectilinear rectangles in a 2D plane, 
return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and 
its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its 
top-right corner (bx2, by2).
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // Calculate the individual area of both the rectangle
        int areaRec1 = (ax2 - ax1) * (ay2 - ay1);
        int areaRec2 = (bx2 - bx1) * (by2 - by1);

        // Find 1D overlap along the X-axis and Y-axis (clamped to 0 if no overlap exists)
        int width = max(0, min(ax2, bx2) - max(ax1, bx1));
        int height = max(0, min(ay2, by2) - max(ay1, by1));
        
        // Calculate total area of the overlapping region
        int overlappedArea = width * height;

        // Apply inclusion-exclusion: total area minus double-counted intersection
        return (areaRec1 + areaRec2) - overlappedArea;
    }
};