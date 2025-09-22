# Конвертер температуры
celsius = float(input("Введите температуру: "))
fahrenheit = celsius * 9/5 + 32

print(f"{celsius}C = {fahrenheit:.1f}F")
print("Тип celsius:", type(celsius))
print("Тип fahrenheit:", type(fahrenheit))
