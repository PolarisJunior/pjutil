
#include <gtest/gtest.h>

TEST(sample, sample_test)
{
  SUCCEED();
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
