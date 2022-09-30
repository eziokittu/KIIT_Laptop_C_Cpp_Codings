#include <iostream>
using namespace std;

int main(){
    
    int m, n;
    cout << "Enter no. of rows (range1) : ";
    cin >> m;
    cout << "Enter no. of columns (range2) : ";
    cin >> n;

    // Inverse Triangle Number Pattern
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3        n = 5
    // 1 2
    // 1
    cout << "\n--- Inverse Triangle Number Pattern ---\n";
    for(int i=0; i<m; i++){
        for (int j=1; j<=m-i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout <<"\n";

    // Triangle 0-1 Pattern
    // 1
    // 0 1
    // 1 0 1        n = 5
    // 0 1 0 1 
    // 1 0 1 0 1
    cout << "\n--- Triangle 0-1 Pattern ---\n";
    for(int i=1; i<=m; i++){
        for (int j=1; j<=i; j++){
            if ((i+j)%2==0) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    cout <<"\n";

    // Solid Rhombus Pattern
    //     XXXXX
    //    XXXXX
    //   XXXXX      N = 5
    //  XXXXX
    // XXXXX
    cout << "\n--- Solid Rhombus Pattern ---\n";
    for(int i=0; i<m; i++){
        for (int j=0; j<m-i-1; j++){
            cout << " ";
        }
        for (int j=0; j<n; j++){
            cout << "X";
        }
        cout << endl;
    }
    cout <<"\n";

    // Triangle Number Pattern
    //     1
    //    1 2
    //   1 2 3      n = 5
    //  1 2 3 4
    // 1 2 3 4 5
    cout << "\n--- Solid Rhombus Pattern ---\n";
    for(int i=1; i<=m; i++){
        for (int j=0; j<m-i; j++){
            cout << " ";
        }
        for (int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout <<"\n";

    // Triangle Number Pattern
    //     1
    //    212
    //   32123      n = 5
    //  4321234
    // 543212345
    cout << "\n--- Palindromic Pattern ---\n";
    for(int i=1; i<=m; i++){
        for (int j=0; j<m-i; j++){
            cout << " ";
        }
        for (int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout <<"\n";
}