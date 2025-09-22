import subprocess
import pytest

FILENAME = "index.py"

# Тестовые пары логин+пароль и ожидаемый вывод
test_cases = [
    ("admin\nqwerty\n", "Доступ разрешен"),
    ("admin\n12345\n", "Доступ запрещен"),
    ("user\nqwerty\n", "Доступ запрещен"),
    ("user\n123\n", "Доступ запрещен"),
    ("Admin\nqwerty\n", "Доступ запрещен"),  # проверка с большой буквы
    ("admin\nQwerty\n", "Доступ запрещен")   # проверка с большой буквы в пароле
]

@pytest.mark.parametrize("input_value, expected_output", test_cases)
def test_login_password(input_value, expected_output):
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
        f"Введён логин/пароль:\n{input_value.replace(chr(10), ' / ')}\n"
        f"Ожидалось: {expected_output}\n"
        f"Получено: {actual}\n\n"
        f"💡 Подсказка: проверь, что используешь логический оператор 'and' для проверки одновременно логина и пароля."
    )

    # Проверяем, что ошибок в stderr нет
    assert stderr.strip() == "", f"Программа вызвала ошибку:\n{stderr}"
