// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
#include <iostream>
using namespace std;

bool isVowel(char c)
{
    // "A", "E", "I", "O", and "U"
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
int solve(string s)
{
    int count[26] = {};
    int maxVowel = 0, maxConsonant = 0;
    int cVowel = 0, cConsonant = 0;
    for (char c : s)
    {
        count[c - 'A']++;
        if (isVowel(c))
        {
            cVowel++;
            maxVowel = max(maxVowel, count[c - 'A']);
        }
        else
        {
            cConsonant++;
            maxConsonant = max(maxConsonant, count[c - 'A']);
        }
    }
    // Two options
    // Make all the characters same as the consonant that occurs the maximum time.
    // Cost1: # of vowels + 2*(# consonants - maxFreq of consonant)
    // All vowel
    // Make all the characters same as the vowel that occurs the maximum time.
    // Cost2: # of consonants + 2*(# vowels - maxFreq of Vowel)
    // min(cost1,cost2)
    return min(cVowel + 2 * (cConsonant - maxConsonant), cConsonant + 2 * (cVowel - maxVowel));
}
int main()
{
    freopen("consistency_chapter_1_input.txt", "r", stdin);
    freopen("consistency_chapter_1_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s;
        cin >> s;
        printf("Case #%d: %d\n", t, solve(s));
    }
}
// FOXEN