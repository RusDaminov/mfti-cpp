class InsufficientFundsError(Exception):
    pass

class BankAccount:
    def __init__(self, balance=100):
        self.balance = balance
    
    def deposit(self, amount):
        if amount <= 0:
            raise ValueError("Сумма должна быть положительной")
        self.balance += amount
        print(f"Баланс: {self.balance}")
    
    def withdraw(self, amount):
        if amount <= 0:
            raise ValueError("Сумма должна быть положительной")
        if amount > self.balance:
            raise InsufficientFundsError("Недостаточно средств на счете")
        self.balance -= amount
        print(f"Баланс: {self.balance}")

account = BankAccount()

try:
    action = input("Выберите действие (deposit/withdraw): ").lower()
    amount = float(input("Введите сумму: "))
    
    if action == "deposit":
        account.deposit(amount)
    elif action == "withdraw":
        account.withdraw(amount)
    else:
        print("Ошибка: неизвестное действие")
except InsufficientFundsError as e:
    print(f"Ошибка: {e}")
except ValueError as e:
    print(f"Ошибка значения: {e}")
