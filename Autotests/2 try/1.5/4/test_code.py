import subprocess
import pytest

FILENAME = "index.py"

# Тестовые координаты и ожидаемый вывод
test_cases = [
    ("5\n7\n", "I четверть"),
    ("-3\n4\n", "II четверть"),
    ("-2\n-6\n", "III четверть"),
    ("8\n-5\n", "IV четверть"),
    ("0\n3\n", "Точка на оси"),
    ("4\n0\n", "Точка на оси"),
    ("0\n0\n", "Точка на оси"),
    ("1.5\n2.7\n", "I четверть"),
    ("-0.1\n-0.2\n", "III четверть")
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_quadrant(input_value, expected_output):
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
        "Похоже, программа не выводит ничего.\n"
        "Проверь, используешь ли print() и input() правильно."
    )

    # Берем первую строку вывода
    actual = actual_lines[0]

    # Сравниваем с ожидаемым результатом
    assert actual == expected_output, (
        f"Ошибка в выводе программы!\n\n"
        f"Введены координаты: {input_value.replace(chr(10), ' / ')}\n"
        f"Ожидалось: {expected_output}\n"
        f"Получено: {actual}\n\n"
        f"💡 Подсказка: проверь логические условия и последовательность проверки осей и четвертей."
    )

    # Проверяем, что ошибок в stderr нет
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
