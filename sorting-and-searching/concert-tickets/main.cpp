#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, 
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,...,h_n: the price of each ticket.
The last line contains m integers t_1,t_2,...,t_m: the maximum price for each customer in the order they arrive.

Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.

*/


struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.reserve(n);
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int n) {
        if (n < 0) return -1;
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void remove(int n) {
        parent[n] = find(n - 1);
    }
}; 

int main() {
    
    int n;
    int m;
    vector<int> prices;
    vector<int> maxPrices;

    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        prices.push_back(val);
        
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        maxPrices.push_back(val);
    }

    sort(prices.begin(), prices.end());

    DSU lookup = DSU(n);


    for (int i = 0; i < m; i++) {
        int maxPrice = maxPrices[i];

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = (l + r + 1) / 2;

            if (prices[mid] > maxPrice) {
                r = mid - 1;
            } else {
                l = mid; 
            }
        }

        int best_idx = -1;
        if (prices[l] <= maxPrice) {
            best_idx = l;
        }

        int actual_idx = lookup.find(best_idx);

        if (actual_idx == -1) {
            cout << -1 << "\n";
        } else {
            cout << prices[actual_idx] << "\n";
            lookup.remove(actual_idx);
        }

    }
}