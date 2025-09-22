import subprocess

FILENAME = "index.py"

EXPECTED_OUTPUT = """Alice
10
100"""

def test_output():
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate()
    actual_lines = stdout.strip().splitlines()
    expected_lines = EXPECTED_OUTPUT.splitlines()

    messages = []
    all_good = True
    used_indices = set()

    # Проверяем каждую ожидаемую строку
    for i, exp in enumerate(expected_lines, start=1):
        found = False
        for j, act in enumerate(actual_lines):
            if j in used_indices:
                continue
            if act == exp:
                messages.append(f"✅ Строка {i} верна: {exp}")
                used_indices.add(j)
                found = True
                break
        if not found:
            messages.append(f"❌ Строка {i} не найдена в выводе! Ожидалось: {exp}")
            all_good = False

    # Лишние строки
    for j, act in enumerate(actual_lines):
        if j not in used_indices:
            messages.append(f"❌ Лишняя строка в выводе: {act}")
            all_good = False

    # Проверяем ошибки выполнения
    if stderr:
        messages.append(f"❌ Программа завершилась с ошибкой:\n{stderr}")
        all_good = False

    if not all_good:
        full_report = "\n".join(messages)
        raise AssertionError("\nРазбор вывода программы:\n\n" + full_report)
