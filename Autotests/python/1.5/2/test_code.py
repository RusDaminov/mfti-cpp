import subprocess
import pytest

FILENAME = "index.py"

# Входные значения и ожидаемые выводы
test_cases = [
    ("2020\n", "Високосный год"),
    ("1900\n", "Не високосный год"),
    ("2000\n", "Високосный год"),
    ("2023\n", "Не високосный год"),
    ("2400\n", "Високосный год"),
    ("2100\n", "Не високосный год"),
    ("1996\n", "Високосный год"),
    ("1999\n", "Не високосный год")
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_leap_year(input_value, expected_output):
    # Запускаем программу
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input_value)

    # Разбиваем вывод на строки и убираем пустые
    actual_lines = [line.strip() for line in stdout.split("\n") if line.strip()]

    # Проверяем, что вывод есть
    assert len(actual_lines) > 0, (
        f"Похоже, программа не выводит ничего.\n"
        f"Проверь, используешь ли print() и input() правильно."
    )

    # Берем первую строку вывода
    actual = actual_lines[0]

    # Сравниваем с ожидаемым выводом
    assert actual == expected_output, (
        f"Ошибка в выводе программы!\n\n"
        f"Введён год: {input_value.strip()}\n"
        f"Ожидалось: {expected_output}\n"
        f"Получено: {actual}\n\n"
        f"💡 Подсказка: проверь условие для високосного года и используй правильные операторы."
    )

    # Проверяем, что ошибок в stderr нет
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
