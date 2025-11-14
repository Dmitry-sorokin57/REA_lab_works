import math

def jump_search(arr, target):
    """
    Поиск скачками в отсортированном массиве.
    Возвращает индекс элемента или -1, если не найден.
    """
    n = len(arr)
    if n == 0:
        return -1
    
    # Определяем размер шага
    step = int(math.sqrt(n))
    
    # Поиск блока, где может находиться элемент
    prev = 0
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1
    
    # Линейный поиск в найденном блоке
    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
        if arr[i] > target:
            break
    
    return -1

# Пример использования
arr = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144]
target = 34

print("Массив:", arr)
print(f"Поиск элемента {target}")

result = jump_search(arr, target)
if result != -1:
    print(f"Элемент найден на позиции {result}")
else:
    print("Элемент не найден")
