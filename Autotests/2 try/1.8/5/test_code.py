import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("25C", "25C = 77.0F"),
    ("77F", "77F = 25.0C"),
    ("30K", "Ошибка формата. Используйте например '25C' или '77F'"),
    ("0C", "0C = 32.0F"),
    ("100F", "100F = 37.8C")
]

def test_temperature_conversion():
    for user_input, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=user_input + "\n")
        actual_lines = stdout.strip().splitlines()

        # Проверяем ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # Проверка, что ожидаемая строка присутствует
        if expected_output not in actual_lines:
            raise AssertionError(
                f"\n❌ Для ввода: {user_input}\n"
                f"Ожидалось: {expected_output}\n"
                f"✅ Получено: {actual_lines}"
            )
