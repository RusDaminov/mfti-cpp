import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("10 20 30 40\n2", "30"),
    ("a b c\n5", "Ошибка: индекс вне диапазона"),
    ("1 2 3\nx", "Ошибка: индекс должен быть целым числом"),
]

def test_get_element():
    for input_data, expected in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=input_data)
        actual_lines = [line.strip() for line in stdout.strip().splitlines() if line.strip()]

        # Проверяем ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # В выводе должна быть ровно одна строка
        assert len(actual_lines) == 1, f"Ожидалась одна строка, получено: {actual_lines}"

        actual = actual_lines[0]
        assert actual == expected, f"Для ввода '{input_data}' ожидалось: '{expected}', получено: '{actual}'"
