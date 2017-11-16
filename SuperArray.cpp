// File: SuperArray
// Created by Javier Zarate on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include "SuperArray.h"
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	arr = new int[capacity];
    SuperArray::capacity = capacity;
    lowIndex = begIndex;
    highIndex = begIndex + capacity - 1;
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}

/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
	stringstream ss;

	for (int i = 0; i < obj.capacity; i++)
    {
        ss << obj.arr[i] << " ";
    }
	string str = ss.str();
	size_t found;
	found = str.find_last_not_of(" ");
	if (found != string::npos)
		str.erase(found + 1);
	else
		str.clear();            // str is all whitespace

	return str;
}

/*!
 * Index operator overload
 * @param index User's index notation
 * @return Actual index notation
 */
int &SuperArray::operator[](const int index)
{
	int realIndex = index - lowIndex;
    if (realIndex < 0)
    {
        throw "Invalid index request, too low";
    }

    if (realIndex >= capacity)
    {
        throw "Invalid index request, too high";
    }

    return arr[realIndex];
}

/*!
 * Gets the first number in the array
 * @return: the low index
 */
int SuperArray::getLowIndex() const
{
    return lowIndex;
}

/*!
 * Gets the last number of the array
 * @return: the high index
 */
int SuperArray::getHighIndex() const
{
    return highIndex;
}

/*!
 * Gets the length of the array
 * @return: the capacity
 */
unsigned int SuperArray::length() const
{
    return capacity;
}

/*!
 * Allocate new memory, and delete old memory
 * @param begIndex: The user's beginning length
 * @param capacity: The maximum array capacity
 */
void SuperArray::resize(const int begIndex, const unsigned int capacity)
{
    int *tempArr  = new int[capacity];
    int newPos = lowIndex - begIndex;
    for (int i =0; i<SuperArray::capacity; i++)
    {
        tempArr[newPos+i]= arr[i];
    }

    delete[] arr;

    arr = tempArr;
    SuperArray::capacity = capacity;
    lowIndex = begIndex;
    highIndex = capacity - 1;
}
