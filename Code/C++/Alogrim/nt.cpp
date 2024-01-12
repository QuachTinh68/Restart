#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    int lastDigit = abs(N) % 10;
    int tempN = abs(N);
    int digitCount = 0;
    while (tempN != 0) {
        tempN /= 10;
        digitCount++;
    }

    int firstDigit = abs(N) / pow(10, digitCount - 1);

    int newNumber = lastDigit * pow(10, digitCount - 1) + abs(N) % (int)pow(10, digitCount - 1);
    newNumber = newNumber - lastDigit + firstDigit;

    if (N < 0) {
        newNumber *= -1;
    }
    cout << newNumber ;
    return 0;
}
