from index import the_longest


def test_1():
    assert the_longest("task.txt") == ['the_longest,', 'максимальной', 'непробельные']

def test_2():
    assert the_longest("Pasternak.md") == ['Крестообразно.']

def test_3():
    assert the_longest("Kipling.txt") == ['Великодушней', 'воссоздавать']

def test_4():
    assert the_longest("VariableUsesOfKg.md") == ['sustainability.']
