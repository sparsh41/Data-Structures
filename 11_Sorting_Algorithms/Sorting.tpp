#include "Sorting.hpp"
#include <iostream>
#include <vector>

template <typename T>
void Sorting::selectionSort(std::vector<T>& v) {
    int size = v.size();
    
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find the minIndex
        for (int j = i + 1; j < size; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        

        std::swap(v[i], v[minIndex]);
    }
}


template <typename T>
void Sorting::mergeSort(std::vector<T>& v) {
    mergeSort(v, 0, v.size() - 1);
}

template <typename T>
void Sorting::mergeSort(std::vector<T>& v, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}


template <typename T>
void Sorting::merge(std::vector<T>& v, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    std::vector<T> left_vector;
    std::vector<T> right_vector;

    for (int i = 0; i < size1; i++) {
        left_vector.push_back(v[left + i]); 
    }
    for (int i = 0; i < size2; i++) {
        right_vector.push_back(v[mid + 1 + i]); 
    }

    int i = 0, j = 0, k = left;

    // Merge the vectors

    while (i < size1 && j < size2) {
        if (left_vector[i] <= right_vector[j]) {
            v[k] = left_vector[i];
            i++;
        }
        else {
            v[k] = right_vector[j];
            j++;
        }
        k++;
    }

    // If reached end of left vector
    while(i < size1) {
        v[k] = left_vector[i];
        i++;
        k++;
    }

    // If reached end of right vector
    while(j < size2) {
        v[k] = right_vector[j];
        j++;
        k++;
    }
}

template <typename T>
int Sorting::partition(std::vector<T>& v, int left, int right) {
    T pivot = v[right];

    int r = right - 1;

    while (left <= right) {
        // Swap
        if ((v[left] > pivot) && (v[r] < pivot)) {
            std::swap(v[left], v[r]);
        }

        // Move the pointers
        if (v[left] <= pivot) {
            left++;
        }
        if (v[r] >= pivot) {
            r--;
        }

    }
    
    std::swap(v[left], v[right]);
    return left;
}

template <typename T>
void Sorting::quickSort(std::vector<T>& v){
    quickSort(v, 0, v.size() - 1);
}

template <typename T>
void Sorting::quickSort(std::vector<T>& v, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot_index = partition(v, left, right);

    quickSort(v, left, pivot_index - 1);
    quickSort(v, pivot_index + 1, right);
}