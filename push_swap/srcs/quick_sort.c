/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:50:49 by jiheo             #+#    #+#             */
/*   Updated: 2022/02/01 12:50:49 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	if (start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left < right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			swap(&arr[pivot], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
