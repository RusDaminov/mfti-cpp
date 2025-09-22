import subprocess
import pytest

FILENAME = "index.py"

# Входные данные и ожидаемый вывод
test_cases = [
    ("7\n", ["Положительное", "Нечётное"]),
    ("-4\n", ["Отрицательное", "Чётное"]),
    ("0\n", ["Ноль", "Чётное"]),
    ("10\n", ["Положительное", "Чётное"]),
    ("-7\n", ["Отрицательное", "Нечётное"]),
]

@pytest.mark.parametrize("input_value, expected_lines", test_cases)
def test_number_properties(input_value, expected_lines):
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
        "💡 Подсказка: выводи каждую характеристику числа через print() на отдельной строке."
    )

    # Сравниваем построчно
    for i, (expected, actual) in enumerate(zip(expected_lines, actual_lines), start=1):
        assert actual == expected, (
            f"❌ Ошибка в строке {i}!\n"
            f"👉 Введено: {input_value.strip()}\n"
            f"✅ Ожидалось: {expected}\n"
            f"🛑 Получено: {actual}\n\n"
            "💡 Подсказка: проверь условные конструкции if-elif-else "
            "и убедись, что вывод полностью совпадает."
        )

    # Проверяем ошибки выполнения
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
