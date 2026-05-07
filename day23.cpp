#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'downToZero' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
int downToZero(int n) {
    // 1. Create our "Shortcut Map" only once
    static int res[1000001] = {0};
    static bool initialized = false;

    if (!initialized) {
        for (int i = 1; i <= 1000000; i++) {
            // Option A: Step down by 1
            // If res[i] hasn't been set by a jump yet, or if stepping 
            // from (i-1) is faster, update it.
            if (res[i] == 0 || res[i] > res[i - 1] + 1) {
                res[i] = res[i - 1] + 1;
            }

            // Option B: Magic Portals (Multiplication)
            // If we are at i, we can reach i * j in one move.
            // We only check j <= i so that 'i' is always the max factor.
            for (int j = 2; j <= i && i * j <= 1000000; j++) {
                if (res[i * j] == 0 || res[i * j] > res[i] + 1) {
                    res[i * j] = res[i] + 1;
                }
            }
        }
        initialized = true;
    }

    // 2. Just return the answer from our map!
    return res[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
