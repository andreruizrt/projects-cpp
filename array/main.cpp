#include <iostream>

using namespace std;


bool compareValues( const int list[4] ) {

    int listCorrect[8] = { 6676, 3216, 4063, 8373, 423, 586, 8850, 6762 };

    for ( int i = 0; i < 4; i++ ) {
        if ( list[i] != listCorrect[i] )
            return false;
    }

    return true;
}


int main() {

    int n = 8;
    int arr[8] = { 6676, 3216, 4063, 8373, 423, 586, 8850, 6762 };

// Pedir valores
//    cin >> n;

//    for ( int i = 0; i < n; i++ ) {
//        cin >> arr[i];
//    }

    int result[8] = {};
    int counter = 0;

    for ( int i = n - 1; i >= 0; i-- ) {
        result[counter] = arr[i];
        cout << arr[i] << " ";
        counter++;
    }

    cout << endl;

    bool passed = compareValues( result );

    cout << ( passed ? "Passou\n" : "Falhou\n" );

    return 0;
}

