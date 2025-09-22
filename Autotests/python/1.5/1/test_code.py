import subprocess
import pytest

FILENAME = "index.py"

# Входные значения и ожидаемые выводы
test_cases = [
    ("15\n", "Число в диапазоне [10, 20]"),
    ("10\n", "Число в диапазоне [10, 20]"),
    ("20\n", "Число в диапазоне [10, 20]"),
    ("5\n", "Число вне диапазона"),
    ("25\n", "Число вне диапазона"),
    ("15.5\n", "Число в диапазоне [10, 20]"),
    ("9.99\n", "Число вне диапазона"),
    ("20.01\n", "Число вне диапазона")
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_number_range(input_value, expected_output):
    # Запускаем программу
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input_value)

    # Разбиваем вывод на строки и убираем лишние пробелы
    actual_lines = [line.strip() for line in stdout.split("\n") if line.strip()]

    # Проверяем, что вывод содержит хотя бы одну строку
    assert len(actual_lines) > 0, (
        f"Похоже, программа не выводит ничего.\n"
        f"Попробуй проверить, используешь ли print() и input() правильно."
    )

    # Берем только первую строку вывода
    actual = actual_lines[0]

    # Сравниваем с ожидаемым выводом
    assert actual == expected_output, (
        f"Ошибка в выводе программы!\n\n"
        f"Введено число: {input_value.strip()}\n"
        f"Ожидалось: {expected_output}\n"
        f"Получено: {actual}\n\n"
        f"💡 Подсказка: проверь, правильно ли проверяешь диапазон и используешь print()."
    )

    # Проверяем, что ошибок в stderr нет
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
