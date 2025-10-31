def quick_sort(array, low, high):
    """
    Метод для сортировки массива
    """
    if low < high:
        # pi - это индекс разбиения, array[pi] находится на своем месте
        pi = partition(array, low, high)
        
        # Отсортировать элементы до и после разбиения
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

def partition(array, low, high):
    """
    Метод для разбиения массива
    """
    # Выбираем последний элемент в качестве опорного
    pivot = array[high]
    i = low - 1  # Индекс меньшего элемента
    
    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if array[j] <= pivot:
            i += 1
            # Поменять местами array[i] и array[j]
            array[i], array[j] = array[j], array[i]
    
    # Поменять местами array[i+1] и array[high] (опорный элемент)
    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1

def print_array(array):
    """
    Вспомогательный метод для вывода массива
    """
    for value in array:
        print(value, end=" ")
    print()

# Основной метод для запуска сортировки
if __name__ == "__main__":
    array = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:")
    print_array(array)
    
    quick_sort(array, 0, len(array) - 1)
    
    print("\nОтсортированный массив:")
    print_array(array)
