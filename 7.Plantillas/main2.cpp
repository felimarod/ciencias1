#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

#define STRING(num) #num

int main() {
  string num = STRING(1234);
    num.empty() ? cout << "empty\n" :
                       cout << num << endl;

    return EXIT_SUCCESS;
}
