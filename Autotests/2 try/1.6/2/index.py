summa = float(input("Введите сумму покупки: "))

if summa > 5000:
    discount = 10
elif summa >= 1000:
    discount = 5
else:
    discount = 0

print(f"Ваша скидка: {discount}%")
