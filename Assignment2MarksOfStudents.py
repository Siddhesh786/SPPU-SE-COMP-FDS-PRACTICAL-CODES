def enterval(n):
    marks = []
    for _ in range(n):
        while True:
            m = input("Enter marks of student, enter 'AB' if absent: ").strip().upper()
            if m == 'AB':
                marks.append(m)
                break
            try:
                u = int(m)
                if 0 <= u <= 50:
                    marks.append(u)
                    break
                else:
                    print("Marks should be between 0 and 50.")
            except ValueError:
                print("Invalid input. Enter a number between 0 and 50 or 'AB'.")
    print("\nFinal list of marks:")
    print(marks)
    return marks

def avg(marks):
    valid_marks = [mark for mark in marks if isinstance(mark, int)]
    if valid_marks:
        average = sum(valid_marks) // len(valid_marks)
        print(f"Average score of class is {average}.")
    else:
        print("No valid scores to calculate average.")
    print()

def score(marks):
    valid_marks = [mark for mark in marks if isinstance(mark, int)]
    if valid_marks:
        high = max(valid_marks)
        low = min(valid_marks)
        print(f"Highest score is {high}.")
        print(f"Lowest score is {low}.")
    else:
        print("No valid scores to determine highest or lowest.")
    print()

def abst(marks):
    count = sum(1 for mark in marks if mark == 'AB')
    if count == 0:
        print("No student was absent for the test.")
    else:
        print(f"{count} student(s) were absent for the test.")
    print()

def highfreq(marks):
    freq = {}
    for mark in marks:
        if isinstance(mark, int):
            freq[mark] = freq.get(mark, 0) + 1

    if freq:
        most_frequent_mark = max(freq, key=freq.get)
        print(f"Mark with highest frequency is {most_frequent_mark}.")
    else:
        print("No valid scores to determine frequency.")
    print()

def main():
    n = int(input("Enter number of students: "))
    marks = enterval(n)
    
    while True:
        print("\nChoose an option:")
        print("1. Average score of class")
        print("2. Highest and lowest score of class")
        print("3. Number of absent students")
        print("4. Mark with highest frequency")
        
        try:
            choice = int(input("\nEnter your choice: "))
            if choice == 1:
                avg(marks)
            elif choice == 2:
                score(marks)
            elif choice == 3:
                abst(marks)
            elif choice == 4:
                highfreq(marks)
            else:
                print("Invalid choice.")
        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()
