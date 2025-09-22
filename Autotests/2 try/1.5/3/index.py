correct_login = "admin"
correct_password = "qwerty"

login = input("Введите логин: ")
password = input("Введите пароль: ")

if login == correct_login and password == correct_password:
    print("Доступ разрешен")
else:
    print("Доступ запрещен")
