
#include <pjutil/container/parallel_deque.hpp>

using namespace pjutil;

int main(int argc, char **argv) {
  ParallelDeque<int> deque;
  deque.push_back(5);
  deque.push_back(3);

  return 0;
}
