import subprocess
import pytest

FILENAME = "index.py"

# Тестовые стороны треугольника и ожидаемый вывод
test_cases = [
    ("3\n4\n5\n", "Треугольник существует"),
    ("10\n6\n3\n", "Треугольник не существует"),
    ("5\n5\n5\n", "Треугольник существует"),
    ("1\n2\n3\n", "Треугольник не существует"),
    ("7\n10\n5\n", "Треугольник существует"),
    ("0\n5\n7\n", "Треугольник не существует"),  # нулевая сторона
    ("3.5\n4.2\n5.1\n", "Треугольник существует"),  # float
    ("2\n2\n4\n", "Треугольник не существует")  # равенство суммы двух сторон третьей
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_triangle_exists(input_value, expected_output):
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
        f"Введены стороны: {input_value.replace(chr(10), ' / ')}\n"
        f"Ожидалось: {expected_output}\n"
        f"Получено: {actual}\n\n"
        f"💡 Подсказка: проверь, что используешь условие 'and' для проверки всех трёх неравенств."
    )

    # Проверяем, что ошибок в stderr нет
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
