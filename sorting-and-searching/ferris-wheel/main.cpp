
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p_1,p_2,...,p_n: the weight of each child.
Output
Print one integer: the minimum number of gondolas.





int[] nums

pick up to 2 from nums

cannot exceed x

goal: # of gondolas



Example:
1,3,5
x = 9
*/


/*
Possible algorithm:
1. pick from list[-1]
2. check if can add with list[0]
3. If exceeds, then no need to check further, due to the invariant x_1 <= x2 <= ... <= x_n. x2 wouldnt fit either
4. Remove both from list (or advance ptr using 2ptr)


[3,7,] limit = 10



x1,x2,x3,x4 limit = 10

is it possible that [x1,x4] robs us of a better selection?
e.g. maybe we get:
[x1,x4]
[x2]
[x3]

Could it have been argued that we could of picked a "bigger" number to close the gap?
example: 
[x2,x4] 
[x1,x3]

Since x1 <= x2, so picking x2 may end up closing our gap.

if (x2 + x4) <= limit is satisfied, then we can deduce the following:
(x1 + x4) <= limit (becuse x1 <= x2)
(x2 + x3) <= limit (because x3 <= x4)
(x1 + x3) <= limit (because x1 + x3 <= x2 + x4)

because of the monotonically nondecreasing invariant. Thus if the following were possible:
[x2, x4]
[x1, x3]

[x2] and [x3] would never be alone by themselves. [x2,x3] can be safely added together.
*/
int main() {
    int numChildren;
    int maxWeight;
    vector<int> cWeight;

    cin >> numChildren;
    cin >> maxWeight;
    cWeight.reserve(numChildren);
    
    for (int i = 0; i < numChildren; i++) {
        int weight;
        cin >> weight;
        
        cWeight.push_back(weight);
    }

    sort(cWeight.begin(), cWeight.end());

    int l = 0;
    int r = numChildren - 1;
    int res = 0;

    
    while(l <= r){
        if(l == r){ // Single child.
            res += 1;
            break;
        }
        int lWeight = cWeight[l];
        int rWeight = cWeight[r];

        if(lWeight + rWeight <= maxWeight){ // can fit both into 1 gondola
            res += 1;

            l += 1;
            r -= 1;
        } else { // need separate gondola for the larger one.
            res += 1;

            r -= 1;
        }
    }
    cout << res;
    return 0;
}