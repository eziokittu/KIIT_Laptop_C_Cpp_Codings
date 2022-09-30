// KIIT OOP LAB Question 2-5
// Create a class distance which stores a distance in feet and inches.
// Input 2 distance values in objects, add them, store the result distance
// in an object and display it.
// [
// Write the above program in 2 ways:
//      i)  store the resultant distance in the calling object: C3.Add(C1, C2);
//      ii) return the resultant object C3=C1.add(C2)
// ]

#include <iostream>
using namespace std;

class Distance{
    private:
        float feet;
        float inches;

    public:
        void GetData(){
            cout << "\nEnter feet : ";
            cin >> feet;
            cout << "Enter inches : ";
            cin >> inches;
        }

        // for part 1
        void Add(Distance d1, Distance d2){
            inches = d1.inches + d2.inches;
            feet = d1.feet + d2.feet;
            if (inches>=12) // since 12 inches make 1 feet
            {
                feet+=1;
                inches = (int)inches%12;
            }
        }

        // for part 2 (Also Function overloading)
        Distance Add(Distance d){
            inches += d.inches;
            feet += + d.feet;
            if (inches>=12){
                feet+=1;
                inches = (int)inches%12;
            }

            Distance dist;
            dist.inches = inches;
            dist.feet = feet;
            return dist;
        }

        void Display(){
            cout <<"\nDistance : "<<feet<<" feet, "<<inches<<" inches";
        }
};

int main(){
    Distance d1, d2, d3, d4;

    // Getting data
    cout << "Enter distance data for d1 and d2 respectively:\n";
    d1.GetData();
    d2.GetData();

    // Part 1
    d3.Add(d1, d2);

    // Part 2
    d4 = d1.Add(d2);

    // Displaying both distances
    d3.Display();
    d4.Display();
}