def calculate_sum(arr):
    total = 0
    for val in arr:
        total += val
    return total

def find_set_with_min_sum(arrA, arrB):
    sumA = calculate_sum(arrA)
    sumB = calculate_sum(arrB)

    if sumA < sumB:
        print(f"Массив A имеет наименьшую сумму: {sumA}")
        print("Элементы массива A:", *arrA)
    else:
        print(f"Массив B имеет наименьшую сумму: {sumB}")
        print("Элементы массива B:", *arrB)

def find_min_in_union(setA, setB):
    union_set = setA | setB
    return min(union_set)

def main():
    sizeA = int(input("Введите размер множества A: "))
    sizeB = int(input("Введите размер множества B: "))

    A = set(map(int, input(f"Введите {sizeA} элементов для множества A: ").split()))
    B = set(map(int, input(f"Введите {sizeB} элементов для множества B: ").split()))

    arrA = list(A)
    arrB = list(B)

    find_set_with_min_sum(arrA, arrB)

    min_union = find_min_in_union(A, B)
    print(f"Наименьший элемент из объединения множеств A и B: {min_union}")

if __name__ == "__main__":
    main()
