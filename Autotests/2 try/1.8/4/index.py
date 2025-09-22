role = input("Ваша роль: ").lower()

match role:
    case "admin":
        access = "Полный доступ"
    case "editor":
        access = "Редактирование"
    case "viewer":
        access = "Просмотр"
    case _:
        access = "Нет доступа"

print(f"Уровень доступа: {access}")
