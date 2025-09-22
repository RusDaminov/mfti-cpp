import subprocess

FILENAME = "index.py"

CASES = [
    # Варианты с большой буквой
    ("0\nC\n", ["0.0C = 32.0F"]),
    ("32\nF\n", ["32.0F = 0.0C"]),
    ("100\nX\n", ["Ошибка: выберите C или F"]),

    # Варианты с маленькой буквой
    ("0\nc\n", ["0.0C = 32.0F"]),
    ("32\nf\n", ["32.0F = 0.0C"]),
    ("100\nx\n", ["Ошибка: выберите C или F"]),
]

def run_io(stdin: str):
    process = subprocess.Popen(
        ["python3", FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(stdin)
    return stdout.strip().splitlines(), stderr

def test_temperature_converter():
    for inp, expected in CASES:
        actual, stderr = run_io(inp)

        messages = []
        all_good = True

        for i, exp in enumerate(expected, start=1):
            if i <= len(actual) and actual[i-1] == exp:
                messages.append(f"✅ Строка {i} верна: {exp}")
            else:
                messages.append(f"❌ Строка {i} не совпадает. Ожидалось: {exp}, Получено: {actual[i-1] if i <= len(actual) else '---'}")
                all_good = False

        assert stderr == "", f"Ошибка выполнения: {stderr}"
        if not all_good:
            raise AssertionError("\nРазбор вывода программы:\n\n" + "\n".join(messages))
