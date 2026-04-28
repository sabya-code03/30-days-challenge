#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    //  I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    
    stack<int> s1;
    stack<int> s2; 
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            s1.push(x); 
        } else {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            
            if (type == 2) {
                s2.pop(); 
            } else if (type == 3) {
                cout << s2.top() << "\n"; 
            }
        }
    }
    return 0;
}
