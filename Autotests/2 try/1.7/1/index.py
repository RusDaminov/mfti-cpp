temp = float(input("Введите температуру: "))
scale = input("Шкала (C/F): ").upper()

if scale == "C":
    converted = temp * 9/5 + 32
    print(f"{temp}°C = {converted}°F")
elif scale == "F":
    converted = (temp - 32) * 5/9
    print(f"{temp}°F = {converted}°C")
else:
    print("Ошибка: выберите C или F")
