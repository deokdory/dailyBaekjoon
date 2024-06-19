#include <iostream>
#include <string>

class Stack {
  int* data_;
  size_t size_ = 0;

 public:
  Stack(size_t max_size) { data_ = new int[max_size]; }
  ~Stack() { delete[] data_; }

  void push(int X) {
    data_[size_] = X;
    size_++;
  }

  size_t size() const { return size_; }

  bool empty() const { return size_ == 0; }

  int top() const {
    if (empty()) return -1;
    return data_[size_ - 1];
  }

  int pop() {
    if (empty()) return -1;
    size_--;
    return data_[size_];
  }
};

int main() {
  size_t num_of_cmd = 0;
  std::cin >> num_of_cmd;

  Stack stack(num_of_cmd);

  for (size_t i = 0; i < num_of_cmd; i++) {
    std::string cmd;
    int X = 0;

    std::cin >> cmd;
    if (cmd == "push") std::cin >> X;

    std::cin.ignore();

    if (cmd == "push") {
      stack.push(X);
    } else if (cmd == "pop") {
      std::cout << stack.pop() << std::endl;
    } else if (cmd == "size") {
      std::cout << stack.size() << std::endl;
    } else if (cmd == "empty") {
      std::cout << stack.empty() << std::endl;
    } else {
      std::cout << stack.top() << std::endl;
    }
  }

  return 0;
}