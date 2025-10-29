def calculate_sum(s):
    total = 0
    for val in s:
        total += val
    return total

def find_set_with_min_sum(setA, setB):
    sumA = calculate_sum(setA)
    sumB = calculate_sum(setB)

    if sumA < sumB:
        print(f"Множество A имеет наименьшую сумму: {sumA}")
        print("Элементы множества A:", *setA)
    else:
        print(f"Множество B имеет наименьшую сумму: {sumB}")
        print("Элементы множества B:", *setB)

def find_min_in_union(setA, setB):
    union_set = setA | setB 
    return min(union_set)

def main():
    sizeA = int(input("Введите размер множества A: "))
    sizeB = int(input("Введите размер множества B: "))

    A = set(map(int, input(f"Введите {sizeA} элементов для множества A: ").split()))
    B = set(map(int, input(f"Введите {sizeB} элементов для множества B: ").split()))

    find_set_with_min_sum(A, B)

    min_union = find_min_in_union(A, B)
    print(f"Наименьший элемент из объединения множеств A и B: {min_union}")

if __name__ == "__main__":
    main()
