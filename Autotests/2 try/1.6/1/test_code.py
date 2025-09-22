import subprocess
import pytest

FILENAME = "index.py"

# Тестовые входные данные и ожидаемый вывод
test_cases = [
    ("20\n", "Можно получить права"),
    ("18\n", "Можно получить права"),
    ("17\n", "Ещё рано для прав"),
    ("10\n", "Ещё рано для прав"),
    ("0\n", "Ещё рано для прав"),
    ("99\n", "Можно получить права"),
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_driving_license(input_value, expected_output):
    # Запускаем программу
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input_value)

    # Чистим вывод
    actual_lines = [line.strip() for line in stdout.split("\n") if line.strip()]

    # Проверка: программа что-то вывела
    assert len(actual_lines) > 0, (
        "❌ Программа не вывела ничего.\n"
        "Проверь, что используешь print()."
    )

    # Берем первую строку
    actual = actual_lines[0]

    # Сравниваем
    assert actual == expected_output, (
        f"❌ Ошибка в выводе!\n\n"
        f"👉 Введено: {input_value.strip()}\n"
        f"✅ Ожидалось: {expected_output}\n"
        f"🛑 Получено: {actual}\n\n"
        f"💡 Подсказка: проверь условие 'if age >= 18', "
        f"и убедись, что вывод совпадает с заданием."
    )

    # Проверка на ошибки
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
