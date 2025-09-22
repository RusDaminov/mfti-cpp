day = int(input("Номер дня (1-7): "))

if day == 1:
    name = "Понедельник"
elif day == 2:
    name = "Вторник"
elif day == 3:
    name = "Среда"
elif day == 4:
    name = "Четверг"
elif day == 5:
    name = "Пятница"
elif day == 6:
    name = "Суббота"
elif day == 7:
    name = "Воскресенье"
else:
    name = "Ошибка: введите число 1-7"

print(name)
