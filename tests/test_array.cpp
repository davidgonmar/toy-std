#include <toy-std/array.hpp>
#include <gtest/gtest.h>


class Base: public ::testing::Test {
public:
  toy::array<int, 5> arr;
  void SetUp() override {
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
  }
  void TearDown() override {}
};



TEST_F(Base, at) {
  EXPECT_EQ(arr.at(0), 1);
  EXPECT_EQ(arr.at(1), 2);
  EXPECT_EQ(arr.at(2), 3);
  EXPECT_EQ(arr.at(3), 4);
  EXPECT_EQ(arr.at(4), 5);
  EXPECT_THROW(arr.at(5), toy::out_of_range);
}

TEST_F(Base, operator_brackets) {
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
  EXPECT_EQ(arr[3], 4);
  EXPECT_EQ(arr[4], 5);
}

TEST_F(Base, front) {
  EXPECT_EQ(arr.front(), 1);
}

TEST_F(Base, back) {
  EXPECT_EQ(arr.back(), 5);
}

TEST_F(Base, size) {
  EXPECT_EQ(arr.size(), 5);
}

TEST_F(Base, data) {
  EXPECT_EQ(arr.data(), &arr[0]);
}


int main() {

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();

}