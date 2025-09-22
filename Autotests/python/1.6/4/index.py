num = int(input("Введите число: "))

if num > 0:
    print("Положительное")
elif num < 0:
    print("Отрицательное")
else:
    print("Ноль")

if num % 2 == 0:
    print("Чётное")
else:
    print("Нечётное")
