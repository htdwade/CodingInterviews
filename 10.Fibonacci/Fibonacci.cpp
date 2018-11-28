/*

剑指Offer
面试题10：斐波那契数列
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

*/

#include <iostream>

using namespace std;

// 迭代，保存中间项，避免重复计算
int Fibonacci(int n) {
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	int fib1 = 0;
	int fib2 = 1;
	int fibn = 0;
	for (int i = 2; i <= n; i++) {
		fibn = fib1 + fib2;
		fib1 = fib2;
		fib2 = fibn;
	}
	return fibn;
}

// 基于矩阵乘法
struct Matrix2By2
{
	int m_00;
	int m_01;
	int m_10;
	int m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1, const Matrix2By2& matrix2)
{
	Matrix2By2 res;
	res.m_00 = matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10;
	res.m_01 = matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11;
	res.m_10 = matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10;
	res.m_11 = matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11;
	return res;
}

Matrix2By2 MatrixPower(int n)
{
	Matrix2By2 matrix;
	Matrix2By2 res;
	matrix.m_00 = 1;
	matrix.m_01 = 1;
	matrix.m_10 = 1;
	matrix.m_11 = 0;
	if (n == 1)
		return matrix;
	else if (n % 2 == 0)
	{
		Matrix2By2 temp = MatrixPower(n / 2);
		res = MatrixMultiply(temp, temp);
	}
	else if (n % 2 == 1)
	{
		Matrix2By2 temp = MatrixPower((n - 1) / 2);
		res = MatrixMultiply(temp, temp);
		res = MatrixMultiply(res, matrix);
	}
	return res;
}

int Fibonacci2(int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	Matrix2By2 res = MatrixPower(n - 1);
	return res.m_00;
}

int main()
{
	cout << Fibonacci(2) << endl;
	cout << Fibonacci2(2) << endl;
	cout << Fibonacci(8) << endl;
	cout << Fibonacci2(8) << endl;
	return 0;
}