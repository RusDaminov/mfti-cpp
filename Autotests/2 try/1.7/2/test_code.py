import subprocess

FILENAME = "index.py"

CASES = [
    ("50\n1.70\n", ["ИМТ: 17.3, Категория: Недостаток"]),
    ("68\n1.75\n", ["ИМТ: 22.2, Категория: Норма"]),
    ("80\n1.7\n",  ["ИМТ: 27.7, Категория: Избыток"]),
    ("95\n1.65\n", ["ИМТ: 34.9, Категория: Ожирение"]),
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

def test_bmi():
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

        assert stderr == "", f"Ошибка выполнения: {stderr}"
        if not all_good:
            raise AssertionError("\nРазбор вывода программы:\n\n" + "\n".join(messages))
