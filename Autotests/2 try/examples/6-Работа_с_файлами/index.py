def the_longest(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        longest_word = ""
        for line in lines:
            words = line.split()
            for word in words:
                if len(word) > len(longest_word):
                    longest_word = word
        result = []
        for line in lines:
            words = line.split()
            for word in words:
                if len(word) == len(longest_word):
                    result.append(word)
        return result
