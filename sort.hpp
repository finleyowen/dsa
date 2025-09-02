#ifndef __SORT_HPP__
#define __SORT_HPP__

template <typename T>
void selsort(T A[], size_t n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = i; j < n; j++)
		{
			if (A[i] > A[j])
			{
				T tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}

#endif