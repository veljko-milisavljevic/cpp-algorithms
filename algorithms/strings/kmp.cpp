// Knuth–Morris–Pratt string search.
//
// Input:  two whitespace-separated words, the text and the pattern.
// Output: the 0-based index of the first occurrence of the pattern in the text,
//         or -1 if it does not occur.
//
// Time: O(n + m), memory: O(m), where n = |text|, m = |pattern|.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// lps[i] = length of the longest proper prefix of pattern[0..i]
// that is also a suffix of pattern[0..i].
vector<int> buildLps(const string& pattern)
{
    vector<int> lps(pattern.size(), 0);
    size_t len = 0;
    size_t j = 1;
    while (j < pattern.size())
    {
        if (pattern[j] == pattern[len])
        {
            lps[j++] = static_cast<int>(++len);
        }
        else if (len == 0)
        {
            j++;
        }
        else
        {
            len = lps[len - 1];
        }
    }
    return lps;
}

int kmpSearch(const string& text, const string& pattern)
{
    if (pattern.empty()) return 0;

    vector<int> lps = buildLps(pattern);
    size_t i = 0; // position in text
    size_t j = 0; // position in pattern
    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == pattern.size()) return static_cast<int>(i - j);
        }
        else if (j != 0)
        {
            j = lps[j - 1];
        }
        else
        {
            i++;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    cout << kmpSearch(text, pattern) << '\n';
    return 0;
}
