#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void print(const vector<pair<int, int>> &v)
{
  for (const auto &i : v)
  {
    cout << "[" << i.first << ", " << i.second << "] ";
  }
  cout << endl; // Add this to print on new line
}

int monstersDefeated(int n, int e, vector<pair<int, int>> monsters)
{
  print(monsters);
  sort(monsters.begin(), monsters.end(),
    [](const pair<int, int> &a, const pair<int, int> &b)
    {
      return a.first < b.first;
    });
  print(monsters);

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (monsters[i].first <= e)
    {
      e += monsters[i].second;
      count++;
    }
    else
    {
      return count;
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  int e;
  cin >> e;
  vector<int> power(n), bonus(n);
  for (int i = 0; i < n; i++)
  {
    cin >> power[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> bonus[i];
  }

  vector<pair<int, int>> monsters;
  for (int i = 0; i < n; i++)
  {
    monsters.push_back({power[i], bonus[i]});
  }
  cout << monstersDefeated(n, e, monsters);
}
