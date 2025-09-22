import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("5\n3\n+\n", "Результат: 8.0"),
    ("10\n2\n/\n", "Результат: 5.0"),
    ("10\n0\n/\n", "Ошибка: деление на ноль"),
    ("5\nx\n*\n", "Ошибка ввода: could not convert string to float: 'x'"),
    ("5\n2\n^\n", "Ошибка ввода: Неизвестная операция"),
]

def test_calculator():
    for user_input, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=user_input)

        # Проверка на ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        actual = stdout.strip()

        if expected_output not in actual:
            raise AssertionError(
                f"\n❌ Тест провален для ввода:\n{user_input}\n"
                f"Ожидалось: {expected_output}\n"
                f"Фактически: {actual}\n"
            )
