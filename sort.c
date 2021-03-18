#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void _swap (int *arr, size_t i, size_t j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void _print (int *arr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubble_sort (int *arr, size_t size) {
  int *new = malloc(sizeof(int) * size);
  memcpy(new, arr, sizeof(int) * size);

  for (size_t i = size - 1; i > 0; i--) {
    for (size_t j = 0; j < i; j++) {
      if (new[j] > new[j + 1]) {
        _swap(new, j, j + 1);
      }
    }
  }

  _print(new, size);

  free(new);
}

void insertion_sort (int *arr, size_t size) {
  int *new = malloc(sizeof(int) * size);
  memcpy(new, arr, sizeof(int) * size);

  for (size_t i = 1; i < size; i++) {
    for (size_t j = i; j >= 0; j--) {
      if (new[j] < new[j - 1]) {
        _swap(new, j, j - 1);
      } else {
        break;
      }
    }
  }

  _print(new, size);

  free(new);
}

void selection_sort (int *arr, size_t size) {
  int *new = malloc(sizeof(int) * size);
  memcpy(new, arr, sizeof(int) * size);

  for (size_t pivot = 0; pivot < size - 1; pivot++) {
    int minIdx = pivot;
    for (size_t i = pivot + 1; i < size; i++) {
      if (new[i] < new[minIdx]) {
        minIdx = i;
      }
    }

    _swap(new, pivot, minIdx);
  }

  _print(new, size);

  free(new);
}

void _merge (int *arr, size_t left, size_t right) {
  // do nothing
  if (left == right) return;

  size_t mid = (left + right) / 2;
  _merge(arr, left, mid);
  _merge(arr, mid + 1, right);

  int *tmpArr = calloc(right - left + 1, sizeof(int));

  size_t cur = 0;
  size_t lIdx = left;
  size_t rIdx = mid + 1;

  while (lIdx <= mid && rIdx <= right) {
    if (arr[lIdx] < arr[rIdx]) {
      tmpArr[cur++] = arr[lIdx++];
    } else if (arr[lIdx] > arr[rIdx]) {
      tmpArr[cur++] = arr[rIdx++];
    }
  }

  while (lIdx <= mid) {
    tmpArr[cur++] = arr[lIdx++];
  }

  while (rIdx <= right) {
    tmpArr[cur++] = arr[rIdx++];
  }

  _print(tmpArr, right - left + 1);
  memcpy(arr + left, tmpArr, sizeof(int) * (right - left + 1));
  free(tmpArr);
}

void merge_sort (int *arr, size_t size) {
  int *new = malloc(sizeof(int) * size);
  memcpy(new, arr, sizeof(int) * size);

  _merge(new, 0, size - 1);

  _print(new, size);

  free(new);
}

void _qsort (int *arr, size_t left, size_t right) {
  if (left >= right) return;

  // pick right as pivot
  size_t lbound = left - 1;
  for (size_t i = left; i < right; i++) {
    if (arr[i] < arr[right]) {
      _swap(arr, ++lbound, i);
    }
  }
  _swap(arr, lbound + 1, right);

  // divide
  _qsort(arr, left, lbound);
  _qsort(arr, lbound + 2, right);
}

void quick_sort (int *arr, size_t size) {
  int *new = malloc(sizeof(int) * size);
  memcpy(new, arr, sizeof(int) * size);

  _qsort(new, 0, size - 1);

  _print(new, size);

  free(new);
}

int main () {
  int arr[] = { 0, 3, 5, 1, 7, 4, 9, 13, 8 };

  insertion_sort(arr, 9);
  merge_sort(arr, 9);
  quick_sort(arr, 9);
  bubble_sort(arr, 9);
}
