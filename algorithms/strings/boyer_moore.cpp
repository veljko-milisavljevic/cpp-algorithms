// Boyer–Moore string search with the bad-character rule.
//
// Input:  two whitespace-separated words, the text and the pattern.
// Output: the 0-based index of the first occurrence of the pattern in the text,
//         or -1 if it does not occur.
//
// The pattern is compared right to left. On a mismatch, the pattern is shifted
// so that the mismatched text character lines up with its last occurrence in
// the pattern (or moves past it if the character does not occur at all).
//
// Time: O(n * m) worst case, typically sub-linear on natural text; memory: O(σ),
// where σ = 256 is the alphabet size.

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

int boyerMooreSearch(const string& text, const string& pattern)
{
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());
    if (m == 0) return 0;

    // Last index of every byte value in the pattern, -1 if absent.
    array<int, 256> last;
    last.fill(-1);
    for (int i = 0; i < m; i++)
    {
        last[static_cast<unsigned char>(pattern[i])] = i;
    }

    int shift = 0; // current alignment of pattern[0] in the text
    while (shift <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) j--;

        if (j < 0) return shift; // full match

        int badCharIndex = last[static_cast<unsigned char>(text[shift + j])];
        shift += max(1, j - badCharIndex);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    cout << boyerMooreSearch(text, pattern) << '\n';
    return 0;
}
