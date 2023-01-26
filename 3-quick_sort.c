#include "sort.h"
/**
 * partition - takes last element as pivot,
 * and according to this organizes to the left those less
 * than the pivot and to the right those greater than the pivot
 * @array: the array to sort
 * @less_p: those less than the selected pivot
 * @greater_p: thos greater than the selected pivot
 * @size: array size
 * Return: each int set to the first place in the sort array
 */
int partition(int *array, int less_p, int greater_p, size_t size)
{
	int pivot = array[greater_p];
	int i = (less_p - 1), j, tmp, tmp2;

	for (j = less_p; j <= greater_p; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[greater_p] < array[i + 1])
	{
		tmp2 = array[i + 1];
		array[i + 1] = array[greater_p];
		array[greater_p] = tmp2;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort - implements quick sort
 * @array: array to be sorted
 * @less_p: begginig of the array (start)
 * @greater_p: the end of the array
 * @size: array size
 * Return: void
 */
void quicksort(int *array, int less_p, int greater_p, size_t size)
{
	int idx_to_part;

	if (less_p < greater_p)
	{
		idx_to_part = partition(array, less_p, greater_p, size);
		quicksort(array, less_p, idx_to_part - 1, size);
		quicksort(array, idx_to_part + 1, greater_p, size);
	}
}
/**
 * quick_sort - sorts an array in ascending order
 * implementin the lomuto partition scheme
 * and setting as pivot always the last element of the partition
 * once is ordered
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
