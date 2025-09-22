from hexlet.test import expect_output

def test(capsys):
    expected = """25
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
    expect_output(capsys, expected)
