#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Рекурсивна функція для створення масиву
void create(int* arr, int size, int min, int max, int i = 0) {
    if (i < size) {
        arr[i] = min + rand() % (max - min + 1);
        create(arr, size, min, max, i + 1);
    }
}

// Рекурсивна функція для виведення масиву
void print(int* arr, int size, int i = 0) {
    cout << setw(4) << arr[i];
    if (i < size - 1) {
        print(arr, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Рекурсивна функція для знаходження індексу найбільшого непарного елемента
int findLargestOddIndex(int* arr, int size, int i = 0, int largestOdd = -1, int largestOddIndex = -1) {
    if (i == size) {
        return largestOddIndex;
    }
    if (arr[i] % 2 != 0 && (largestOdd == -1 || arr[i] > largestOdd)) {
        largestOdd = arr[i];
        largestOddIndex = i;
    }
    return findLargestOddIndex(arr, size, i + 1, largestOdd, largestOddIndex);
}

// Рекурсивна функція для обміну останнього елемента з найбільшим непарним
void swapLastWithLargestOdd(int* arr, int size, int i = 0) {
    int largestOddIndex = findLargestOddIndex(arr, size);
    if (largestOddIndex != -1) { // якщо є непарний елемент
        int lastIndex = size - 1;
        swap(arr[largestOddIndex], arr[lastIndex]);
    }
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    print(arr, SIZE);

    swapLastWithLargestOdd(arr, SIZE);

    print(arr, SIZE);

    delete[] arr;
    return 0;
}
