#include <iostream>
using namespace std;

class Singleton {
    private:
        static Singleton *instance;
        int data = 50;
    
        // Private constructor so that no objects can be created.
        Singleton() {
            data = 50;
        }

    public:
        static Singleton *getInstance() {
            if (!instance){
                //cout << "\nNot Instance = " << !instance << endl;
                instance = new Singleton;
            }
            //cout << "\nInstance = " << !instance << endl;
            return instance;
        }

        int getData() {
            return this -> data;
        }

        void setData(int data) {
            this -> data = data;
        }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
    Singleton *s1 = s1->getInstance();
    Singleton *s2 = s2->getInstance();

    cout << s1->getData() << endl;
    s1->setData(100);
    cout << s1->getData() << endl;

    cout << s2->getData() << endl;
    s2->setData(200);
    cout << s2->getData() << endl;

    cout << s1->getData() << endl;
    return 0;
}