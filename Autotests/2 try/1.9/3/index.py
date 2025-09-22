class PasswordError(Exception):
    pass

class LengthError(PasswordError):
    pass

class DigitError(PasswordError):
    pass

class UpperCaseError(PasswordError):
    pass

def validate_password(password):
    if len(password) < 8:
        raise LengthError("Пароль должен быть не менее 8 символов")
    if not any(c.isdigit() for c in password):
        raise DigitError("Пароль должен содержать цифры")
    if not any(c.isupper() for c in password):
        raise UpperCaseError("Пароль должен содержать заглавные буквы")

try:
    pwd = input("Введите пароль: ")
    validate_password(pwd)
    print("Пароль надежный!")
except PasswordError as e:
    print(f"Ошибка пароля: {e}")
