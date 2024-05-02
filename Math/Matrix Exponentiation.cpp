class Solution {
public:
    const int mod = 1000000007;

    // Matrix multiplication function that can handle temporaries
    vector<vector<int>> mult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        vector<vector<int>> ans(2, vector<int>(2, 0));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                long long sum = 0; // Use long long to avoid overflow during multiplication
                for(int k = 0; k < 2; k++){
                    sum = (sum + (long long) a[i][k] * b[k][j] % mod) % mod;
                }
                ans[i][j] = (int)sum;
            }
        }
        return ans;
    }

    // Recursive function to compute matrix power
    vector<vector<int>> func(const vector<vector<int>>& a, int n) {
        if (n == 1) return a; // Base case for recursion: return matrix itself if n is 1
        vector<vector<int>> temp = func(a, n / 2); // Compute power recursively
        if (n % 2 == 0)
            return mult(temp, temp);
        else {
            vector<vector<int>> tempSquared = mult(temp, temp);
            return mult(tempSquared, a);
        }
    }

    // Function to compute nth Fibonacci number using matrix exponentiation
    int fib(int n) {
        if (n == 0) return 0; 
        if (n == 1) return 1;
        vector<vector<int>> baseMatrix = {{1, 1}, {1, 0}};
        vector<vector<int>> resultMatrix = func(baseMatrix, n);
        return resultMatrix[1][0];
    }
};
