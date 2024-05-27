#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "../s21_containersplus.h"

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА VECTOR (START) ==========
*/

TEST(test_class_vector, default_constructor) {
  s21::vector<int> vector_;
  EXPECT_EQ((int)vector_.size(), 0);
  EXPECT_EQ((int)vector_.capacity(), 0);
  EXPECT_EQ(vector_.data(), nullptr);
}

TEST(test_class_vector, copy_constructor) {
  s21::vector<int> vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> vector_2(vector_1);
  EXPECT_EQ(vector_2.size(), vector_1.size());
  EXPECT_EQ(vector_2.capacity(), vector_1.capacity());
  EXPECT_EQ(vector_2[0], 1);
  EXPECT_EQ(vector_2[1], 2);
  EXPECT_EQ(vector_2[2], 3);
  EXPECT_EQ(vector_2[3], 4);
  EXPECT_EQ(vector_2[4], 5);
}

TEST(test_class_vector, move_constructor) {
  s21::vector<int> vector_1 = {1, 2, 3, 4, 5};
  int size = vector_1.size();
  int capacity = vector_1.capacity();
  s21::vector<int> vector_2(std::move(vector_1));
  EXPECT_EQ((int)vector_2.size(), size);
  EXPECT_EQ((int)vector_2.capacity(), capacity);
  EXPECT_EQ(vector_2[0], 1);
  EXPECT_EQ(vector_2[1], 2);
  EXPECT_EQ(vector_2[2], 3);
  EXPECT_EQ(vector_2[3], 4);
  EXPECT_EQ(vector_2[4], 5);
  EXPECT_EQ((int)vector_1.size(), 0);
  EXPECT_EQ((int)vector_1.capacity(), 0);
  EXPECT_EQ(vector_1.data(), nullptr);
}

// TEST(test_class_vector, parameterized_constructor_1) {
//   s21::vector<int> vector_(5);
//   EXPECT_EQ((int)vector_.size(), 5);
//   EXPECT_EQ((int)vector_.capacity(), 5);
//   EXPECT_EQ(vector_[0], 0);
//   EXPECT_EQ(vector_[1], 0);
//   EXPECT_EQ(vector_[2], 0);
//   EXPECT_EQ(vector_[3], 0);
//   EXPECT_EQ(vector_[4], 0);
// }

TEST(test_class_vector, parameterized_constructor_2) {
  EXPECT_ANY_THROW(s21::vector<int> vector_(-5));
}

TEST(test_class_vector, initializer_list_constructor_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ((int)vector_.size(), 5);
  EXPECT_EQ((int)vector_.capacity(), 5);
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 3);
  EXPECT_EQ(vector_[3], 4);
  EXPECT_EQ(vector_[4], 5);
}

TEST(test_class_vector, initializer_list_constructor_2) {
  s21::vector<int> vector_ = {};
  EXPECT_EQ((int)vector_.size(), 0);
  EXPECT_EQ((int)vector_.capacity(), 0);
  EXPECT_EQ(vector_.data(), nullptr);
}

TEST(test_class_vector, begin_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  int* pointer = vector_.data();
  EXPECT_EQ(vector_.begin(), pointer);
}

TEST(test_class_vector, begin_2) {
  s21::vector<int> vector_;
  EXPECT_ANY_THROW(vector_.begin());
}

TEST(test_class_vector, end_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  int* pointer = vector_.data();
  EXPECT_EQ(vector_.end(), pointer + vector_.size());
}

TEST(test_class_vector, end_2) {
  s21::vector<int> vector_;
  EXPECT_ANY_THROW(vector_.end());
}

TEST(test_class_vector, insert_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator it = vector_.begin();
  vector_.insert(it + 2, 10);
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 10);
  EXPECT_EQ(vector_[3], 3);
  EXPECT_EQ(vector_[4], 4);
  EXPECT_EQ(vector_[5], 5);
}

// TEST(test_class_vector, insert_2) {
//   s21::vector<int> vector_ = {1, 2, 3, 4, 5};
//   s21::vector<int>::iterator it = vector_.begin();
//   EXPECT_ANY_THROW(vector_.insert(it + 12, 10));
// }

TEST(test_class_vector, data_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  int* copy = vector_.data();
  EXPECT_EQ(copy[0], vector_[0]);
  EXPECT_EQ(copy[1], vector_[1]);
  EXPECT_EQ(copy[2], vector_[2]);
  EXPECT_EQ(copy[3], vector_[3]);
  EXPECT_EQ(copy[4], vector_[4]);
}

TEST(test_class_vector, data_2) {
  s21::vector<int> vector_;
  int* copy = vector_.data();
  EXPECT_EQ(copy, nullptr);
}

TEST(test_class_vector, at_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ(vector_.at(0), 1);
  EXPECT_EQ(vector_.at(1), 2);
  EXPECT_EQ(vector_.at(2), 3);
  EXPECT_EQ(vector_.at(3), 4);
  EXPECT_EQ(vector_.at(4), 5);
}

TEST(test_class_vector, at_2) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(vector_.at(10));
}

TEST(test_class_vector, back_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ(vector_.back(), 5);
}

TEST(test_class_vector, back_2) {
  s21::vector<int> vector_;
  EXPECT_ANY_THROW(vector_.back());
}

TEST(test_class_vector, front_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ(vector_.front(), 1);
}

TEST(test_class_vector, front_2) {
  s21::vector<int> vector_;
  EXPECT_ANY_THROW(vector_.front());
}

TEST(test_class_vector, assignment_operator) {
  s21::vector<int> vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> vector_2 = vector_1;
  EXPECT_EQ(vector_2.size(), vector_1.size());
  EXPECT_EQ(vector_2.capacity(), vector_2.capacity());
  EXPECT_EQ(vector_2[0], 1);
  EXPECT_EQ(vector_2[1], 2);
  EXPECT_EQ(vector_2[2], 3);
  EXPECT_EQ(vector_2[3], 4);
  EXPECT_EQ(vector_2[4], 5);
}

TEST(test_class_vector, brackets_operator) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_[2] = 5;
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 5);
  EXPECT_EQ(vector_[3], 4);
  EXPECT_EQ(vector_[4], 5);
}

TEST(test_class_vector, empty_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ(vector_.empty(), false);
}

TEST(test_class_vector, empty_2) {
  s21::vector<int> vector_;
  EXPECT_EQ(vector_.empty(), true);
}

TEST(test_class_vector, size) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  EXPECT_EQ((int)vector_.size(), 5);
}

TEST(test_class_vector, max_size) {
  std::vector<int> vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> vector_2 = {1, 2, 3, 4, 5};
  printf("std::vector.max_size = %lu\n", vector_1.max_size());
  printf("s21::vector.max_size = %lu\n", vector_2.max_size());
}

TEST(test_class_vector, capacity) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.push_back(6);
  EXPECT_EQ((int)vector_.capacity(), 10);
}

TEST(test_class_vector, clear) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.clear();
  EXPECT_EQ((int)vector_.size(), 0);
}

TEST(test_class_vector, pop_back) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.pop_back();
  EXPECT_EQ((int)vector_.size(), 4);
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 3);
  EXPECT_EQ(vector_[3], 4);
}

TEST(test_class_vector, shrink_to_fit) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.push_back(6);
  vector_.shrink_to_fit();
  EXPECT_EQ((int)vector_.capacity(), 6);
}

TEST(test_class_vector, erase_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator it = vector_.begin();
  vector_.erase(it + 2);
  EXPECT_EQ((int)vector_.size(), 4);
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 4);
  EXPECT_EQ(vector_[3], 5);
}

// TEST(test_class_vector, erase_2) {
//   s21::vector<int> vector_ = {1, 2, 3, 4, 5};
//   s21::vector<int>::iterator it = vector_.begin();
//   EXPECT_ANY_THROW(vector_.erase(it + 12));
//   EXPECT_EQ((int)vector_.size(), 5);
// }

TEST(test_class_vector, swap) {
  s21::vector<int> vector_1 = {1, 2, 3, 4, 5};
  s21::vector<int> vector_2 = {5, 4, 3, 2, 1};
  vector_1.swap(vector_2);
  EXPECT_EQ(vector_1[0], 5);
  EXPECT_EQ(vector_1[1], 4);
  EXPECT_EQ(vector_1[2], 3);
  EXPECT_EQ(vector_1[3], 2);
  EXPECT_EQ(vector_1[4], 1);

  EXPECT_EQ(vector_2[0], 1);
  EXPECT_EQ(vector_2[1], 2);
  EXPECT_EQ(vector_2[2], 3);
  EXPECT_EQ(vector_2[3], 4);
  EXPECT_EQ(vector_2[4], 5);
}

TEST(test_class_vector, reserve_1) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.reserve(10);
  EXPECT_EQ((int)vector_.capacity(), 10);
}

// TEST(test_class_vector, reserve_2) {
//   s21::vector<int> vector_ = {1, 2, 3, 4, 5};
//   vector_.reserve(3);
//   EXPECT_EQ((int)vector_.capacity(), 5);
// }

TEST(test_class_vector, push_back) {
  s21::vector<int> vector_ = {1, 2, 3, 4, 5};
  vector_.push_back(6);
  vector_.push_back(7);
  vector_.push_back(8);
  vector_.push_back(9);
  vector_.push_back(10);
  vector_.push_back(11);
  EXPECT_EQ((int)vector_.size(), 11);
  EXPECT_EQ((int)vector_.capacity(), 20);
  EXPECT_EQ(vector_[0], 1);
  EXPECT_EQ(vector_[1], 2);
  EXPECT_EQ(vector_[2], 3);
  EXPECT_EQ(vector_[3], 4);
  EXPECT_EQ(vector_[4], 5);
  EXPECT_EQ(vector_[5], 6);
  EXPECT_EQ(vector_[6], 7);
  EXPECT_EQ(vector_[7], 8);
  EXPECT_EQ(vector_[8], 9);
  EXPECT_EQ(vector_[9], 10);
  EXPECT_EQ(vector_[10], 11);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА VECTOR (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА SET (START) ==========
*/

TEST(set_test, constructor1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, constructor3) {
  const s21::set<int> s1{4};
  const std::set<int> s2{4};
  s21::set<int>::const_iterator it1 = s1.begin();
  std::set<int>::const_iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = s1;
  std::set<int> s22 = s2;
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constructor5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = std::move(s1);
  std::set<int> s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, move_operator1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s11 = std::move(s1);
  s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, begin1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, end1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  EXPECT_EQ(*it2, *it1);
}

TEST(set_test, end2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(*it1, std::invalid_argument);
}

TEST(set_test, iterator1) {
  s21::set<int>::iterator it;
  EXPECT_THROW(*it, std::invalid_argument);
}

TEST(set_test, iterator2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  for (; it2 != s2.begin(); --it1, --it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iterator3) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  s21::set<int>::iterator it2 = s1.end();
  --(--it1), --(--it2);
  EXPECT_TRUE(it1 == it2);
}

TEST(set_test, iterator4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++it1), ++(++(++it2));
  EXPECT_TRUE(it1 != it2);
}

TEST(set_test, iterator5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++it1, ++(++(++it2));
  EXPECT_FALSE(it1 == it2);
}

TEST(set_test, iterator6) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++(++it1)), ++(++(++it2));
  EXPECT_FALSE(it1 != it2);
}

TEST(set_test, iterator7) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  EXPECT_THROW(--it1, std::invalid_argument);
}

TEST(set_test, iterator8) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(++it1, std::invalid_argument);
}

TEST(set_test, iterator9) {
  s21::set<int>::iterator it;
  EXPECT_THROW(++it, std::invalid_argument);
}

TEST(set_test, iterator10) {
  s21::set<int>::iterator it;
  EXPECT_THROW(--it, std::invalid_argument);
}

TEST(set_test, iterator11) {
  s21::set<std::pair<int, int>> s1{{1, 7}};
  std::set<std::pair<int, int>> s2{{1, 7}};
  s21::set<std::pair<int, int>>::iterator it1 = s1.begin();
  std::set<std::pair<int, int>>::iterator it2 = s2.begin();
  EXPECT_EQ(it1->first, it2->first);
}

TEST(set_test, empty1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, empty2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, size1) {
  s21::set<int> s1;
  std::set<int> s2;
  s1.insert(1);
  s2.insert(1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size3) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, max_size1) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(set_test, clear1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear2) {
  s21::set<double> s1;
  std::set<double> s2;
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, insert1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(3.0).second, s2.insert(3.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(3.0).first), *(s2.insert(3.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert2) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(9.0).second, s2.insert(9.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(9.0).first), *(s2.insert(9.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(943).second, s2.insert(943).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(943).first), *(s2.insert(943).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase1) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.end();
  EXPECT_THROW(s1.erase(it1), std::invalid_argument);
}

TEST(set_test, erase2) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  it1 = s1.begin();
  it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase3) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.end();
  std::set<double>::iterator it2 = s2.end();
  s1.erase(--it1);
  s2.erase(--it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.begin();
  it2 = s2.begin();
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase4) {
  s21::set<double> s1{4};
  std::set<double> s2{4};
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, erase5) {
  s21::set<double> s1{4};
  s21::set<double>::iterator it1 = s1.begin();
  s1.erase(it1);
  EXPECT_ANY_THROW(*it1);
}

TEST(set_test, swap1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{671, 5894, 720, 8096, 99};
  std::set<int> s22{671, 5894, 720, 8096, 99};
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap3) {
  s21::set<int> s1;
  std::set<int> s2;
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

// не находит merge в библиотеке оригинального set

// TEST(set_test, merge1) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{671, 5894, 720, 80396, 99};
//   std::set<int> s22{671, 5894, 720, 80396, 99};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge2) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge3) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12,
//                     3, 88, 43,   18, 5,  35,  832};
//   std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12,
//                     3, 88, 43,   18, 5,  35,  832};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge4) {
//   s21::set<int> s1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
//   std::set<int> s2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
//   s21::set<int> s11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
//   std::set<int> s22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
//   s1.merge(s11);
//   s2.merge(s22);
//   s21::set<int>::iterator it1 = s1.begin();
//   for (std::set<int>::iterator it2 = s2.begin(); it2 != s2.end(); ++it1,
//   ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge5) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{7, 4, 20, -9, 3, 5, -6};
//   std::set<int> s22{7, 4, 20, -9, 3, 5, -6};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge6) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s1.merge(s1);
//   s2.merge(s2);
//   EXPECT_EQ(s1.size(), s2.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

TEST(set_test, find1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(*(s1.find(3)), *(s2.find(3)));
}

TEST(set_test, contains1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(73), true);
}

TEST(set_test, contains2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(7), false);
}

TEST(set_test, emplace) {
  s21::set<char> s1{'g', 'f'};
  std::set<char> s2{'g', 'f'};
  s1.emplace('7');
  s1.emplace('L');
  s1.emplace(';');
  s1.emplace('5');
  s1.emplace('e');
  s2.emplace('7');
  s2.emplace('L');
  s2.emplace(';');
  s2.emplace('5');
  s2.emplace('e');
  s21::set<char>::iterator it1 = s1.begin();
  std::set<char>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА SET (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MAP (START) ==========
*/

TEST(map_test, constructor1) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 7});
  m2.insert({1, 7});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor4) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor5) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  s21::map<std::string, int> m11;
  std::map<std::string, int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, at1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at2) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_ANY_THROW(m1.at("hm"));
  EXPECT_ANY_THROW(m2.at("hm"));
}

TEST(map_test, at3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_EQ(m1.at("Messi"), m2.at("Messi"));
}

TEST(map_test, operator_ind1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1[100], m2[100]);
  EXPECT_NO_THROW(m1[-2] = 3);
  EXPECT_NO_THROW(m2[-2] = 3);
  EXPECT_NO_THROW(m1.at(-2) = 5);
  EXPECT_NO_THROW(m2.at(-2) = 5);
  EXPECT_EQ(m1.at(-2), m2.at(-2));
}

TEST(map_test, begin1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, end1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, end2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, empty1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, max_size1) {
  s21::map<int, int> s1;
  std::map<int, int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(map_test, clear1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert4) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

// TEST(map_test, insert5) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   EXPECT_EQ(m1.empty(), m2.empty());
//   EXPECT_EQ(m1.insert_or_assign(3, 1).second, m2.insert_or_assign(3,
//   1).second); EXPECT_EQ(m1.at(3), m2.at(3)); EXPECT_EQ(m1.empty(),
//   m2.empty()); EXPECT_EQ(m1.size(), m2.size());
// }

// TEST(map_test, insert6) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   EXPECT_EQ(m1.empty(), m2.empty());
//   EXPECT_EQ(m1.insert_or_assign(2, 1).second, m2.insert_or_assign(2,
//   1).second); EXPECT_EQ(m1.at(2), m2.at(2)); EXPECT_EQ(m1.empty(),
//   m2.empty()); EXPECT_EQ(m1.size(), m2.size());
// }

TEST(map_test, erase1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_ANY_THROW(m1.erase(m1.end()));
}

TEST(map_test, erase2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  std::map<int, int> m22{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap3) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

// TEST(map_test, merge1) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   std::map<int, int> m22{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

// TEST(map_test, merge2) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   std::map<int, int> m22{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

// TEST(map_test, merge3) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
//                          {7, 45},  {56, 0},     {4, 0},       {542, 5}};
//   std::map<int, int> m22{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
//                          {7, 45},  {56, 0},     {4, 0},       {542, 5}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

TEST(map_test, contains1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(44), true);
}

TEST(map_test, contains2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, emplace) {
  s21::map<std::string, int> m1{{"LeBron", 38}, {"Messi", 36}};
  std::map<std::string, int> m2{{"LeBron", 38}, {"Messi", 36}};
  m1.emplace("Bradley Pitt", 59);
  m1.emplace("LeBron", 38);
  m1.emplace("Ryan Gosling", 42);
  m1.emplace("Messi", 36);
  m1.emplace("Ryan Gosling", 42);
  m2.emplace("Bradley Pitt", 59);
  m2.emplace("LeBron", 38);
  m2.emplace("Ryan Gosling", 42);
  m2.emplace("Messi", 36);
  m2.emplace("Ryan Gosling", 42);
  s21::map<std::string, int>::iterator it1 = m1.begin();
  std::map<std::string, int>::iterator it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ((*it1).second, (*it2).second);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MAP (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА QUEUE (START) ==========
*/

template <typename value_type>
bool compare_queues(s21::queue<value_type> my_queue,
                    std::queue<value_type> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CompareQueues_2) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(100);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  s21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  //   s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  //   std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, Pop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, Swap) {
  s21::queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  s21::queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА QUEUE (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА LIST (START) ==========
*/

TEST(ListConstructor, Default) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListConstructor, Sized) {
  s21::list<int> s21_list(3);

  ASSERT_EQ(s21_list.size(), 3);

  for (auto& item : s21_list) ASSERT_EQ(item, 0);
}

TEST(ListConstructor, InitializerList) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();

  ASSERT_EQ(s21_list.size(), list.size());

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Copy) {
  std::list<int> list{1, 2, 3}, copy(list);
  s21::list<int> s21_list{1, 2, 3}, s21_copy(s21_list);
  auto it = copy.cbegin();

  ASSERT_EQ(s21_copy.size(), copy.size());

  for (auto& item : s21_copy) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Move) {
  std::list<int> list{1, 2, 3}, moved(std::move(list));
  s21::list<int> s21_list{1, 2, 3}, s21_moved(std::move(s21_list));
  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, MoveOperator) {
  std::list<int> list{1, 2, 3}, moved;
  s21::list<int> s21_list{1, 2, 3}, s21_moved;

  moved = std::move(list);
  s21_moved = std::move(s21_list);

  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListAccessors, Front) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.front(), list.front());
}

// TEST(ListAccessors, FrontEmptyList) {
//   std::list<int> list;
//   s21::list<int> s21_list;

//   EXPECT_THROW(s21_list.front(), std::logic_error);
// }

TEST(ListAccessors, Back) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.back(), list.back());
}

// TEST(ListAccessors, BackEmptyList) {
//   std::list<int> list;
//   s21::list<int> s21_list;

//   EXPECT_THROW(s21_list.back(), std::logic_error);
// }

TEST(ListIterator, DerefOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, PlusPlusOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  it++;
  s21_it++;

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, ForInLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) EXPECT_EQ(item, *(it++));
}

TEST(ListIterator, ForLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto s21_it = s21_list.begin(); s21_it != s21_list.end(); s21_it++)
    EXPECT_EQ(*s21_it, *(it++));
}

TEST(ListIterator, Mutations) {
  std::list<int> list{2, 4, 6};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) item *= 2;
  for (auto& item : list) ASSERT_EQ(item, *(it++));
}

// TEST(ListConstIterator, DerefOperator) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();
//   auto s21_it = s21_list.cbegin();

//   ASSERT_EQ(*s21_it, *it);
// }

// TEST(ListConstIterator, PlusPlusOperator) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();
//   auto s21_it = s21_list.cbegin();

//   it++;
//   s21_it++;

//   ASSERT_EQ(*s21_it, *it);
// }

// TEST(ListConstIterator, ForLoop) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();

//   for (auto s21_it = s21_list.cbegin(); s21_it != s21_list.cend(); s21_it++)
//     EXPECT_EQ(*s21_it, *(it++));
// }

TEST(ListCapacity, Empty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, NotEmpty) {
  std::list<int> list{1, 2};
  s21::list<int> s21_list{1, 2};

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, SizeEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeOneItem) {
  std::list<int> list{1};
  s21::list<int> s21_list{1};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeFiveItems) {
  std::list<int> list{1, 2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, MaxSize) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.max_size(), list.max_size());
}

TEST(ListModifiers, Clear) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, ClearEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, InsertEmpty) {
  s21::list<int> s21_list;

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);
}

TEST(ListModifiers, InsertAtStart) {
  std::list<int> list{0, 1, 2};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, InsertAtEnd) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();
  auto s21_iter = s21_list.begin();

  s21_iter++;
  s21_iter++;

  auto s21_res = s21_list.insert(s21_iter, 3);

  ASSERT_EQ(s21_list.back(), 3);
  ASSERT_EQ(*s21_res, 3);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

// TEST(ListModifiers, EraseAtStart) {
//   s21::list<int> list{1, 2};
//   list.erase(list.begin());

//   ASSERT_TRUE(list.empty());
// }

// TEST(ListModifiers, EraseAfterFirst) {
//   s21::list<int> list{1, 2, 3, 4};
//   list.erase(++list.begin());

//   ASSERT_EQ(list.size(), 1);
//   ASSERT_EQ(list.front(), 1);
// }

TEST(ListModifiers, PushBackEmpty) {
  s21::list<int> s21_list;

  s21_list.push_back(0);

  ASSERT_EQ(s21_list.back(), 0);
}

TEST(ListModifiers, PushBack) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_back(4);

  ASSERT_EQ(s21_list.back(), 4);
}

TEST(ListModifiers, PopBackEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_back();

  ASSERT_TRUE(s21_list.empty());
}

// TEST(ListModifiers, PopBackOneElement) {
//   s21::list<int> s21_list{1};

//   s21_list.pop_back();

//   ASSERT_TRUE(s21_list.empty());
// }

// TEST(ListModifiers, PopBackFiveElements) {
//   std::list<int> list{1, 2, 3, 4};
//   s21::list<int> s21_list{1, 2, 3, 4, 5};
//   auto it = list.begin();

//   s21_list.pop_back();

//   ASSERT_EQ(s21_list.size(), 4);

//   for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
// }

TEST(ListModifiers, PushFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PushFront) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PopFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontOneElement) {
  s21::list<int> s21_list{1};

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontFiveElements) {
  std::list<int> list{2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  auto it = list.begin();

  s21_list.pop_front();

  ASSERT_EQ(s21_list.size(), 4);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, SwapEmpty) {
  std::list<int> list{4, 5, 6, 7};
  s21::list<int> s21_list, s21_swap{4, 5, 6, 7};
  auto it = list.begin();

  s21_list.swap(s21_swap);

  ASSERT_TRUE(s21_swap.empty());
  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Swap) {
  std::list<int> list{1, 2, 3}, swap{4, 5, 6, 7};
  s21::list<int> s21_list{1, 2, 3}, s21_swap{4, 5, 6, 7};

  list.swap(swap);
  s21_list.swap(s21_swap);

  auto it = list.begin();
  auto swap_it = swap.begin();

  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));

  ASSERT_EQ(s21_swap.size(), swap.size());
  for (auto& item : s21_swap) ASSERT_EQ(item, *(swap_it++));
}

TEST(ListModifiers, Merge) {
  s21::list<int> list{2, 5}, merge{3, 1, 4};
  s21::list<int> s21_list{2, 5}, s21_merge{3, 1, 4};

  list.merge(merge);
  s21_list.merge(s21_merge);

  auto it = list.begin();
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

// TEST(ListModifiers, Splice) {
//   s21::list<int> s21_list{1, 2, 3}, s21_splice{-1, 0}, s21_res{-1, 0, 1, 2,
//   3}; auto it = s21_res.begin();

//   s21_list.splice(s21_list.cbegin(), s21_splice);

//   ASSERT_EQ(s21_list.size(), 5);
//   for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
// }

TEST(ListModifiers, Reverse) {
  s21::list<int> s21_list{1, 2, 3}, s21_res{3, 2, 1};
  auto it = s21_res.begin();

  s21_list.reverse();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Unique) {
  s21::list<int> s21_list{1, 1, 2, 3, 3}, s21_res{1, 2, 3};
  auto it = s21_res.begin();

  s21_list.unique();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Sort) {
  s21::list<int> s21_list{2, 1, 5, 4, 3}, s21_sorted{1, 2, 3, 4, 5};
  auto it = s21_sorted.begin();

  s21_list.sort();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА LIST (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА STACK (START) ==========
*/

TEST(StackTest, Constructor_default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), 3);
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};

  EXPECT_THROW(s21_stack.top(), std::logic_error);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

// TEST(StackTest, Pop_2) {
//   std::initializer_list<int> il1;

//   s21::stack<int> s21_stack{il1};
//   std::stack<int> std_stack{il1};
//   s21_stack.pop();
//   std_stack.pop();
//   EXPECT_EQ(s21_stack.size(), 0);
// }

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА STACK (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА ARRAY (START) ==========
*/

TEST(ArrayTest, constructor_default) {
  s21::array<int, 0> arrays210;
  std::array<int, 0> arraystd0;
  s21::array<char, 0> arrays211;
  std::array<char, 0> arraystd1;
  s21::array<std::string, 0> arrays212;
  std::array<std::string, 0> arraystd2;
  s21::array<double, 0> arrays213;
  std::array<double, 0> arraystd3;
  EXPECT_EQ(arraystd0.size(), arrays210.size());
  EXPECT_EQ(arraystd1.size(), arrays211.size());
  EXPECT_EQ(arraystd2.size(), arrays212.size());
  EXPECT_EQ(arraystd3.size(), arrays213.size());
}

TEST(ArrayTest, constructor_initializer_list) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arraystd.at(0), arrays21.at(0));
  EXPECT_EQ(arraystd.at(1), arrays21.at(1));
  EXPECT_EQ(arraystd.at(2), arrays21.at(2));
  EXPECT_EQ(arraystd.at(3), arrays21.at(3));
  EXPECT_EQ(arraystd.at(4), arrays21.at(4));
}

TEST(ArrayTest, constructor_copy) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  s21::array<int, 5> carrays21(arrays21);
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  std::array<int, 5> carraystd(arraystd);
  EXPECT_EQ(carrays21.at(0), carraystd.at(0));
  EXPECT_EQ(carrays21.at(1), carraystd.at(1));
  EXPECT_EQ(carrays21.at(2), carraystd.at(2));
  EXPECT_EQ(carrays21.at(3), carraystd.at(3));
  EXPECT_EQ(carrays21.at(4), carraystd.at(4));
}

TEST(ArrayTest, constructor_move) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  s21::array<int, 5> marrays21(std::move(arrays21));
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  std::array<int, 5> marraystd(std::move(arraystd));
  EXPECT_EQ(marrays21.at(0), marraystd.at(0));
  EXPECT_EQ(marrays21.at(1), marraystd.at(1));
  EXPECT_EQ(marrays21.at(2), marraystd.at(2));
  EXPECT_EQ(marrays21.at(3), marraystd.at(3));
  EXPECT_EQ(marrays21.at(4), marraystd.at(4));
}

TEST(ArrayTest, constructor_operator) {
  s21::array<int, 5> arrays21 = {1, 2, 3, 4, 5};
  s21::array<int, 5> marrays21;
  marrays21 = std::move(arrays21);
  EXPECT_EQ(marrays21.at(0), 1);
  EXPECT_EQ(marrays21.at(1), 2);
  EXPECT_EQ(marrays21.at(2), 3);
  EXPECT_EQ(marrays21.at(3), 4);
  EXPECT_EQ(marrays21.at(4), 5);
}

TEST(ArrayTest, at_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(0), arraystd.at(0));
  EXPECT_EQ(arrays21.at(1), arraystd.at(1));
  EXPECT_EQ(arrays21.at(2), arraystd.at(2));
  EXPECT_EQ(arrays21.at(3), arraystd.at(3));
  EXPECT_EQ(arrays21.at(4), arraystd.at(4));
}

TEST(ArrayTest, at_throw) {
  s21::array<int, 0> arrays21;
  std::array<int, 0> arraystd;
  EXPECT_ANY_THROW(arrays21.at(1));
  EXPECT_ANY_THROW(arraystd.at(1));
}

TEST(ArrayTest, square_brackets_operator) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21[0], arraystd[0]);
  EXPECT_EQ(arrays21[1], arraystd[1]);
  EXPECT_EQ(arrays21[2], arraystd[2]);
  EXPECT_EQ(arrays21[3], arraystd[3]);
  EXPECT_EQ(arrays21[4], arraystd[4]);
}

TEST(ArrayTest, front_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.front(), arraystd.front());
}

TEST(ArrayTest, back_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.back(), arraystd.back());
}

TEST(ArrayTest, data_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(*arrays21.data(), *arraystd.data());
}

TEST(ArrayTest, empty_function) {
  s21::array<int, 0> arrays21;
  std::array<int, 0> arraystd;
  EXPECT_EQ(arrays21.empty(), arraystd.empty());
}

TEST(ArrayTest, size_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.size(), arraystd.size());
}

TEST(ArrayTest, max_size_function) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.max_size(), arraystd.max_size());
}

TEST(ArrayTest, iterator_0) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  s21::array<int, 5>::iterator i = arrays21.begin();
  std::array<int, 5>::iterator j = arraystd.begin();
  EXPECT_EQ(arrays21.at(0), *i);
  EXPECT_EQ(arraystd.at(0), *j);
}

TEST(ArrayTest, iterator_1) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  s21::array<int, 5>::iterator i = arrays21.begin();
  std::array<int, 5>::iterator j = arraystd.begin();
  i++;
  j++;
  EXPECT_EQ(arrays21.at(1), *i);
  EXPECT_EQ(arraystd.at(1), *j);
}

TEST(ArrayTest, iterator_operator_minus_minus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(2)--, arraystd.at(2)--);
}
TEST(ArrayTest, iterator_operator_plus_plus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(1)++, arraystd.at(1)++);
}
TEST(ArrayTest, iterator_operator_plus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(0) + arrays21.at(1), arraystd.at(0) + arraystd.at(1));
}
TEST(ArrayTest, iterator_operator_minus) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(2) - arrays21.at(1), arraystd.at(2) - arraystd.at(1));
}
TEST(ArrayTest, iterator_operator_eq) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(4) == arraystd.at(4), 1);
}
TEST(ArrayTest, iterator_operator_not_eq) {
  s21::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(3) != arraystd.at(4), 1);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА ARRAY (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MULTISET (START) ==========
*/

TEST(multiset_test, constructor1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor2) {
  s21::multiset<int> m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::multiset<int> m2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor4) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11 = m1;
  std::multiset<int> m22 = m2;
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor5) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int> m11 = m1;
  std::multiset<int> m22 = m2;
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor6) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11 = std::move(m1);
  std::multiset<int> m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, constructor7) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  s21::multiset<int> m11 = std::move(m1);
  std::multiset<int> m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, move_operation1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11;
  std::multiset<int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  s21::multiset<int>::iterator it1 = m11.begin();
  for (std::multiset<int>::iterator it2 = m22.begin(); it2 != m22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m11.size(), m22.size());
  it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, begin1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, end1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.end();
  std::multiset<int>::iterator it2 = m2.end();
  --it1;
  --it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, empty1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, empty2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, empty3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, size1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, size2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, size3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, max_size1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.max_size(), m2.max_size());
}

TEST(multiset_test, clear1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, clear2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(multiset_test, insert1) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  for (int i = 0; i < 1000; i++) {
    int num = rand();
    EXPECT_EQ(*(m1.insert(num)), *(m2.insert(num)));
  }
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, insert2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(*(m1.insert(1)), *(m2.insert(1)));
  }
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, insert3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  for (int i = 0; i < 100; i++) {
    int num = rand();
    m1.insert(num);
    m2.insert(num);
  }
  s21::multiset<int>::iterator it1 = m1.begin();
  for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, erase1) {
  s21::multiset<int> m1;
  EXPECT_ANY_THROW(m1.erase(m1.begin()));
}

TEST(multiset_test, erase2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.size(), m2.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  m1.erase(it1);
  m2.erase(it2);
  it1 = m1.begin();
  it2 = m2.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(multiset_test, erase3) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_ANY_THROW(m1.erase(m1.end()));
}

TEST(multiset_test, swap1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11;
  std::multiset<int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  s21::multiset<int>::iterator it11 = m11.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  std::multiset<int>::iterator it22 = m22.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  for (; it22 != m22.end(); ++it11, ++it22) EXPECT_EQ(*it11, *it22);
}

TEST(multiset_test, swap2) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int> m11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  std::multiset<int> m22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  s21::multiset<int>::iterator it1 = m1.begin();
  s21::multiset<int>::iterator it11 = m11.begin();
  std::multiset<int>::iterator it2 = m2.begin();
  std::multiset<int>::iterator it22 = m22.begin();
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  for (; it22 != m22.end(); ++it11, ++it22) EXPECT_EQ(*it11, *it22);
}

// TEST(multiset_test, merge1) {
// s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2,
// 127}; std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0,
// 2, 127}; s21::multiset<int> m11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3,
// 321}; std::multiset<int> m22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
// m1.merge(m11);
// m2.merge(m22);
// s21::multiset<int>::iterator it1 = m1.begin();
// for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
// ++it1, ++it2)
// EXPECT_EQ(*it1, *it2);
// }

// TEST(multiset_test, merge2) {
// s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2,
// 127}; std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0,
// 2, 127}; s21::multiset<int> m11; std::multiset<int> m22; m1.merge(m11);
// m2.merge(m22);
// s21::multiset<int>::iterator it1 = m1.begin();
// for (std::multiset<int>::iterator it2 = m2.begin(); it2 != m2.end();
// ++it1, ++it2)
// EXPECT_EQ(*it1, *it2);
// }

TEST(multiset_test, count1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, count2) {
  s21::multiset<int> m1;
  std::multiset<int> m2;
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, count3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(m1.count(1), m2.count(1));
  EXPECT_EQ(m1.count(2), m2.count(2));
  EXPECT_EQ(m1.count(6), m2.count(6));
}

TEST(multiset_test, find1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(*(m1.find(127)), *(m2.find(127)));
  EXPECT_EQ(*(m1.find(2)), *(m2.find(2)));
  EXPECT_EQ(*(m1.find(4)), *(m2.find(4)));
}

TEST(multiset_test, find3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(*(m1.find(1)), *(m2.find(1)));
}

TEST(multiset_test, contains1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  EXPECT_EQ(m1.contains(127), true);
  EXPECT_EQ(m1.contains(2), true);
  EXPECT_EQ(m1.contains(4), true);
}

TEST(multiset_test, contains2) {
  s21::multiset<int> m1;
  EXPECT_EQ(m1.contains(127), false);
  EXPECT_EQ(m1.contains(2), false);
  EXPECT_EQ(m1.contains(4), false);
}

TEST(multiset_test, contains3) {
  s21::multiset<int> m1 = {1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> m2 = {1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(m1.contains(1), true);
  EXPECT_EQ(m1.contains(2), false);
  EXPECT_EQ(m1.contains(4), false);
}

TEST(multiset_test, equal_range1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> pair1 =
      m1.equal_range(9);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> pair2 =
      m2.equal_range(9);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = m1.equal_range(1);
  pair2 = m2.equal_range(1);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
  pair1 = m1.equal_range(2);
  pair2 = m2.equal_range(2);
  EXPECT_EQ(*(pair1.first), *(pair2.first));
  EXPECT_EQ(*(pair1.second), *(pair2.second));
}

TEST(multiset_test, lower_bound1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.lower_bound(9);
  std::multiset<int>::iterator it2 = m2.lower_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.lower_bound(1);
  it2 = m2.lower_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.lower_bound(2);
  it2 = m2.lower_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, upper_bound1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.upper_bound(9);
  std::multiset<int>::iterator it2 = m2.upper_bound(9);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.upper_bound(1);
  it2 = m2.upper_bound(1);
  EXPECT_EQ(*(it1), *(it2));
  it1 = m1.upper_bound(2);
  it2 = m2.upper_bound(2);
  EXPECT_EQ(*(it1), *(it2));
}

TEST(multiset_test, iterator1) {
  s21::multiset<int> m1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  std::multiset<int> m2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
  s21::multiset<int>::iterator it1 = m1.end();
  std::multiset<int>::iterator it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ(*(it1), *(it2));
  for (; it2 != m2.begin(); --it1, --it2) EXPECT_EQ(*it1, *it2);
}

TEST(multiset_test, emplace) {
  s21::multiset<char> m1{'g', 'f', 'e', 'g'};
  std::multiset<char> m2{'g', 'f', 'e', 'g'};
  m1.emplace('7');
  m1.emplace('e');
  m1.emplace('L');
  m1.emplace(';');
  m1.emplace('g');
  m1.emplace('5');
  m1.emplace('e');
  m2.emplace('7');
  m2.emplace('e');
  m2.emplace('L');
  m2.emplace(';');
  m2.emplace('g');
  m2.emplace('5');
  m2.emplace('e');
  s21::multiset<char>::iterator it1 = m1.begin();
  std::multiset<char>::iterator it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MULTISET (END) ==========
*/

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
