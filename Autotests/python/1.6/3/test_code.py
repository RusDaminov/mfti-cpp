import subprocess
import pytest

FILENAME = "index.py"

# Входные данные и ожидаемый вывод
test_cases = [
    ("1\n", "Время года: Зима"),
    ("12\n", "Время года: Зима"),
    ("2\n", "Время года: Зима"),
    ("3\n", "Время года: Весна"),
    ("4\n", "Время года: Весна"),
    ("5\n", "Время года: Весна"),
    ("6\n", "Время года: Лето"),
    ("7\n", "Время года: Лето"),
    ("8\n", "Время года: Лето"),
    ("9\n", "Время года: Осень"),
    ("10\n", "Время года: Осень"),
    ("11\n", "Время года: Осень"),
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_season(input_value, expected_output):
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

    # Проверяем, что программа что-то вывела
    assert actual_lines, (
        "❌ Программа ничего не вывела.\n"
        "Добавь print(), чтобы выводить результат."
    )

    actual = actual_lines[0]

    # Сравнение вывода
    assert actual == expected_output, (
        f"❌ Ошибка в выводе!\n\n"
        f"👉 Введено: {input_value.strip()}\n"
        f"✅ Ожидалось: {expected_output}\n"
        f"🛑 Получено: {actual}\n\n"
        "💡 Подсказка: используй if-elif-else и оператор in, "
        "и убедись, что вывод совпадает с примером."
    )

    # Проверяем ошибки выполнения
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
