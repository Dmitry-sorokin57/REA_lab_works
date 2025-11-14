def bead_sort(arr):
    if not arr or min(arr) < 0:
        raise ValueError("Массив должен содержать только неотрицательные числа")
    
    # Создаем "матрицу бусин"
    max_val = max(arr)
    beads = [[0] * max_val for _ in range(len(arr))]
    
    # Расставляем бусины
    for i, num in enumerate(arr):
        for j in range(num):
            beads[i][j] = 1
    
    # "Падение" бусин
    for j in range(max_val):
        # Считаем количество бусин в столбце
        count = sum(beads[i][j] for i in range(len(arr)))
        # Опускаем бусины вниз
        for i in range(len(arr) - 1, len(arr) - count - 1, -1):
            beads[i][j] = 1
        for i in range(len(arr) - count - 1, -1, -1):
            beads[i][j] = 0
    
    # Преобразуем обратно в числа
    for i in range(len(arr)):
        arr[i] = sum(beads[i][j] for j in range(max_val))
    
    return arr

# Пример использования
arr = [3, 1, 4, 1, 5]
print("До сортировки:", arr)
print("После сортировки:", bead_sort(arr.copy()))
