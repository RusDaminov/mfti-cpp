temp_input = input("Температура (например, 25C или 77F): ")

match temp_input[-1], temp_input[:-1]:
    case ("C" | "c", temp) if temp.isdigit():
        f = float(temp) * 9/5 + 32
        print(f"{temp}C = {f:.1f}F")
    case ("F" | "f", temp) if temp.isdigit():
        c = (float(temp) - 32) * 5/9
        print(f"{temp}F = {c:.1f}C")
    case _:
        print("Ошибка формата. Используйте например '25C' или '77F'")
