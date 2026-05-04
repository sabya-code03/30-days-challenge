#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>    

#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {
    // We use multisets because they stay sorted and allow duplicates
    multiset<long long> left, right;

    for (int i = 0; i < s.size(); i++) {
        char op = s[i];
        long long x = X[i];
        bool found = true;

        if (op == 'r') {
            // Try to find and remove the number from either bucket
            auto it = left.find(x);
            if (it != left.end()) {
                left.erase(it);
            } else {
                it = right.find(x);
                if (it != right.end()) {
                    right.erase(it);
                } else {
                    found = false; // Number wasn't in the list
                }
            }
        } else {
            // 'a' for add: put it in 'left' if it's small, otherwise 'right'
            if (left.empty() || x <= *left.rbegin()) {
                left.insert(x);
            } else {
                right.insert(x);
            }
        }

        // --- Rebalancing Act ---
        // We ensure left.size() is either equal to right.size() 
        // or exactly one element larger.
        if (found) {
            if (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            } else if (right.size() > left.size()) {
                auto it = right.begin();
                left.insert(*it);
                right.erase(it);
            }
        }

        // --- Output Logic ---
        if (!found || left.empty()) {
            printf("Wrong!\n");
        } else {
            if (left.size() > right.size()) {
                // Odd total: Median is the max of the smaller half
                printf("%lld\n", *left.rbegin());
            } else {
                // Even total: Average of the two middle elements
                long long sum = *left.rbegin() + *right.begin();
                if (sum % 2 == 0) {
                    printf("%lld\n", sum / 2);
                } else {
                    // Using .1f ensures we print .5 without extra trailing zeros
                    double med = sum / 2.0;
                    printf("%.1f\n", med);
                }
            }
        }
    }
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;
	
	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	
	median(s,X);
	return 0;
}
