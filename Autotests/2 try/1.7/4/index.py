client_type = input("Тип клиента: ").lower()

if client_type == "platinum":
    discount = 20
elif client_type == "gold":
    discount = 15
elif client_type == "silver":
    discount = 10
elif client_type == "regular":
    discount = 5
else:
    discount = 0

print(f"Ваша скидка: {discount}%")
