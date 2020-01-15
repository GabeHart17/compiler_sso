#include <iostream>
#include <vector>


int main(int argc, char const *argv[]) {
  std::vector<int> v = {1, 2, 5, 11, 27};
  // std::cout << v.back() << '\n';
  std::cout << *(v.end() - 1) << '\n';
  std::cout << *(v.end() - 2) << '\n';
  return 0;
}
