#include "sort.h"
/**
 * selection_sort - sorts an array of integers with selection sort
 * @array: an array of integers
 * @size: the array size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t traverser, picker, min_idx;
	int tmp;

	if (!array || size < 2)
		return;
	for (traverser = 0; traverser < size - 1; traverser++)
	{
		min_idx = traverser;
		for (picker = traverser + 1; picker < size; picker++)
			if (array[picker] < array[min_idx])
				min_idx = picker;
		if (traverser != min_idx)
		{
			tmp = array[min_idx];
			array[min_idx] = array[traverser];
			array[traverser] = tmp;
			print_array(array, size);
		}
	}
}
