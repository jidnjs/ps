// codeforces 886D
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool hasDuplicate(array<bool, 26> &checkcheck, const string &s) {
    for (char c : s) {
        int idx = c - 'a';
        if (checkcheck[idx]) return true;
        checkcheck[idx] = true;
    }
    return false;
}

void uncheckCheckCheck(array<bool, 26> &checkcheck, const string &s) {
    for (char c : s) {
        int idx = c - 'a';
        checkcheck[idx] = false;
    }
}

bool isValidString(vector<string> &distinctsSubs, string &s, array<bool, 26> &checkcheck) {
    if (s.size() > 26) return false;

    stack<string> toRemove;

    for (string &sub: distinctsSubs) {
        if (sub.contains(s)) {
            return true;
        } else if (s.contains(sub)) {
            toRemove.push(sub);
            uncheckCheckCheck(checkcheck, sub);
        } else {
            int pos = sub.find_last_of(s.front());
            if (pos != string::npos) {
                string overlap1 = sub.substr(pos);
                string overlap2 = s.substr(0, sub.size() - pos);
                if (overlap1 == overlap2) {
                    s = sub.substr(0, pos) + s;
                    toRemove.push(sub);
                    uncheckCheckCheck(checkcheck, sub);
                    continue;
                } else {
                    return false;
                }
            }
            pos = s.find_last_of(sub.front());
            if (pos != string::npos) {
                string overlap1 = s.substr(pos);
                string overlap2 = sub.substr(0, s.size() - pos);
                if (overlap1 == overlap2) {
                    s = s.substr(0, pos) + sub;
                    toRemove.push(sub);
                    uncheckCheckCheck(checkcheck, sub);
                } else {
                    return false;
                }
            }
        }
    }

    while (not toRemove.empty()) {
        erase(distinctsSubs, toRemove.top());
        toRemove.pop();
    }

    distinctsSubs.push_back(s);
    return not hasDuplicate(checkcheck, s);
}

bool solvable(vector<string> &distinctsSubs, int n) {
    string s;
    array<bool, 26> checkcheck = {};
    while (n--) {
        cin >> s;

        if (not isValidString(distinctsSubs, s, checkcheck)) return false;
    }
    return true;
}

int main()
{
    int n;
    string result = "";
    vector<string> distinctsSubs;

    cin >> n;
    if (solvable(distinctsSubs, n)) {
        sort(distinctsSubs.begin(), distinctsSubs.end());
        for (string &s: distinctsSubs) {
            result += s;
        }
    } else {
        result = "NO";
    }
    cout << result << "\n";
}
