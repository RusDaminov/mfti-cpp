class Password:
    def __init__(self, passwd=None):
        self.passwd = passwd

    def low_reg(self):
        flag = False
        for _ in self.passwd:
            if _ in "abcdefghijklmnopqrstuvwxyz":
                flag = True
                break
        return flag

    def high_reg(self):
        flag = False
        for _ in self.passwd:
            if _ in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
                flag = True
                break
        return flag

    def special(self):
        flag = False
        for _ in self.passwd:
            if _ in "!@#$%^&*":
                flag = True
                break
        return flag

    def number(self):
        flag = False
        for _ in self.passwd:
            if _.isdigit():
                flag = True
                break
        return flag

    def length(self):
        flag = True if 6 <= len(self.passwd) <= 12 else False
        return flag

    def is_valid(self):
        return self.low_reg() and self.high_reg() and self.number() and self.special() and self.length()

    def message(self):
        if self.is_valid():
            return "Ваш пароль полностью соответствует всем критериям"

        mes = "Ваш пароль не соответствуем следующим критериям:"
        if not self.low_reg():
            mes = mes + " минимум 1 буква латинского алфавита в нижнем регистре,"
        if not self.high_reg():
            mes = mes + " минимум 1 буква латинского алфавита в верхнем регистре,"
        if not self.number():
            mes = mes + " минимум одна цифра от 0 до 9,"
        if not self.special():
            mes = mes + " минимум 1 специальный символ,"
        if not self.length():
            mes = mes + " длина пароля от 6 до 12 символов,"

        return mes[:-1]
