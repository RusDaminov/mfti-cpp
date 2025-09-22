try:
    a = float(input("Введите первое число: "))
    b = float(input("Введите второе число: "))
    op = input("Операция (+, -, *, /): ")
    
    match op:
        case '+': res = a + b
        case '-': res = a - b
        case '*': res = a * b
        case '/': res = a / b
        case _: raise ValueError("Неизвестная операция")
    
    print(f"Результат: {res}")
except ValueError as e:
    print(f"Ошибка ввода: {e}")
except ZeroDivisionError:
    print("Ошибка: деление на ноль")
