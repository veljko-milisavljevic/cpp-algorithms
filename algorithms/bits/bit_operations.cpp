// Basic bit manipulation on 8-bit values.
//
// Input:  an operation and its arguments, one query per line:
//   print x        binary representation of x (8 bits)
//   clear x mask   x with every bit that is set in mask cleared   (x & ~mask)
//   toggle x mask  x with every bit that is set in mask inverted  (x ^ mask)
//   rotr x k       x rotated right by k bits within 8 bits
// Output: one line per query.
//
// Time and memory: O(1) per query.

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

string toBinary(uint8_t x)
{
    string bits(8, '0');
    for (int i = 7; i >= 0; i--, x >>= 1)
    {
        if (x & 1) bits[i] = '1';
    }
    return bits;
}

uint8_t clearBits(uint8_t x, uint8_t mask) { return x & static_cast<uint8_t>(~mask); }

uint8_t toggleBits(uint8_t x, uint8_t mask) { return x ^ mask; }

uint8_t rotateRight(uint8_t x, unsigned k)
{
    k %= 8;
    if (k == 0) return x;
    return static_cast<uint8_t>((x >> k) | (x << (8 - k)));
}

int main()
{
    string op;
    while (cin >> op)
    {
        unsigned x, arg = 0;
        cin >> x;
        if (op != "print") cin >> arg;

        uint8_t v = static_cast<uint8_t>(x);
        if (op == "print") cout << toBinary(v);
        else if (op == "clear") cout << +clearBits(v, static_cast<uint8_t>(arg));
        else if (op == "toggle") cout << +toggleBits(v, static_cast<uint8_t>(arg));
        else if (op == "rotr") cout << +rotateRight(v, arg);
        else cout << "unknown operation";
        cout << '\n';
    }
    return 0;
}
