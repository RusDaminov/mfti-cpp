figure = eval(input("Введите фигуру (например, ('circle', 5)): "))

match figure:
    case ("circle", r):
        area = 3.14 * r ** 2
        print(f"Площадь круга: {area:.2f}")
    case ("rect", a, b):
        area = a * b
        print(f"Площадь прямоугольника: {area:.2f}")
    case ("triangle", a, b, c):
        perimeter = a + b + c
        print(f"Периметр треугольника: {perimeter:.2f}")
    case _:
        print("Неизвестная фигура")
