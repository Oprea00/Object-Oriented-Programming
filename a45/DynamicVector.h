#pragma once

#include <functional>
#include <utility>


template <typename TemplateElement>
class DynamicVector
{
private:
	TemplateElement* elements;
	int size = 0;
	int capacity;

public:
	// default constructor
	DynamicVector(int capacity = 10);
	// copy constructor
	DynamicVector(const DynamicVector& vector);
	// destructor
	~DynamicVector();
	// assignment operator
	DynamicVector& operator=(const DynamicVector& vector);
	// [] operator to return an element from a given position
	TemplateElement& operator[](int position);
	// add an element
	void add(TemplateElement element);
	// update an element at a given position
	void update(int index, TemplateElement element);
	// remove an element from a given position
	void remove(int index);
	// get the size of the dynamicVector
	int getSize() const;
	// get the capacity of the dynamicVector
	int getCapacity() const;


private:
	//resize the DynamicVector, multiplying its capacity by 2
	void resize(double factor = 2);
};

template <typename TemplateElement>
DynamicVector<TemplateElement>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TemplateElement[capacity];
}

template <typename TemplateElement>
DynamicVector<TemplateElement>::DynamicVector(const DynamicVector<TemplateElement>& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new TemplateElement[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elements[index] = vector.elements[index];
}

template <typename TemplateElement>
DynamicVector<TemplateElement>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename TemplateElement>
DynamicVector<TemplateElement>& DynamicVector<TemplateElement>::operator=(const DynamicVector<TemplateElement>& vector)
{
	if (this == &vector)
		return *this;
	this->size = vector.size;
	this->capacity = vector.capacity;
	TemplateElement* elements = new TemplateElement[this->capacity];
	delete[] this->elements;
	this->elements = elements;
	for (int index = 0; index < this->size; index++)
		this->elements[index] = vector.elements[index];
	return *this;
}

template <typename TemplateElement>
TemplateElement& DynamicVector<TemplateElement>::operator[](int position)
{
	return this->elements[position];
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::resize(double factor)
{
	this->capacity *= (int)factor;
	TemplateElement* newElements = new TemplateElement[this->capacity];
	for (int index = 0; index < this->size; index++)
		newElements[index] = this->elements[index];
	delete[] this->elements;
	this->elements = newElements;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::add(TemplateElement element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::update(int index, TemplateElement element)
{
	if (index > -1 && index < this->size)
		this->elements[index] = element;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::remove(int index)
{
	if (index > -1 && index < this->size)
	{
		this->size--;
		for (int index2 = index; index2 < this->size; index2++)
			this->elements[index2] = this->elements[index2 + 1];
	}
}

template <typename TemplateElement>
int DynamicVector<TemplateElement>::getSize() const
{
	return this->size;
}

template <typename TemplateElement>
int DynamicVector<TemplateElement>::getCapacity() const
{
	return this->capacity;
}