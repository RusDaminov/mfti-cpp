import subprocess

FILENAME = "index.py"

CASES = [
    ("regular\n", ["Ваша скидка: 5%"]),
    ("silver\n", ["Ваша скидка: 10%"]),
    ("gold\n", ["Ваша скидка: 15%"]),
    ("platinum\n", ["Ваша скидка: 20%"]),
    ("bronze\n", ["Ваша скидка: 0%"]),
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

def test_discount():
    for inp, expected in CASES:
        actual, stderr = run_io(inp)

        messages = []
        all_good = True

        for i, exp in enumerate(expected, start=1):
            if i <= len(actual) and actual[i-1] == exp:
                messages.append(f"✅ Строка {i} верна: {exp}")
            else:
                got = actual[i-1] if i <= len(actual) else "---"
                messages.append(f"❌ Строка {i} не совпадает. Ожидалось: {exp}, Получено: {got}")
                all_good = False

        # Проверка ошибок выполнения
        assert stderr == "", f"Ошибка выполнения программы: {stderr}"

        if not all_good:
            raise AssertionError("\nРазбор вывода программы:\n\n" + "\n".join(messages))
