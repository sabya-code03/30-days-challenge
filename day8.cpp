include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'substringDiff' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. STRING s1
 *  3. STRING s2
 */
int solve(int k, const string& s1, const string& s2, int start1, int start2) {
    int max_len = 0;
    int mismatches = 0;
    int left = 0;
    int n = s1.length();
    
    // Sliding window logic
    for (int right = 0; (start1 + right < n) && (start2 + right < n); ++right) {
        // If characters at current window end don't match, increment mismatch count
        if (s1[start1 + right] != s2[start2 + right]) {
            mismatches++;
        }
        
        // If we have too many mistakes, shrink from the left
        while (mismatches > k) {
            if (s1[start1 + left] != s2[start2 + left]) {
                mismatches--;
            }
            left++;
        }
        
        // Update the global maximum length found so far
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int substringDiff(int k, string s1, string s2) {
    int n = s1.length();
    int result = 0;

    // We check two main scenarios:
    // 1. s1 starts at 0, and we slide s2
    for (int j = 0; j < n; ++j) {
        result = max(result, solve(k, s1, s2, 0, j));
    }
    
    // 2. s2 starts at 0, and we slide s1
    for (int i = 1; i < n; ++i) {
        result = max(result, solve(k, s1, s2, i, 0));
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int k = stoi(first_multiple_input[0]);

        string s1 = first_multiple_input[1];

        string s2 = first_multiple_input[2];

        int result = substringDiff(k, s1, s2);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
