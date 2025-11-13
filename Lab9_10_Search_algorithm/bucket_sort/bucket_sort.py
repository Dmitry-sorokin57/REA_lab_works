def bucket_sort(arr):
    if len(arr) == 0:
        return arr

    # Находим минимальное и максимальное значения
    min_val = min(arr)
    max_val = max(arr)

    # Создаем корзины
    bucket_count = len(arr)
    buckets = [[] for _ in range(bucket_count)]

    # Распределяем элементы по корзинам
    for num in arr:
        # Вычисляем индекс корзины
        index = int((num - min_val) / (max_val - min_val) * (bucket_count - 1))
        buckets[index].append(num)

    # Сортируем каждую корзину и объединяем результат
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket))

    return sorted_arr


# Пример использования
arr = [0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51]
print("Исходный массив:", arr)
sorted_arr = bucket_sort(arr)
print("Отсортированный массив:", sorted_arr)
