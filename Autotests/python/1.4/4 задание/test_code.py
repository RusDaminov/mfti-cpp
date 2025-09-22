import subprocess
import pytest

FILENAME = "index.py"

# Тестовые наборы входных и ожидаемых выходов
TEST_CASES = [
    ("0\n", "0.0C = 32.0F\nТип celsius: <class 'float'>\nТип fahrenheit: <class 'float'>"),
    ("100\n", "100.0C = 212.0F\nТип celsius: <class 'float'>\nТип fahrenheit: <class 'float'>"),
    ("-40\n", "-40.0C = -40.0F\nТип celsius: <class 'float'>\nТип fahrenheit: <class 'float'>"),
]

@pytest.mark.parametrize("input_values, expected_output", TEST_CASES)
def test_temperature_converter(input_values, expected_output):
    # Запускаем скрипт
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input_values)
    actual_lines = stdout.strip().splitlines()
    expected_lines = expected_output.splitlines()

    messages = []
    all_good = True
    used_indices = set()

    # Проверяем построчно каждую ожидаемую строку
    for i, exp in enumerate(expected_lines, start=1):
        found = False
        for j, act in enumerate(actual_lines):
            if j in used_indices:
                continue
            if act == exp:
                messages.append(f"✅ Строка {i} верна: {exp}")
                used_indices.add(j)
                found = True
                break
        if not found:
            messages.append(f"❌ Строка {i} не найдена в выводе! Ожидалось: {exp}")
            all_good = False

    # Лишние строки
    for j, act in enumerate(actual_lines):
        if j not in used_indices:
            messages.append(f"❌ Лишняя строка в выводе: {act}")
            all_good = False

    # Проверка ошибок выполнения
    if stderr:
        messages.append(f"❌ Программа завершилась с ошибкой:\n{stderr}")
        all_good = False

    if not all_good:
        full_report = "\n".join(messages)
        raise AssertionError("\nРазбор вывода программы:\n\n" + full_report)
