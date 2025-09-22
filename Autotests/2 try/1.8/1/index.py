currency = input("Валюта (USD, EUR, GBP): ").upper()
amount = float(input("Сумма: "))

match currency:
    case "USD":
        result = amount * 75.5
    case "EUR":
        result = amount * 80.2
    case "GBP":
        result = amount * 90.1
    case _:
        print("Ошибка: неизвестная валюта")
        exit()

print(f"{amount} {currency} = {result:.2f} RUB")
