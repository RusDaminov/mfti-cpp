import subprocess

FILENAME = "index.py"

EXPECTED_OUTPUT = """25
-10
19.99
3.141592
Alice
Hello, World!
True
False
['red', 'green', 'blue']
(10.5, 20.3)
{'name': 'John', 'age': 30}
<class 'int'>
<class 'float'>
<class 'str'>
<class 'bool'>
<class 'list'>"""

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

    # Проверяем лишние строки
    for j, act in enumerate(actual_lines):
        if j not in used_indices:
            messages.append(f"❌ Лишняя строка в выводе: {act}")
            all_good = False

    # Проверяем ошибки выполнения
    assert stderr == "", f"Программа завершилась с ошибкой: {stderr}"

    if not all_good:
        full_report = "\n".join(messages)
        raise AssertionError("\nРазбор вывода программы:\n\n" + full_report)
