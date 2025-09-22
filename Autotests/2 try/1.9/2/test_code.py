import subprocess

FILENAME = "index.py"
EXPECTED_CONTENT = '"Да пребудет с тобой Сила." — Звёздные войны'

def test_file_reading():
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    # передаем имя файла
    stdout, stderr = process.communicate(input="test.txt\n")

    actual_lines = [line.strip() for line in stdout.strip().splitlines() if line.strip()]

    assert stderr == "", f"Ошибка выполнения: {stderr}"
    assert len(actual_lines) > 0, "Нет вывода программы"

    combined = " ".join(actual_lines)  # соединяем все строки в одну для проверки

    # проверяем оба варианта: одна строка или две
    option1 = f"Содержимое файла: {EXPECTED_CONTENT}"
    option2 = len(actual_lines) >= 2 and actual_lines[0] == "Содержимое файла:" and actual_lines[1] == EXPECTED_CONTENT

    assert combined == option1 or option2, f"Вывод программы не соответствует ожидаемому.\nОжидалось: '{EXPECTED_CONTENT}'\nПолучено: '{combined}'"
