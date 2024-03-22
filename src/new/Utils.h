/**
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

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

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

inline long long extractNumericPart(const std::string& filename) {
    std::string numberStr;
    for (char c : filename) {
        if (std::isdigit(c)) {
            numberStr += c;
        }
    }
    return !numberStr.empty() ? std::stoll(numberStr) : 0;
}


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

inline void quickSortFilenames(std::vector<std::string> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionFilenames(arr, low, high);

        quickSortFilenames(arr, low, pi - 1);
        quickSortFilenames(arr, pi + 1, high);
    }
}

#endif // UTILS_H
