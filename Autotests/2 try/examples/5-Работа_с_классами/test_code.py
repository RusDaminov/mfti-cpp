from index import Password


def test_1():
    pwd = Password("Wq")
    assert pwd.passwd == "Wq"
    assert pwd.special() is False
    assert pwd.length() is False
    assert pwd.is_valid() is False


def test_2():
    pwd = Password("qW34!")
    assert pwd.passwd == "qW34!"
    assert pwd.special() is True
    assert pwd.length() is False 
    assert pwd.is_valid() is False

def test_3():
    pwd = Password("!My_pass124")
    assert pwd.passwd == "!My_pass124"
    assert pwd.special() is True
    assert pwd.length() is True
    assert pwd.is_valid() is True
