#include <iostream>

void calculateSum(const int* arr, int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
}

void findArrayWithMinSum(const int* arrA, int sizeA, const int* arrB, int sizeB) {
    int sumA = 0, sumB = 0;
    calculateSum(arrA, sizeA, sumA);
    calculateSum(arrB, sizeB, sumB);

    if (sumA < sumB) {
        std::cout << "Массив A имеет наименьшую сумму: " << sumA << std::endl;
        std::cout << "Элементы массива A: ";
        for (int i = 0; i < sizeA; i++) std::cout << arrA[i] << " ";
    }
    else {
        std::cout << "Массив B имеет наименьшую сумму: " << sumB << std::endl;
        std::cout << "Элементы массива B: ";
        for (int i = 0; i < sizeB; i++) std::cout << arrB[i] << " ";
    }
    std::cout << std::endl;
}

int findMinInUnion(const int* arrA, int sizeA, const int* arrB, int sizeB) {
    int minVal = arrA[0];

    for (int i = 1; i < sizeA; i++) {
        if (arrA[i] < minVal) minVal = arrA[i];
    }

    for (int i = 0; i < sizeB; i++) {
        if (arrB[i] < minVal) minVal = arrB[i];
    }

    return minVal;
}

int main() {
    setlocale(LC_ALL, "ru");

    int sizeA, sizeB;

    std::cout << "Введите размер массива A: ";
    std::cin >> sizeA;
    std::cout << "Введите размер массива B: ";
    std::cin >> sizeB;

    int* A = new int[sizeA];
    int* B = new int[sizeB];

    std::cout << "Введите " << sizeA << " элементов для массива A:" << std::endl;
    for (int i = 0; i < sizeA; i++) std::cin >> A[i];

    std::cout << "Введите " << sizeB << " элементов для массива B:" << std::endl;
    for (int i = 0; i < sizeB; i++) std::cin >> B[i];

    findArrayWithMinSum(A, sizeA, B, sizeB);

    int minUnion = findMinInUnion(A, sizeA, B, sizeB);
    std::cout << "Наименьший элемент из объединения множеств A и B: " << minUnion << std::endl;

    delete[] A;
    delete[] B;

    system("pause");

    return 0;
}
