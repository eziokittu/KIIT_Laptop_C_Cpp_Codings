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
            arr = new T(size);
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
    cout << "\n---- For integer array ----";
    int arr1[5] = {3,1,9,2,8};
	MyClass<int> obj1(5, arr1);
    cout << "\n---- For char array ----";
    char arr2[4] = {'d', 't', 'z', 'c'};
	MyClass<int> obj2(5, arr2);

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
