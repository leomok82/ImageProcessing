/**
 * @file Utils.h
 * @brief This file contains utility functions for sorting and manipulating vectors and strings.
 *
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <stdexcept>
#include <algorithm>

/**
 * @brief Swaps the values of two variables.
 * 
 * @tparam T The type of the variables.
 * @param a The first variable.
 * @param b The second variable.
 */
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Partitions the vector around a pivot element.
 * 
 * @tparam T The type of the elements in the vector.
 * @param arr The vector to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
template <typename T>
int partition(std::vector<T> &arr, int low, int high)
{
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Finds the k-th smallest element in the vector using the QuickSelect algorithm.
 * 
 * @tparam T The type of the elements in the vector.
 * @param arr The vector to be searched.
 * @param low The starting index of the search range.
 * @param high The ending index of the search range.
 * @param k The position of the element to be found.
 * @return The k-th smallest element in the vector.
 * @throws std::runtime_error if the index is out of bounds.
 */
template <typename T>
T quickSelect(std::vector<T> &arr, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int index = partition(arr, low, high);

        if (index - low == k - 1)
            return arr[index];

        if (index - low > k - 1)
            return quickSelect(arr, low, index - 1, k);

        return quickSelect(arr, index + 1, high, k - index + low - 1);
    }

    throw std::runtime_error("Index out of bounds");
}

/**
 * @brief Extracts the numeric part from a filename.
 * 
 * @param filename The filename from which to extract the numeric part.
 * @return The numeric part of the filename as a long long integer.
 */
inline long long extractNumericPart(const std::string& filename) {
    std::string numberStr;
    for (char c : filename) {
        if (std::isdigit(c)) {
            numberStr += c;
        }
    }
    return !numberStr.empty() ? std::stoll(numberStr) : 0;
}

/**
 * @brief Partitions the vector of filenames based on their numeric parts.
 * 
 * @param arr The vector of filenames to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
inline int partitionFilenames(std::vector<std::string> &arr, int low, int high) {
    long long pivot = extractNumericPart(arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (extractNumericPart(arr[j]) < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Sorts the vector of filenames using the QuickSort algorithm.
 * 
 * @param arr The vector of filenames to be sorted.
 * @param low The starting index of the sort range.
 * @param high The ending index of the sort range.
 */
inline void quickSortFilenames(std::vector<std::string> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionFilenames(arr, low, high);

        quickSortFilenames(arr, low, pi - 1);
        quickSortFilenames(arr, pi + 1, high);
    }
}

#endif // UTILS_H
