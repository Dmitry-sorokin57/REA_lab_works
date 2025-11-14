def binary_search(arr, left, right, target):
    """
    Вспомогательная функция бинарного поиска.
    """
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def exponential_search(arr, target):
    """
    Экспоненциальный поиск в отсортированном массиве.
    Возвращает индекс элемента или -1, если не найден.
    """
    n = len(arr)
    if n == 0:
        return -1
    
    # Если элемент в начале массива
    if arr[0] == target:
        return 0
    
    # Находим диапазон для бинарного поиска
    i = 1
    while i < n and arr[i] <= target:
        i *= 2
    
    # Выполняем бинарный поиск в найденном диапазоне
    left = i // 2
    right = min(i, n - 1)
    return binary_search(arr, left, right, target)

# Пример использования
arr = [2, 3, 4, 10, 15, 18, 20, 23, 35, 40, 55, 60, 78, 90]
target = 35

print("Массив:", arr)
print(f"Поиск элемента {target}")

result = exponential_search(arr, target)
if result != -1:
    print(f"Элемент найден на позиции {result}")
else:
    print("Элемент не найден")

# Тестирование на разных случаях
test_cases = [2, 90, 15, 100, -1]
print("\nТестирование:")
for test_target in test_cases:
    idx = exponential_search(arr, test_target)
    status = f"найден на позиции {idx}" if idx != -1 else "не найден"
    print(f"Элемент {test_target}: {status}")
