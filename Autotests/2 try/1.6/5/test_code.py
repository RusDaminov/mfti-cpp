import subprocess
import pytest

FILENAME = "index.py"

# Входные данные и ожидаемый вывод
test_cases = [
    ("95\n", ["Ваша оценка: A"]),
    ("100\n", ["Ваша оценка: A"]),
    ("85\n", ["Ваша оценка: B"]),
    ("72\n", ["Ваша оценка: C"]),
    ("60\n", ["Ваша оценка: D"]),
    ("58\n", ["Ваша оценка: F"]),
    ("0\n", ["Ваша оценка: F"]),
]

@pytest.mark.parametrize("input_value, expected_lines", test_cases)
def test_grades(input_value, expected_lines):
    process = subprocess.Popen(
        ["python3", FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input=input_value)

    # Чистим вывод
    actual_lines = [line.strip() for line in stdout.split("\n") if line.strip()]

    # Проверяем количество строк
    assert len(actual_lines) == len(expected_lines), (
        f"❌ Количество строк не совпадает!\n"
        f"👉 Введено: {input_value.strip()}\n"
        f"✅ Ожидалось {len(expected_lines)} строк: {expected_lines}\n"
        f"🛑 Получено {len(actual_lines)} строк: {actual_lines}\n\n"
        "💡 Подсказка: программа должна выводить ровно одну строку с оценкой."
    )

    # Сравниваем построчно
    for i, (expected, actual) in enumerate(zip(expected_lines, actual_lines), start=1):
        assert actual == expected, (
            f"❌ Ошибка в строке {i}!\n"
            f"👉 Введено: {input_value.strip()}\n"
            f"✅ Ожидалось: {expected}\n"
            f"🛑 Получено: {actual}\n\n"
            "💡 Подсказка: проверь условия if-elif-else и формулировку строки вывода."
        )

    # Проверяем ошибки выполнения
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
