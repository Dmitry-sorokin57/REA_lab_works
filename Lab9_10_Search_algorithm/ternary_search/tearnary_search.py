def ternary_search_iterative(arr, target):
    """
    Тернарный поиск (итеративная версия).
    Возвращает индекс элемента или -1, если не найден.
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        # Вычисляем две точки деления
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
        
        # Проверяем точки деления
        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2
        
        # Определяем в какой трети продолжать поиск
        if target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1
    
    return -1

#### Рекурсивная версия
def ternary_search_recursive(arr, target):
    """
    Тернарный поиск (рекурсивная версия).
    """
    def search(left, right):
        if left > right:
            return -1
        
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
        
        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2
        
        if target < arr[mid1]:
            return search(left, mid1 - 1)
        elif target > arr[mid2]:
            return search(mid2 + 1, right)
        else:
            return search(mid1 + 1, mid2 - 1)
    
    return search(0, len(arr) - 1)

# Пример использования
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
target = 8

print("Массив:", arr)
print(f"Поиск элемента {target}")

# Тестирование обеих версий
result_iter = ternary_search_iterative(arr, target)
result_rec = ternary_search_recursive(arr, target)

print(f"Итеративная версия: элемент {'найден на позиции ' + str(result_iter) if result_iter != -1 else 'не найден'}")
print(f"Рекурсивная версия: элемент {'найден на позиции ' + str(result_rec) if result_rec != -1 else 'не найден'}")

# Тестирование на разных случаях
test_cases = [1, 15, 8, 20, -5]
print("\nТестирование итеративной версии:")
for test_target in test_cases:
    idx = ternary_search_iterative(arr, test_target)
    status = f"найден на позиции {idx}" if idx != -1 else "не найден"
    print(f"Элемент {test_target}: {status}")
