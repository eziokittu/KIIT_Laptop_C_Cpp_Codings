#include <iostream>
using namespace std;

int main(){
    
    int m, n;
    cout << "Enter no. of rows (range1) : ";
    cin >> m;
    cout << "Enter no. of columns (range2) : ";
    cin >> n;

    // Solid Rectange pattern
    cout << "\n--- Solid Rectangle Pattern ---\n";
    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << "X";
        }
        cout << endl;
    }
    cout <<"\n";

    // Hollow Rectange Pattern
    cout << "\n--- Hollow Rectange Pattern ---\n";
    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (i==0 || j==0 || i==m-1 || j==n-1)
                cout <<"X";
            else
                cout <<" ";
        }
        cout << endl;
    }
    cout <<"\n";

    // Inverted Half Pyramid Pattern
    // X X X X X
    // X X X X
    // X X X        range = 5
    // X X
    // X
    cout << "\n--- Inverted Half Pyramid Pattern ---\n";
    for (int i=m; i>0; i--){
        for (int j=0; j<i; j++){
            cout << "X";
        }
        cout << endl;
    }
    cout <<"\n";

    // Half Pyramid after 180 degrees roation - Pattern
    //         X
    //       X X
    //     X X X        range = 5
    //   X X X X
    // X X X X X
    cout << "\n--- Half Pyramid after 180 degrees roation - Pattern ---\n";
    for (int i=1; i<=m; i++){
        // printing spaces
        for (int j=0; j<m-i; j++) cout << " ";
        // printing stars
        for (int k=0; k<i; k++) cout << "X";
        // new line
        cout << endl;
    }
    cout <<"\n";

    // Half Pyramid using numbers - Pattern
    // 1
    // 2 2
    // 3 3 3        range = 5
    // 4 4 4 4
    // 5 5 5 5 5
    cout << "\n--- Half Pyramid using numbers - Pattern ---\n";
    for (int i=1; i<=m; i++){
        // printing numbers
        for (int j=0; j<i; j++) cout << i;
        // new line
        cout << endl;
    }
    cout <<"\n";

    // Floyd's Triangle - Pattern
    // 1
    // 2 3
    // 4 5 6       range = 5
    // 7 8 9 10
    // 11 12 13 14 15
    cout << "\n--- Half Pyramid using numbers - Pattern ---\n";
    int num = 1;
    for (int i=1; i<=m; i++){
        // printing numbers
        for (int j=0; j<i; j++){
            if (num>9) cout << num++ << " ";
            else cout << "0" << num++ << " ";
        }
        // new line
        cout << endl;
    }
    cout <<"\n";

    // Butterfly Triangle - Pattern
    // X                 X
    // X X             X X
    // X X X         X X X
    // X X X X     X X X X
    // X X X X X X X X X X
    // X X X X X X X X X X     N = 4
    // X X X X     X X X X
    // X X X         X X X
    // X X             X X
    // X                 X
    cout << "\n--- Half Pyramid using numbers - Pattern ---\n";
    // upper
    for (int i=1; i<=m; i++){
        // left
        for (int j=0; j<i; j++) cout << "X";
        //spaces
        for (int j=1; j<=(m-i)*2; j++){
            cout << " ";
        }
        // right
        for (int j=0; j<i; j++) cout << "X";
        // new line
        cout << endl;
    }
    // lower
    for (int i=m; i>0; i--){
        // left
        for (int j=0; j<i; j++) cout << "X";
        // spaces
        for (int j=0; j<(m-i)*2; j++){
            cout << " ";
        }
        // right
        for (int j=0; j<i; j++) cout << "X";
        // new line
        cout << endl;
    }
    cout <<"\n";
}