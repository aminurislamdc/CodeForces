#include <bits/stdc++.h> // Includes all standard libraries

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; // Read number of test cases

    while (n--) {
        string s;
        cin >> s; // Read the word

        if (s.length() > 10) {
            // "Too long": Print first char + middle length + last char
            cout << s[0] << s.length() - 2 << s.back() << "\n";
        } else {
            // Short enough: Print as is
            cout << s << "\n";
        }
    }

    return 0;
}
