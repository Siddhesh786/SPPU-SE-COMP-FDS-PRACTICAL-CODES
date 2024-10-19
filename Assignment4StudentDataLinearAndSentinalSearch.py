def enterval(roll, n):
    """Function to enter roll numbers."""
    for i in range(n):
        while True:
            try:
                m = int(input("Enter roll number: "))
                roll.append(m)
                break
            except ValueError:
                print("Invalid input.")
    print("\nFinal list of roll numbers is: ")
    print(roll)
    print()

def linear(roll, n):
    """Function to perform linear search."""
    print("Linear Search")
    try:
        find = int(input("Enter roll number to be found: "))
        flag = False
        for i in range(n):
            if find == roll[i]:
                print("Student found at index", i)
                flag = True
                break
        if not flag:
            print("Student not found!")
    except ValueError:
        print("Invalid input.")
    print()

def sentinel(roll, n):
    """Function to perform sentinel search."""
    print("Sentinel Search")
    try:
        find = int(input("Enter roll number to be found: "))
        i = 0
        last = roll[n - 1]
        roll[n - 1] = find
        while roll[i] != find:
            i += 1
        roll[n - 1] = last
        if i < n - 1 or roll[n - 1] == find:
            print("Student found at index", i)
        else:
            print("Student not found!")
    except ValueError:
        print("Invalid input.")
    print()

def main():
    """Main function to drive the menu-based operations."""
    n = int(input("Enter number of students: "))
    roll = []
    enterval(roll, n)

    while True:
        print("\n1. Linear Search")
        print("2. Sentinel Search")
        try:
            ch = int(input("\nEnter your choice: "))
            if ch == 1:
                linear(roll, n)
            elif ch == 2:
                sentinel(roll, n)
            else:
                print("Invalid choice!")
        except ValueError:
            print("Invalid input.")

if __name__ == "__main__":
    main()
