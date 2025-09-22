month = int(input("Введите номер месяца (1-12): "))

if month in (12, 1, 2):
    season = "Зима"
elif month in (3, 4, 5):
    season = "Весна"
elif month in (6, 7, 8):
    season = "Лето"
else:
    season = "Осень"

print(f"Время года: {season}")
 
