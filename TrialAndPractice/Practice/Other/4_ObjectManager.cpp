#include <iostream>
using namespace std;

class ObjectManager{
    private:
        static ObjectManager* instance;
        static int count;
        int data;
    public:
        ObjectManager () {
            data = 10;
            count ++;
        }
        static int totalObjects()
		{
			return count;
		}

        int getData() {
            return this -> data;
        }

        void setData(int data) {
            this -> data = data;
        }
};

//initialise static member function
int ObjectManager::count =0;

int main(){
    ObjectManager obj1, obj2;

    cout << obj1.getData() << endl;
    cout << obj2.getData() << endl;

    obj1.setData(100);
    obj2.setData(200);

    cout << obj1.getData() << endl;
    cout << obj2.getData() << endl;
    

    //printing object count 
	cout << "Total objects created: " << ObjectManager::totalObjects() << endl;

    return 0;
}