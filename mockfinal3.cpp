#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int intLog(int n, int b) {
    // ADD YOUR CODE HERE
    if(n == 1) {
        return 0;
    }
    if( n == b) {
        return 1;
    }
    if (n % b != 0) {
        return -1;
    }
    return 1 + intLog(n/b, b); // Dummy Return
}



int powerMod(int n, int k, int m) {
    // ADD YOUR CODE HERE
    // if(k = 0) {
    //     return 1;
    // }
    // if(n = 1) {
    //     return 1;
    // }
    // return powerMod(); // Dummy return



    // if (n == 0) 
    //     return 0; 
    // if (k == 0) 
    //     return 1; 
 
    // long y; 
    // if (k % 2 == 0) { 
    //     y = powerMod(n, k / 2, m); 
    //     y = (y * y) % m; 
    // } else { 
    //     y = n % m; 
    //     y = (y * powerMod(n, k - 1, m) % m) % m; 
    // } 
 
    // return (int)((y + m) % m);


   
    if (k == 0) return 1;
    if (k == 1) return n % m;
    return n * powerMod(n, k-1, m) % m;


}

int nChooseK(int n, int k) {
    // ADD YOUR CODE HERE
    if(k == n || k == 0) {
        return 1;
    }
    if(k == 1) {
        return n;
    }
    return nChooseK(n-1, k-1) + nChooseK(n-1, k);
}



int main() {
    // Ex 8
    // cout << intLog(16,2) << endl;
    // cout << intLog(1,2) << endl;
    // cout << intLog(7,7) << endl;

    // cout << intLog(441,21) << endl;
    // cout << intLog(442,21) << endl;

    // cout << intLog(8,2) << endl;
    // cout << intLog(27,3) << endl;

    // Ex 9 
    cout << powerMod(3,2,6) << endl;
    cout << powerMod(7,7,4) << endl;
    cout << powerMod(15,2,9) << endl;

    cout << powerMod(9,0,10) << endl;
    cout << powerMod(9,1,10) << endl;

    // Ex 10

    // cout << nChooseK(3,2) << endl;
    // cout << nChooseK(4,2) << endl;
    // cout << nChooseK(5,2) << endl;

    // cout << nChooseK(2,1) << endl;
    // cout << nChooseK(100,100) << endl;
    // cout << nChooseK(4,0) << endl;

}