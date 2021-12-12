#include <iostream>
#include <string>
using namespace std;

// fixed mod opperator
// http://www.cplusplus.com/forum/general/19502/
template <typename T, typename OP> struct modulo { T bace; };

enum { mod };

template <typename T>
modulo<T, decltype(mod)> operator<(const T &front, decltype(mod)) {
  return {front};
}

template <typename T> T operator>(modulo<T, decltype(mod)> tail, T exponent) {
  T &bace = tail.bace;
  return bace % exponent < 0 ? (bace % exponent) + exponent : bace % exponent;
}

template <typename T> T abs(T num) { return num < 0 ? num * -1 : num; }

class ternaryConverter {
private:
  static string balancedTernary(int64_t n) {
    string output = "";
    bool invert = 0;

    if (n < 0)
      invert = 1;

    while (abs(n) > 0) {
      int rem = abs(n) <mod> int64_t(3);
      n = abs(n) / 3;

      if (rem == 2) {
        rem = -1;
        n++;
      }

      output = (invert ? rem == 1 ? '-' : rem == -1 ? '+' : '0' : rem == 1 ? '+' : rem == -1 ? '-' : '0') + output;
    }

    return output;
  }

public:
  static string balancedConvert(int64_t input) {
    return balancedTernary(input);
  }
};

int main() {
  int64_t N;
  cin >> N;

  cout << ternaryConverter::balancedConvert(N);
}
