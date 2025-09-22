import subprocess
import pytest

FILENAME = "index.py"

# Входные данные и ожидаемый вывод
test_cases = [
    ("500\n", "Ваша скидка: 0%"),
    ("999.99\n", "Ваша скидка: 0%"),
    ("1000\n", "Ваша скидка: 5%"),
    ("1500\n", "Ваша скидка: 5%"),
    ("5000\n", "Ваша скидка: 5%"),
    ("7000\n", "Ваша скидка: 10%"),
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_discount(input_value, expected_output):
    process = subprocess.Popen(
        ["python3", FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input=input_value)

    # Чистим вывод от пустых строк и пробелов
    actual_lines = [line.strip() for line in stdout.split("\n") if line.strip()]

    # Проверяем, что программа что-то вывела
    assert actual_lines, (
        "❌ Программа ничего не вывела.\n"
        "Убедись, что используешь print()."
    )

    # Берем первую строку (по условию задачи нужен один вывод)
    actual = actual_lines[0]

    # Проверяем совпадение
    assert actual == expected_output, (
        f"❌ Ошибка в выводе!\n\n"
        f"👉 Введено: {input_value.strip()}\n"
        f"✅ Ожидалось: {expected_output}\n"
        f"🛑 Получено: {actual}\n\n"
        "💡 Подсказка: проверь условия if-elif-else, "
        "и убедись, что вывод полностью совпадает с примером."
    )

    # Проверяем, что программа не упала с ошибкой
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
