import subprocess

FILENAME = "index.py"

TEST_CASES = [
    (("circle", 5), "Площадь круга: 78.50"),
    (("rect", 4, 6), "Площадь прямоугольника: 24.00"),
    (("triangle", 3, 4, 5), "Периметр треугольника: 12.00"),
    (("hexagon", 6), "Неизвестная фигура")
]

def test_shapes():
    import ast
    for input_tuple, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        # Передаем кортеж как строку
        stdin_data = str(input_tuple) + "\n"
        stdout, stderr = process.communicate(input=stdin_data)
        actual_lines = stdout.strip().splitlines()

        # Проверка на ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # Проверка наличия нужного вывода
        if expected_output not in actual_lines:
            raise AssertionError(
                f"\n❌ Ожидалось: {expected_output}\n"
                f"✅ Получено: {actual_lines}"
            )
