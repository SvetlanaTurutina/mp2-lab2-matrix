#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(3);
	m[0][0] = 1;
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
  //ADD_FAILURE();
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	m[0][0] = 1;
	TMatrix<int> m1(m);
	m[0][0] = 2;
	EXPECT_NE(m[0][0], m1[0][0]);
  //ADD_FAILURE();
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);

	EXPECT_EQ(4, m.GetSize());
  //ADD_FAILURE();
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	m[0][1] = 4;

	EXPECT_EQ(4, m[0][1]);
  //ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-2][1]);
  //ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[5][1]);
  //ADD_FAILURE();
}


TEST(TMatrix, can_assign_matrix_to_itself)//=
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	m = m;
	EXPECT_EQ(1, m[0][0]);
	EXPECT_EQ(2, m[0][1]);
	EXPECT_EQ(3, m[1][1]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), m1(5);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	m1 = m;
	EXPECT_EQ(m, m1);
  //ADD_FAILURE();
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	m = TMatrix<int>(6);
	EXPECT_EQ(6, m.GetSize());
  //ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), m1(7);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	m1 = m;

	EXPECT_EQ(m, m1);
  //ADD_FAILURE();
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(2), m2(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][1] = 3;
	m2 = m1;
	EXPECT_TRUE(m1 == m2);
  //ADD_FAILURE();
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;
	EXPECT_TRUE(m == m);
  //ADD_FAILURE();
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5), m2(2);
	EXPECT_FALSE(m1 == m2);
  //ADD_FAILURE();
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2), m1(2), res(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;

	m1[0][0] = 3;
	m1[0][1] = 4;
	m1[1][1] = 5;

	res[0][0] = 4;
	res[0][1] = 6;
	res[1][1] = 8;

	EXPECT_EQ(res, m + m1);
  //ADD_FAILURE();
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(2), m1(3);
	ASSERT_ANY_THROW(m + m1);
  //ADD_FAILURE();
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(2), m1(2), res(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;

	m1[0][0] = 3;
	m1[0][1] = 4;
	m1[1][1] = 5;

	res[0][0] = 2;
	res[0][1] = 2;
	res[1][1] = 2;

	EXPECT_EQ(res, m1 - m);
  //ADD_FAILURE();
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(2), m1(3);
	ASSERT_ANY_THROW(m - m1);
  //ADD_FAILURE();
}

TEST(TMatrix, can_multiply_matrices_with_equal_size)
{
	TMatrix<int> m(2), m1(2), res(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][1] = 3;

	m1[0][0] = 3;
	m1[0][1] = 4;
	m1[1][1] = 5;

	res[0][0] = 3;
	res[0][1] = 14;
	res[1][1] = 15;

	EXPECT_EQ(res, m * m1);
	//ADD_FAILURE();
}

TEST(TMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TMatrix<int> m(2), m1(3);
	ASSERT_ANY_THROW(m * m1);
	//ADD_FAILURE();
}


