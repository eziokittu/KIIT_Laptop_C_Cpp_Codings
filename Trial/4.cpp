#include <iostream>
using namespace std;

class Music{
    private:
        static Music* instance;
        string track;

        // Private Constructor so that no object can be created
        Music () {
            track = "Halleluiah";
        }
    public:
        static Music* GetInstance(){
            if (instance == 0) 
                instance = new Music; // calls the private constructor
            return instance;
        }

        string getData() {
            return this -> track;
        }

        void setData(string track) {
            this -> track = track;
        }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Music *Music::instance = 0;

int main(){
    Music *s1 = s1->GetInstance();
    Music *s2 = s2->GetInstance();

    cout << s1->getData() << endl;
    s1->setData("ggg");
    cout << s1->getData() << endl;

    cout << s2->getData() << endl;
    s2->setData("hhh");
    cout << s2->getData() << endl;

    cout << s1->getData() << endl;
    return 0;
}