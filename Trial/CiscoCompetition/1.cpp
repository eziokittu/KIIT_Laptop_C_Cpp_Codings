#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'GetMaxPoints' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY markers as parameter.
 */



int optimalSelection(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // Fill the diagonal elements of dp[][]
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    // Build dp[][] in bottom-up manner
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            int x = i + 2 <= j ? dp[i + 2][j] : 0;
            int y = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0;
            int z = i <= j - 2 ? dp[i][j - 2] : 0;

            dp[i][j] = std::max(nums[i] + std::min(x, y), nums[j] + std::min(y, z));
        }
    }

    return dp[0][n - 1];
}

int GetMaxPoints(vector<int> markers) {
    return optimalSelection(markers);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string markers_count_temp;
    getline(cin, markers_count_temp);

    int markers_count = stoi(ltrim(rtrim(markers_count_temp)));

    vector<int> markers(markers_count);

    for (int i = 0; i < markers_count; i++) {
        string markers_item_temp;
        getline(cin, markers_item_temp);

        int markers_item = stoi(ltrim(rtrim(markers_item_temp)));

        markers[i] = markers_item;
    }

    int result = GetMaxPoints(markers);

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