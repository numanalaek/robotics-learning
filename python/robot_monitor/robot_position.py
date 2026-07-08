x = 0
y = 0

while True:
    command = input("Perintah (w/a/s/d/q): ")

    if command == "w":
        y += 1

    elif command == "s":
        y -= 1

    elif command == "a":
        x -= 1

    elif command == "d":
        x += 1

    elif command == "q":
        break

    print(f"Posisi robot: ({x}, {y})")
