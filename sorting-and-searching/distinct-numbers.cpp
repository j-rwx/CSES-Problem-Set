#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*

You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

Input
The first input line has an integer n: the number of values.
The second line has n integers x_1,x_2,...,x_n.

Output
Print one integers: the number of distinct values.

*/

int main() {
    int n = 0;
    cin >> n;

    unordered_set<int> lookup;
    int res = 0;

    lookup.reserve(1000);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!lookup.count(x)) {
            res++;
            lookup.insert(x);
        }
    }

    cout << res;
    return 0;
}