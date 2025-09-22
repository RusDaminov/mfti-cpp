def get_element(lst, index):
    try:
        return lst[index]
    except IndexError:
        print("Ошибка: индекс вне диапазона")
        return None
    except TypeError:
        print("Ошибка: индекс должен быть целым числом")
        return None

# Ввод списка от пользователя
lst_input = input("Введите список элементов через пробел: ")
lst = lst_input.split()

# Ввод индекса
index_input = input("Введите индекс элемента: ")
try:
    index = int(index_input)
except ValueError:
    print("Ошибка: индекс должен быть целым числом")
    index = None

# Получение элемента
if index is not None:
    element = get_element(lst, index)
    if element is not None:
        print(element)
