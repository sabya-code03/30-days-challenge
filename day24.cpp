#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long largestRectangle(vector<int> h) {
    stack<int> s;
    long max_area = 0;
    int n = h.size();
    int i = 0;

    while (i < n) {
        
        if (s.empty() || h[s.top()] <= h[i]) {
            s.push(i);
            i++;
        } else {
            
            int top_index = s.top();
            s.pop();
            
            long width = s.empty() ? i : (i - s.top() - 1);
            long current_area = (long)h[top_index] * width;
            
            max_area = max(max_area, current_area);
        }
    }

    while (!s.empty()) {
        int top_index = s.top();
        s.pop();
        
        long width = s.empty() ? i : (i - s.top() - 1);
        long current_area = (long)h[top_index] * width;
        
        max_area = max(max_area, current_area);
    }

    return max_area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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
