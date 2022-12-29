#include <iostream>

using namespace std;


// Description:
// The longest line of the pattern has n stars beginning in column col of the output. 
// Precondition: n is an positive odd number.
// Postcondition: A pattern based on the above example has been printed.
void pattern(int n, int col) {

    if (n == 1) {
        // A loop to print exactly col columns 
        for (int i = 0; i < col; i++) {
            cout << " ";
        }

        // A loop to print n asterisks, each one followed by a space: 
        for (int i = 0; i < n; i++) {
            cout << "* ";
        }
        cout << endl;
        return;
    }

    pattern(n-2, col + 2);
    // A loop to print exactly col columns 
    for (int i = 0; i < col; i++) {
        cout << " ";
    }

    // A loop to print n asterisks, each one followed by a space: 
    for (int i = 0; i < n; i++) {
        cout << "* ";
    }
    cout << endl;

    pattern(n-2, col + 2); /// logic for COLUMNS
}


int main() {

    int n;
    int col;

    cout << "Please enter a positive odd integer: ";
    cin >> n;
    cout << "Please enter a positive integer: ";
    cin >> col;

    pattern(n, col);
}