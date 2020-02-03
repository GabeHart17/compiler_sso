#include <iostream>
#include <vector>


enum class EC {A, B, C};

int main(int argc, char const *argv[]) {
  std::cout << ((int) EC::B == 1) << '\n' << ((int) EC::A == 1) << '\n';
  std::vector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(15);
  std::vector<int>::iterator i = v.begin();
  std::cout << *(i++) << '\n' << *i << '\n';
  return 0;
}
