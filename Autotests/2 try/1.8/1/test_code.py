import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("USD", 100, "100 USD = 7550.00 RUB"),
    ("EUR", 50, "50 EUR = 4010.00 RUB"),
    ("GBP", 10, "10 GBP = 901.00 RUB"),
    ("JPY", 1000, "Ошибка: неизвестная валюта")
]

def test_currency_converter():
    for currency_input, amount_input, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        # Передаём два input: код валюты и сумму
        stdout, stderr = process.communicate(input=f"{currency_input}\n{amount_input}\n")
        actual_lines = stdout.strip().splitlines()

        # Проверка ошибок выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # Проверяем, что вывод содержит именно ожидаемую строку
        assert expected_output in actual_lines, (
            f"\n❌ Ожидалось: {expected_output}\n"
            f"✅ Получено: {actual_lines}"
        )
