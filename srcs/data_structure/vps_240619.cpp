#include <iostream>
#include <string>

class VPS {
  int open_ = 0;
  int close_ = 0;

 public:
  void Clear() { open_ = close_ = 0; }

  bool Input(std::string input_string) {
    for (const auto& c : input_string) {
      if (c == '(')
        open_++;
      else if (c == ')') {
        close_++;

        // 열린 괄호보다 더 많이 괄호가 닫힌 경우
        if (open_ < close_) return false;
      }
    }
    return open_ == close_;
  }
};

int main() {
  int operation_count;
  std::cin >> operation_count;

  std::cin.ignore();

  VPS vps;

  for (int i = 0; i < operation_count; i++) {
    std::string input;
    std::cin >> input;

    std::cout << (vps.Input(input) ? "YES" : "NO") << std::endl;

    vps.Clear();
  }
  return 0;
}