#include "DynamicArray.h"

/* This function creates a Dynamic Array with the given capacity
 * Input: int capacity - the given capacity
 * Output: the new DynamicArray*
*/
DynamicArray* dynamicArrayConstructor(int capacity){
    DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof (DynamicArray));
    dynamicArray->size = 0;
    dynamicArray->capacity = capacity;
    dynamicArray->elements = (TElem*)malloc(sizeof (TElem)* capacity);
}

/* This function resizes the DynamicArray by doubling it's capacity
 * Input: a pointer to the DynamicArray
 * Output: -
 */
void resize(DynamicArray* dynamicArray){
    dynamicArray->capacity *= 2;
    TElem *newElements = (TElem*)malloc(sizeof (TElem)* dynamicArray->capacity);
    for (int index = 0; index < dynamicArray->size; index++)
        newElements[index] = dynamicArray->elements[index];
    free(dynamicArray->elements);
    dynamicArray->elements = newElements;
}

/* This function adds an element in the dynamicArray
 * Input: dynamicArray - the dynamicArray in which we add the element
 *        element - a generic TElem which will be added
 * Output: -
 */
void addElement(DynamicArray* dynamicArray, TElem element){
    if (dynamicArray->size == dynamicArray->capacity)
        resize(dynamicArray);
    dynamicArray->elements[dynamicArray->size++] = element;
}

/* This function updates an element in the dynamicArray at a given index
 * Input: dynamicArray - the dynamicArray in which we update the element
 *        element - a generic TElem which the one from index will be updated with
 *        index - the position of the element which will be updated
 * Output: 0 if the position is not a good one
 */
int updateElement(DynamicArray* dynamicArray, int index, TElem element){
    if (index < 0 || index >= dynamicArray->size)
        return 0;
    dynamicArray->elements[index] = element;
}

/* This function deleted an element in the dynamicArray at a given index
 * Input: dynamicArray - the dynamicArray
 *        index - the position of the element which will be deleted
 * Output: 0 if the position is not a good one, 1 if the operation succeed
 */
int deleteElement(DynamicArray* dynamicArray, int index){
    if (index < 0 || index >= dynamicArray->size)
        return 0;
    if (dynamicArray->size > 0){
        dynamicArray->size--;
        for (int index2 = index; index2 < dynamicArray->size; index2++)
            dynamicArray->elements[index2] = dynamicArray->elements[index2 + 1];
    }
    return 1;
}

/* This function gets an element from the dynamicArray at a given index
 * Input: dynamicArray - the dynamicArray
 *        index - the position of the element which will be extracted
 * Output: dynamicArray->elements[index] if the index is valid, NULL otherwise
 */
TElem getElementAtIndex(DynamicArray* dynamicArray, int index){
    if (index < 0 || index >= dynamicArray->size)
        return NULL;
    return dynamicArray->elements[index];
}

/* This function swaps 2 elements in the dynamic array
 * Input: dynamicArray - the dynamicArray
 *        index1, index2 - the positions of the elements which will be swapped
 * Output: -
 */
void swapElements(DynamicArray* dynamicArray, int index1, int index2){
    TElem element;
    element = dynamicArray->elements[index1];
    dynamicArray->elements[index1] = dynamicArray->elements[index2];
    dynamicArray->elements[index2] = element;
}

/* This function destroys a Dynamic Array
 * Input: a pointer to the DynamicArray
 * Output: -
*/
void dynamicArrayDestructor(DynamicArray** dynamicArray){
    free((*dynamicArray)->elements);
    free(*dynamicArray);
}