#include <iostream>
#include <set>

int calculateSum(const std::set<int>& s) {
    int sum = 0;
    for (int val : s) {
        sum += val;
    }
    return sum;
}

void findSetWithMinSum(const std::set<int>& setA, const std::set<int>& setB) {
    int sumA = calculateSum(setA);
    int sumB = calculateSum(setB);

    if (sumA < sumB) {
        std::cout << "Множество A имеет наименьшую сумму: " << sumA << std::endl;
        std::cout << "Элементы множества A: ";
        for (int val : setA) std::cout << val << " ";
    }
    else {
        std::cout << "Множество B имеет наименьшую сумму: " << sumB << std::endl;
        std::cout << "Элементы множества B: ";
        for (int val : setB) std::cout << val << " ";
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

    findSetWithMinSum(setA, setB);

    int minUnion = findMinInUnion(setA, setB);
    std::cout << "Наименьший элемент из объединения множеств A и B: " << minUnion << std::endl;

    system("pause");
    return 0;
}
