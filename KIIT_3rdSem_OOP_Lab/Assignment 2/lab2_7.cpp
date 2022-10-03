/*
KIIT OOP LAB Question 2-7
Create a class which stores x and y coordinates of a point.
Calculate ditance between 2 points and dispaly it
*/

#include <iostream>
#include <math.h>
using namespace std;

class Point{
    float x, y;

    public:
        void GetCoordinate(){
            cout << "X = ";
            cin >> x;
            cout << "Y = ";
            cin >> y;
        }
        float CalcualteDistance(Point p1, Point p2){
            float dist_y = p2.y-p1.y;
            float dist_x = p2.x-p1.x;
            return (sqrt((dist_y*dist_y)+(dist_x*dist_x)));
        }
};

int main(){
    Point p1, p2;
    cout << "Point 1 -\n";
    p1.GetCoordinate();
    cout << "Point 2 -\n";
    p2.GetCoordinate();

    // Displaying distance between 2 points
    cout << "Distance between the two points is : " << p1.CalcualteDistance(p1, p2) << " units.";
    return 0;
}