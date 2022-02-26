#include <iostream>
#include <string>

using namespace std;

bool isAlice(char c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string GetRuler(const string &kingdom)
{
  // TODO: implement this method to determine the ruler name, given the kingdom.
  string ruler = "";
  if (isAlice(tolower(kingdom.back())))
  {
    ruler = "Alice";
  }
  else if (tolower(kingdom.back()) == 'y')
  {
    ruler = "nobody";
  }
  else
  {
    ruler = "Bob";
  }
  return ruler;
}

int main()
{
  int testcases;
  cin >> testcases;
  string kingdom;

  for (int t = 1; t <= testcases; ++t)
  {
    cin >> kingdom;
    cout << "Case #" << t << ": " << kingdom << " is ruled by "
         << GetRuler(kingdom) << ".\n";
  }
  return 0;
}
