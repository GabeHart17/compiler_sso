#include <iostream>


class C {
private:
  int num_;
public:
  C(int n) : num_(n) {};
  operator bool() const {return num_ > 100;}
};

int main(int argc, char const *argv[]) {
  C test(5);
  C test2(500);
  std::cout << (bool) test << '\n' << (bool) test2 << '\n' << !test << '\n';
  if (test2 && !test) {
    std::cout << "a" << '\n';
  }
  return 0;
}
