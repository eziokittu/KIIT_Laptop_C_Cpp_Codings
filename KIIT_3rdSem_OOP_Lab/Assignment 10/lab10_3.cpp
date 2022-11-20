// OOPs LAB Assignment 10
// Q1) Rewrite program 1 using class template.

#include <iostream>
using namespace std;

// Class template
template <class T>
class MyClass {
    private:
        int size;
        T arr[];
    public:
        MyClass(int n, T a[]){
            size = n;
            for (int i=0; i<size; i++){
                arr[i] = a[i];
            }
        }

        void SortArray(){
            // Bubble Sorting
            for (int i=0; i<size-1; i++){
                for (int j=i; j<size; j++){
                    if (arr[i]>arr[j]){
                        T temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }

        void Display(){
            cout <<endl;
            for (int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
        }
};

int main()
{
    int arr1[10] = {3,1,9,2,8,11,7,6,4,5};
	MyClass<int> obj1(10, arr1);
    float arr2[4] = {7.4, 7.2, 7.9, 7.6};
	MyClass<float> obj2(4, arr2);

    cout <<"----- Before Soring -----";
    obj1.Display();
    obj2.Display();

    obj1.SortArray();
    obj2.SortArray();

    cout <<"\n\n----- After Soring -----";
    obj1.Display();
    obj2.Display();

	return 0;
}
