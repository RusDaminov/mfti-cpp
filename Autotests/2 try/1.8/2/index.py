status = int(input("HTTP статус: "))

match status:
    case 200:
        message = "OK"
    case 404:
        message = "Not Found"
    case 500:
        message = "Server Error"
    case _:
        message = "Unknown Status"

print(f"{status}: {message}")
