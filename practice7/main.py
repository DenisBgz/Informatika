def calculate_sum(arr):
    """Вычисляет сумму элементов массива"""
    return sum(arr)

def find_array_with_min_sum(arrA, arrB):
    """Определяет, какой массив имеет наименьшую сумму, и выводит его"""
    sumA = calculate_sum(arrA)
    sumB = calculate_sum(arrB)

    if sumA < sumB:
        print(f"Массив A имеет наименьшую сумму: {sumA}")
        print("Элементы массива A:", *arrA)
    else:
        print(f"Массив B имеет наименьшую сумму: {sumB}")
        print("Элементы массива B:", *arrB)

def find_min_in_union(arrA, arrB):
    """Находит наименьший элемент в объединении массивов"""
    return min(min(arrA), min(arrB))

def main():
    sizeA = int(input("Введите размер массива A: "))
    sizeB = int(input("Введите размер массива B: "))

    A = list(map(int, input(f"Введите {sizeA} элементов для массива A: ").split()))
    B = list(map(int, input(f"Введите {sizeB} элементов для массива B: ").split()))

    if len(A) != sizeA or len(B) != sizeB:
        print("Ошибка: количество введённых элементов не совпадает с размером массива.")
        return

    find_array_with_min_sum(A, B)

    min_union = find_min_in_union(A, B)
    print(f"Наименьший элемент из объединения множеств A и B: {min_union}")

if __name__ == "__main__":
    main()
