filename = input("Введите имя файла: ")

try:
    with open(filename, 'r') as file:
        content = file.read()
        print("Содержимое файла:")
        print(content)
except FileNotFoundError:
    print("Ошибка: файл не найден")
except PermissionError:
    print("Ошибка: нет прав доступа к файлу")
except Exception as e:
    print(f"Неизвестная ошибка: {e}")
