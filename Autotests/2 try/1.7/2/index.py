weight = float(input("Вес (кг): "))
height = float(input("Рост (м): "))
bmi = weight / (height ** 2)

if bmi < 18.5:
    category = "Недостаток"
elif 18.5 <= bmi < 25:
    category = "Норма"
elif 25 <= bmi < 30:
    category = "Избыток"
else:
    category = "Ожирение"

print(f"ИМТ: {bmi:.1f}, Категория: {category}")
