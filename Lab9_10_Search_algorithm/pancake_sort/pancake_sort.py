def flip(arr, i):
    """Переворачивает массив от 0 до i"""
    start = 0
    while start < i:
        arr[start], arr[i] = arr[i], arr[start]
        start += 1
        i -= 1

def find_max_index(arr, n):
    """Находит индекс максимального элемента в массиве до n-го элемента"""
    max_index = 0
    for i in range(1, n):
        if arr[i] > arr[max_index]:
            max_index = i
    return max_index

def pancake_sort(arr):
    """Основная функция блинной сортировки"""
    n = len(arr)
    
    # Начинаем с полного массива и уменьшаем размер на 1 на каждой итерации
    for curr_size in range(n, 1, -1):
        # Находим индекс максимального элемента в несортированной части
        max_index = find_max_index(arr, curr_size)
        
        # Если максимальный элемент не на своем месте
        if max_index != curr_size - 1:
            # Переворачиваем массив до максимального элемента,
            # чтобы переместить его в начало
            if max_index != 0:
                flip(arr, max_index)
            
            # Теперь переворачиваем весь несортированный массив,
            # чтобы переместить максимальный элемент на правильную позицию
            flip(arr, curr_size - 1)
    
    return arr

# Пример использования
arr = [23, 10, 20, 11, 12, 6, 7]
print("Исходный массив:", arr)
sorted_arr = pancake_sort(arr.copy())
print("Отсортированный массив:", sorted_arr)

# Демонстрация процесса
def pancake_sort_with_steps(arr):
    """Блинная сортировка с выводом шагов"""
    print(f"\nНачальный массив: {arr}")
    n = len(arr)
    
    for curr_size in range(n, 1, -1):
        max_index = find_max_index(arr, curr_size)
        
        if max_index != curr_size - 1:
            if max_index != 0:
                print(f"Переворачиваем до индекса {max_index}: ", end="")
                flip(arr, max_index)
                print(arr)
            
            print(f"Переворачиваем до индекса {curr_size - 1}: ", end="")
            flip(arr, curr_size - 1)
            print(arr)
    
    return arr

# Демонстрация с шагами
arr2 = [3, 1, 4, 2]
pancake_sort_with_steps(arr2)
