#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stddef.h"


typedef struct {
    int *data;
    size_t nalloc;
    size_t size;
} heap_t;

void init (heap_t *heap, size_t n) {
  heap->data = malloc(sizeof(int) * n);
  heap->size = n;
  heap->nalloc = 0;
}

int get_max (heap_t *heap) {
  return heap->data[0];
}

size_t get_length (heap_t *heap) {
  return heap->nalloc;
}

void resize (heap_t *heap, size_t n) {
  int *new = malloc(sizeof(int) * n);  

  memcpy(new, heap->data, heap->size);
  free(heap->data);
  heap->data = new;
  heap->size = n;
}

void swap (heap_t *heap, size_t i, size_t j) {
    int tmp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = tmp;
}

void insert (heap_t *heap, int item) {
  if (heap->nalloc == heap->size) {
    resize(heap, heap->size * 2);
  }

  heap->data[heap->nalloc++] = item;

  size_t k = heap->nalloc - 1;
  while (k > 0 && heap->data[k] > heap->data[(k - 1) / 2]) {
      swap(heap, k, (k - 1) / 2);
      k = (k - 1) / 2;
  }
}

void heapify (heap_t *heap, size_t index, size_t length) {
    if (index >= length) return;

    size_t left = index * 2 + 1;
    size_t right = index * 2 + 2;

    size_t max = index;
    if (left < length && heap->data[left] > heap->data[max]) {
      max = index * 2 + 1;
    } 
    if (right < length && heap->data[right] > heap->data[max]) {
      max = index * 2 + 2;
    }

    if (max != index) {
      swap(heap, index, max);
      heapify(heap, max, length);
    }
}

heap_t * heap_sort (heap_t *heap) {
  heap_t *new_heap = malloc(sizeof(heap_t));
  init(new_heap, heap->nalloc);
  memcpy(new_heap->data, heap->data, sizeof(int) * heap->nalloc);
  new_heap->nalloc = heap->nalloc;

  for (size_t i = new_heap->nalloc - 1; i > 0; i--) {
    swap(new_heap, 0, i);
    heapify(new_heap, 0, i);
  }
  return new_heap;
}

void display (heap_t *heap) {
    for (size_t i = 0; i < heap->nalloc; i++) {
      printf("%d\n", heap->data[i]);
    }
}

int main () {
    heap_t heap; 
    init(&heap, 30);

    insert(&heap, 5);
    insert(&heap, 9);
    insert(&heap, 1);
    insert(&heap, 19);
    insert(&heap, 3);
    insert(&heap, 7);
    insert(&heap, 2);
    insert(&heap, 100);
    insert(&heap, 50);

    display(&heap);

    printf("-------------------------------------\n");

    heap_t * sorted = heap_sort(&heap);
    display(sorted);
}
