### 📘 Matrix Chain Multiplication (MCM) with Optimal Parenthesization

This repository contains a C++ implementation of the **Matrix Chain Multiplication** problem using dynamic programming with memoization. It not only calculates the **minimum number of scalar multiplications** but also returns the **optimal parenthesization**.

---

### 🚀 Problem Description

You're given an array `arr[]` of size `n` which represents the dimensions of matrices such that:

* Matrix A₁ is of size `arr[0] x arr[1]`
* Matrix A₂ is of size `arr[1] x arr[2]`
* ...
* Matrix Aₖ is of size `arr[k-1] x arr[k]`

Your task is to find the **most efficient way to multiply these matrices** and show the parenthesization that minimizes the number of scalar multiplications.

---

### 🧠 Algorithm

**Function**: `minMatCal(arr, memo, i, j)`

**Input**:

* `arr[]` — an array of matrix dimensions
* `i, j` — the range of matrices from Aᵢ to Aⱼ
* `memo` — a DP table storing results of subproblems

**Steps**:

1. **Base Case**: If `i == j`, return the matrix name (like 'A', 'B', ...) and 0 cost.
2. **Memoization Check**: If the result for `(i, j)` is already calculated, return it.
3. **Try all positions `k` between `i+1` to `j`**:

   * Divide the chain at `k`
   * Recursively calculate cost for left and right subproblems
   * Add multiplication cost: `arr[i] * arr[k] * arr[j]`
   * Track minimum cost and corresponding parenthesization
4. **Store and return** the optimal result.

---

### ⏱️ Time & Space Complexity

* **Time**: O(n³)
* **Space**: O(n²) for memoization

---

### 💻 Code

```cpp
#include<bits/stdc++.h>
using namespace std;

pair<string, int> minMatCal(vector<int>& arr, vector<vector<pair<string, int>>>& memo, int i, int j) {
    if(i == j) {
        string temp(1, 'A' + i);
        return {temp, 0};
    }

    if(memo[i][j].second != -1)
        return memo[i][j];

    int res = INT_MAX;
    string str;

    for(int k = i + 1; k <= j; k++) {
        auto left = minMatCal(arr, memo, i, k - 1);
        auto right = minMatCal(arr, memo, k, j);
        int cost = left.second + right.second + arr[i] * arr[k] * arr[j];

        if(cost < res) {
            res = cost;
            str = "(" + left.first + right.first + ")";
        }
    }

    return memo[i][j] = {str, res};
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<pair<string, int>>> memo(n, vector<pair<string, int>>(n, {"", -1}));
    cout << "Optimal Parenthesization: " << minMatCal(arr, memo, 0, n - 1).first << endl;

    return 0;
}
```

---

### 🛠️ How to Compile and Run

```bash
g++ mcm.cpp -o mcm
./mcm
```

---

### 🧪 Example

**Input**:

```
4
10 30 5 60
```

**Explanation**:
This means 3 matrices:

* A = 10×30
* B = 30×5
* C = 5×60

**Output**:

```
Optimal Parenthesization: (A(BC))
```
