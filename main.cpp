#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Helpers
double power(double x, int pow) {
    double result = 1.0;
    for (int i = 1; i <= pow; i++) {
        result *= x;
    }
    return result;
}

int factorial(int x) {
    if (x == 0 || x == 1) return 1;
    int result = x;
    for (int i = x - 1; i > 1; i--) {
        result *= i;
    }
    return result;
}

long long combinate(int n, int k) {
    if (k > n - k) k = n - k; // Symmetry property
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

double binomial(int n, int k, double success, double fail) {
    return combinate(n, k) * power(success, k) * power(fail, n - k);
}
/* 
n = how many tries
k = how much success you want
success = probability of success 1 = 100%, 0 = 0% use decimal base 2
fail = probability of fail 1 = 100%, 0 = 0% use decimal base 2
Note : fail + success MUST HAVE TO BE 1
*/

int main() {
    double success_ratio = 0.8;
    double fail_ratio = 1 - success_ratio;

    if (abs(success_ratio + fail_ratio - 1.0) < 1e-9) {
        double probability = binomial(10, 2, success_ratio, fail_ratio) * 100;
        cout << fixed << setprecision(12) << probability << "%" << endl;
    } else {
        cout << "Please input the correct format into the function!" << endl;
    }
    return 0;
}

//i add this comment
