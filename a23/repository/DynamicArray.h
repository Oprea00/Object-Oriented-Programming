#ifndef A23_OPREA00_DYNAMICARRAY_H
#define A23_OPREA00_DYNAMICARRAY_H

#include "stdlib.h"

typedef void* TElem;

typedef struct{
    TElem* elements;
    int size, capacity;
}DynamicArray;

DynamicArray* dynamicArrayConstructor(int capacity);

void resize(DynamicArray* dynamicArray);

void addElement(DynamicArray* dynamicArray, TElem element);

int updateElement(DynamicArray* dynamicArray, int index, TElem element);

int deleteElement(DynamicArray* dynamicArray, int index);

TElem getElementAtIndex(DynamicArray* dynamicArray, int index);

void swapElements(DynamicArray* dynamicArray, int index1, int index2);

void dynamicArrayDestructor(DynamicArray** dynamicArray);

#endif //A23_OPREA00_DYNAMICARRAY_H