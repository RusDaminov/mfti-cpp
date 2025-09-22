import subprocess

FILENAME = "index.py"

EXPECTED_OUTPUT = """246
4.14
7.3"""

def float_variants(exp: str):
    """Возвращает список допустимых представлений float."""
    try:
        val = float(exp)
    except ValueError:
        return [exp]

    return [
        exp,
        f"{val:.2f}",   # округление до 2 знаков
        str(val)        # полное представление
    ]

def equal_with_variants(exp: str, act: str) -> bool:
    """Проверка строки на совпадение с ожидаемыми вариантами."""
    for variant in float_variants(exp):
        try:
            if abs(float(variant) - float(act)) < 1e-9:
                return True
        except ValueError:
            if act == variant:
                return True
    return False

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
            if exp == act or equal_with_variants(exp, act):
                messages.append(f"✅ Строка {i} верна: {act}")
                used_indices.add(j)
                found = True
                break
        if not found:
            variants = " или ".join(float_variants(exp))
            messages.append(f"❌ Строка {i} не найдена в выводе! Ожидалось: {variants}")
            all_good = False

    # Лишние строки
    for j, act in enumerate(actual_lines):
        if j not in used_indices:
            messages.append(f"❌ Лишняя строка в выводе: {act}")
            all_good = False

    # Ошибки выполнения
    assert stderr == "", f"Программа завершилась с ошибкой: {stderr}"

    if not all_good:
        full_report = "\n".join(messages)
        raise AssertionError("\nРазбор вывода программы:\n\n" + full_report)
