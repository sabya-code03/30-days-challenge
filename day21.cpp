#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = indexes.size();
    
   
    vector<int> depths(n + 1, 0); 
    depths[1] = 1; 
    
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        int left = indexes[node - 1][0];
        int right = indexes[node - 1][1];
        
        if (left != -1) {
            depths[left] = depths[node] + 1;
            q.push(left);
        }
        if (right != -1) {
            depths[right] = depths[node] + 1;
            q.push(right);
        }
    }
    
    vector<vector<int>> result;
    
    function<void(int, vector<int>&)> inorder = [&](int node, vector<int>& current_res) {
        if (node == -1) return;
        
        inorder(indexes[node - 1][0], current_res);
     
        current_res.push_back(node);
      
        inorder(indexes[node - 1][1], current_res);
    };
  
    for (int k : queries) {
      
        for (int i = 1; i <= n; i++) {
            if (depths[i] % k == 0) {
                swap(indexes[i - 1][0], indexes[i - 1][1]);
            }
        }
        
        vector<int> current_res;
        inorder(1, current_res);
        result.push_back(current_res);
    }
    
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
