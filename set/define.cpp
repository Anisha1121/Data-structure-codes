#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
  unordered_set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);

  cout << "Elements in the unordered set: ";
  for (int elem : s)
  {
    cout << elem << " ";
  }
  cout << endl;

  return 0;
}