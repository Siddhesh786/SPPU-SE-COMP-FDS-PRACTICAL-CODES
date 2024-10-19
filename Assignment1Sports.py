def remove_duplicates(lst):
    result = []
    for item in lst:
        if item not in result:
            result.append(item)
    return result

def both_cricket_badminton(cricket, badminton):
    both = []
    for student in cricket:
        if student in badminton and student not in both:
            both.append(student)
    return both

def either_cricket_badminton_not_both(cricket, badminton):
    either = []
    for student in cricket:
        if student not in badminton and student not in either:
            either.append(student)
    for student in badminton:
        if student not in cricket and student not in either:
            either.append(student)
    return either

def neither_cricket_nor_badminton(football, cricket, badminton):
    neither = 0
    for student in football:
        if student not in cricket and student not in badminton:
            neither += 1
    return neither

def cricket_football_not_badminton(cricket, football, badminton):
    count = 0
    for student in cricket:
        if student in football and student not in badminton:
            count += 1
    return count

def main():
    cricket = []
    badminton = []
    football = []

    n = int(input("\nEnter number of students playing cricket: "))
    for _ in range(n):
        name = input("Enter student name: ")
        cricket.append(name)
    cricket = remove_duplicates(cricket)
    print("\nFinal list for cricket:", cricket)

    m = int(input("\nEnter number of students playing badminton: "))
    for _ in range(m):
        name = input("Enter student name: ")
        badminton.append(name)
    badminton = remove_duplicates(badminton)
    print("\nFinal list for badminton:", badminton)

    p = int(input("\nEnter number of students playing football: "))
    for _ in range(p):
        name = input("Enter student name: ")
        football.append(name)
    football = remove_duplicates(football)
    print("\nFinal list for football:", football)

    print("\nStudents playing both cricket and badminton:")
    print(both_cricket_badminton(cricket, badminton))

    print("\nStudents playing either cricket or badminton but not both:")
    print(either_cricket_badminton_not_both(cricket, badminton))

    print("\nNumber of students playing neither cricket nor badminton:")
    print(neither_cricket_nor_badminton(football, cricket, badminton))

    print("\nNumber of students playing cricket and football but not badminton:")
    print(cricket_football_not_badminton(cricket, football, badminton))

if __name__ == "__main__":
    main()
