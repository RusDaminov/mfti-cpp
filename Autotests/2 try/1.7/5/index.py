figure = input("Фигура (круг, квадрат, треугольник): ").lower()

if figure == "круг":
    r = float(input("Радиус: "))
    area = 3.14 * r ** 2
elif figure == "квадрат":
    a = float(input("Сторона: "))
    area = a ** 2
elif figure == "треугольник":
    b = float(input("Основание: "))
    h = float(input("Высота: "))
    area = 0.5 * b * h
else:
    area = None
    print("Ошибка: неизвестная фигура")

if area is not None:
    print(f"Площадь: {area:.2f}")
