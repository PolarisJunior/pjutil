
#include <gtest/gtest.h>
#include <pjutil/container/parallel_deque.hpp>

TEST(parallel_deque, basic) {
  using namespace pjutil;

  ParallelDeque<int> deque;
  deque.push_back(3);
  deque.push_back(4);
  ASSERT_EQ(deque.size(), 2);
  deque.push_front(5);

  ASSERT_EQ(deque.pop_back(), 4);
  ASSERT_EQ(deque.pop_front(), 5);
  ASSERT_EQ(deque.size(), 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
