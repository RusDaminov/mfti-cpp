from index import func


def test_1():
    assert min(['сапфир', 'алмаз', 'изумруд', 'рубин'], key=func) == 'алмаз'

def test_2():
    assert min(["apple", "lemon", "pear", "avocado", "kiwi"], key=func) == "pear"

def test_3():
    assert min(["ежели", "присутствуют", "несколько", "строк", "одинаковой", "длины", "выведите", "первое", "вхождение"], key=func) == "ежели"

