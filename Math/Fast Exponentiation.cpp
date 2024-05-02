#include <iostream>
#include <vector>
#include <string>
using namespace std;

double power(double x, int n){ // for negative numbers also
    if(n == 0) return 1;
        if(n == 1) return x;

        else{
            double ans = power(x, n/2);
            if(n % 2 == 0) return ans*ans;
            if(n > 0) return ans*ans*x;
            else return ans*ans*(1/x);
        }
}

int main() {

    cout << power(2,-3) << endl;
              
    return 0;
}
