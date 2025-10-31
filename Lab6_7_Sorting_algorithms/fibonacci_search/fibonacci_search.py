def fibonacci_search(arr, x):
    """
    Функция поиска Фибоначчи
    """
    n = len(arr)
    
    # Находим наименьшее число Фибоначчи, большее или равное n
    fib_m2 = 0  # (m-2)'е число Фибоначчи
    fib_m1 = 1  # (m-1)'е число Фибоначчи
    fib_m = fib_m2 + fib_m1
    
    # Находим m такое, что F[m] >= n
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1
    
    # Маркеры для элементов, которые не входят в массив
    offset = -1
    
    # Поиск
    while fib_m > 1:
        # Проверяем возможный индекс
        i = min(offset + fib_m2, n - 1)
        
        # Если x больше элемента, переходим к правому подмассиву
        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        # Если x меньше элемента, переходим к левому подмассиву
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        # Элемент найден
        else:
            return i
    
    # Проверяем последний элемент
    if fib_m1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1
    
    return -1  # Элемент не найден

def main():
    arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    x = 85
    
    print("Массив:", arr)
    print("Искомый элемент:", x)
    
    result = fibonacci_search(arr, x)
    
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")
    
    # Дополнительные тесты
    print("\nДополнительные тесты:")
    test_cases = [10, 100, 35, 99, 82]
    for test_x in test_cases:
        result = fibonacci_search(arr, test_x)
        if result != -1:
            print(f"Элемент {test_x} найден на позиции: {result}")
        else:
            print(f"Элемент {test_x} не найден")

if __name__ == "__main__":
    main()
