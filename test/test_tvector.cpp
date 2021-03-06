#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(3);
	v[0] = 1;
	TVector<int> v1(v);
	EXPECT_EQ(v, v1);
  //ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(5);
	v[0] = 1;
	TVector<int> v1(v);
	v[1] = 2;
	EXPECT_NE(v[1], v1[1]);
  //ADD_FAILURE();
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v;
	ASSERT_ANY_THROW(v[-2]);
  //ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4, 2);
	ASSERT_ANY_THROW(v[5]);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself) //=
{
	TVector<int> v(2);
	v[0] = 5;
	v[1] = 1;
	v = v;
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(1, v[1]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(5);
	v[2] = 5;
	v[1] = 1;
	TVector<int> v1 = v;
	EXPECT_EQ(v, v1);
}

//TEST(TVector, can_assign_vector_to_itself)
//{
//TVector<int> v1(3, 1);
//v1 = v1;
//EXPECT_EQ(1, v1==v2);
//  ADD_FAILURE();
//}

//TEST(TVector, can_assign_vectors_of_equal_size)
//{
//const int size = 2;
//TVector<int> v1(size, 1), v2(size, 1);
//v2 = v1;
//EXPECT_EQ(1, v1==v2);
////  ADD_FAILURE();
//}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5);
	v = TVector<int>(6);
	EXPECT_EQ(6, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5), v1(7);
	v1 = v;

	EXPECT_EQ(v, v1);
}


TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1, v2;
	v2 = v1;
	EXPECT_EQ(v1, v2);
  //ADD_FAILURE();
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v;
	EXPECT_EQ(v, v);
  //ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(5, 1), v2(2, 1);
	EXPECT_NE(v1, v2);
  //ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3), v1(3), v2(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v1 = v + 1;

	v2[0] = 2;
	v2[1] = 3;
	v2[2] = 4;

	EXPECT_EQ(v2, v1);
  //ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3), v1(3), v2(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v1 = v - 1;

	v2[0] = 0;
	v2[1] = 1;
	v2[2] = 2;

	EXPECT_EQ(v2, v1);
  //ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3), v1(3), v2(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v1 = v * 2;

	v2[0] = 2;
	v2[1] = 4;
	v2[2] = 6;

	EXPECT_EQ(v2, v1);
  //ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3), v1(3), res(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v1[0] = 4;
	v1[1] = 5;
	v1[2] = 6;

	res[0] = 5;
	res[1] = 7;
	res[2] = 9;

	EXPECT_EQ(res, v + v1);
  //ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(2), v1(3);
	ASSERT_ANY_THROW(v + v1);
  //ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3), v1(3), res(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v1[0] = 4;
	v1[1] = 5;
	v1[2] = 6;

	res[0] = 3;
	res[1] = 3;
	res[2] = 3;

	EXPECT_EQ(res, v1 - v);
  //ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(2), v1(3);
	ASSERT_ANY_THROW(v - v1);
  //ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(2), v1(2);
	v[0] = 1;
	v[1] = 2;

	v1[0] = 3;
	v1[1] = 4;

	EXPECT_EQ(11, v1 * v);
  //ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(2), v1(3);
	ASSERT_ANY_THROW(v * v1);
  //ADD_FAILURE();
}
