import subprocess

FILENAME = "index.py"

TEST_CASES = [
    (200, "200: OK"),
    (404, "404: Not Found"),
    (500, "500: Server Error"),
    (302, "302: Unknown Status")
]

def test_http_status():
    for code_input, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=f"{code_input}\n")
        actual_lines = stdout.strip().splitlines()

        # Проверка на ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # Проверка вывода
        if expected_output not in actual_lines:
            raise AssertionError(
                f"\n❌ Ожидалось: {expected_output}\n"
                f"✅ Получено: {actual_lines}"
            )
