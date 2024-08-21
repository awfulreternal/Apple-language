#include <iostream>
#include <boost/format.hpp>

int main() {
  int age = 30;
  std::string name = "John";

  std::cout << boost::format("My name is %s and I am %d years old.") % name % age << std::endl;
  return 0;
}
