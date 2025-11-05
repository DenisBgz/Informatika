#include <iostream>
#include <set>

void calculateSum(const int* arr, int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
}

void findArrayWithMinSum(const int* arrA, const int* arrB, int size) {
    int sumA = 0, sumB = 0;

    calculateSum(arrA, size, sumA);
    calculateSum(arrB, size, sumB);

    if (sumA < sumB) {
        std::cout << "Массив A имеет наименьшую сумму: " << sumA << std::endl;
        std::cout << "Элементы массива A: ";
        for (int i = 0; i < size; i++) {
            std::cout << arrA[i] << " ";
        }
    }
    else {
        std::cout << "Массив B имеет наименьшую сумму: " << sumB << std::endl;
        std::cout << "Элементы массива B: ";
        for (int i = 0; i < size; i++) {
            std::cout << arrB[i] << " ";
        }
    }
    std::cout << std::endl;
}

int findMinInUnion(const std::set<int>& setA, const std::set<int>& setB) {
    std::set<int> unionSet = setA;
    unionSet.insert(setB.begin(), setB.end());

    return *unionSet.begin();
}

int main() {
    setlocale(LC_ALL, "ru");

    int sizeA, sizeB;
    std::cout << "Введите размер множества A: ";
    std::cin >> sizeA;
    std::cout << "Введите размер множества B: ";
    std::cin >> sizeB;

    std::set<int> setA, setB;
    int value;

    std::cout << "Введите " << sizeA << " элементов для множества A:" << std::endl;
    for (int i = 0; i < sizeA; i++) {
        std::cin >> value;
        setA.insert(value);
    }

    std::cout << "Введите " << sizeB << " элементов для множества B:" << std::endl;
    for (int i = 0; i < sizeB; i++) {
        std::cin >> value;
        setB.insert(value);
    }

    int* arrA = new int[setA.size()];
    int* arrB = new int[setB.size()];

    int i = 0;
    for (int val : setA) arrA[i++] = val;
    i = 0;
    for (int val : setB) arrB[i++] = val;

    findArrayWithMinSum(arrA, arrB, (int)setA.size() < (int)setB.size() ? (int)setA.size() : (int)setB.size());

    int minUnion = findMinInUnion(setA, setB);
    std::cout << "Наименьший элемент из объединения множеств A и B: " << minUnion << std::endl;

    delete[] arrA;
    delete[] arrB;

    system("pause");
    return 0;
}

