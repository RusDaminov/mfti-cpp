import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("Abc12345", "Пароль надежный!"),
    ("abc12345", "Ошибка пароля: Пароль должен содержать заглавные буквы"),
    ("Abcdefgh", "Ошибка пароля: Пароль должен содержать цифры"),
    ("Ab1", "Ошибка пароля: Пароль должен быть не менее 8 символов"),
]

def test_password_strength():
    for pwd, expected in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=pwd + "\n")
        actual_lines = [line.strip() for line in stdout.strip().splitlines() if line.strip()]

        # Проверяем ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # В выводе должна быть ровно одна строка
        assert len(actual_lines) == 1, f"Ожидалась одна строка, получено: {actual_lines}"

        actual = actual_lines[0]
        assert actual == expected, f"Для пароля '{pwd}' ожидалось: '{expected}', получено: '{actual}'"
