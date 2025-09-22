import subprocess

FILENAME = "index.py"

TEST_CASES = [
    ("admin", "Уровень доступа: Полный доступ"),
    ("editor", "Уровень доступа: Редактирование"),
    ("viewer", "Уровень доступа: Просмотр"),
    ("guest", "Уровень доступа: Нет доступа")
]

def test_access_levels():
    for role_input, expected_output in TEST_CASES:
        process = subprocess.Popen(
            ['python3', FILENAME],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=role_input + "\n")
        actual_lines = stdout.strip().splitlines()

        # Проверяем ошибки выполнения
        assert stderr == "", f"Ошибка выполнения: {stderr}"

        # Проверка, что ожидаемая строка присутствует
        if expected_output not in actual_lines:
            raise AssertionError(
                f"\n❌ Ожидалось: {expected_output}\n"
                f"✅ Получено: {actual_lines}"
            )
