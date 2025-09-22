from hexlet.test import expect_output


def test(capsys):
    expected = """Белая берёза
Под моим окном
Принакрылась снегом,
Точно серебром.
С. Есенин"""
    expect_output(capsys, expected)
