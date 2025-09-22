import subprocess
import pytest

FILENAME = "index.py"

def check_for_unsafe_code(file_path):
    """
    Небольшая проверка кода на нехорошие действия
    """
    with open(file_path, 'r') as file:
        code = file.read()

    sec_alert_msg = "Security: в данной задаче можно обойтись без этого :)"
    assert "import" not in code, sec_alert_msg
    assert "eval" not in code, sec_alert_msg
    assert "exec" not in code, sec_alert_msg
    assert "subprocess" not in code, sec_alert_msg


# подсовываем входные и выходные данные в виде кортежа
@pytest.mark.parametrize("input_values, expected_output", [
    ("3.5\n5\n2.5\n", "11.0"), ("1.8\n1.5\n2\n", "5.3"), ("25201\n23467\n27931\n", "76599.0")
])
def test_add(input_values, expected_output):

    check_for_unsafe_code(FILENAME)

    # Simulate input by providing it through stdin
    process = subprocess.Popen(
        ['python3', FILENAME],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    # Provide input values
    stdout, stderr = process.communicate(input_values)

    # Check the output
    assert stdout.strip() == expected_output
    assert stderr == ''

