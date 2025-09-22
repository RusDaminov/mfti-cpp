import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("deposit\n50", "Баланс: 150"),
    ("withdraw\n30", "Баланс: 70"),  # баланс снижается с 100 до 70 после снятия
    ("withdraw\n200", "Ошибка: Недостаточно средств на счете"),
    ("deposit\n-10", "Ошибка значения: Сумма должна быть положительной"),
    ("withdraw\n-5", "Ошибка значения: Сумма должна быть положительной"),
    ("transfer\n10", "Ошибка: неизвестное действие"),
]

def test_bank_account():
    for input_data, expected in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=input_data)
        actual_lines = [line.strip() for line in stdout.strip().splitlines() if line.strip()]

        # Проверяем ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # В выводе должна быть хотя бы одна строка
        assert actual_lines, f"Нет вывода для ввода: {input_data}"

        actual = actual_lines[-1]  # берем последнюю строку, т.к. баланс выводится после операции
        assert actual == expected, f"Для ввода '{input_data}' ожидалось: '{expected}', получено: '{actual}'"
