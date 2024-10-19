def input_percentage():
    number_of_students = int(input("Enter the number of Students: "))
    return [float(input(f"Enter the percentage of Student {i + 1}: ")) for i in range(number_of_students)]

def print_percentage(perc):
    for p in perc:
        print(p)

def partition(perc, start, end):
    pivot = perc[start]
    lower = start + 1
    upper = end
    while True:
        while lower <= upper and perc[lower] <= pivot:
            lower += 1
        while lower <= upper and perc[upper] >= pivot:
            upper -= 1
        if lower <= upper:
            perc[lower], perc[upper] = perc[upper], perc[lower]
        else:
            break
    perc[start], perc[upper] = perc[upper], perc[start]
    return upper

def quick_sort(perc, start, end):
    if start < end:
        p = partition(perc, start, end)
        quick_sort(perc, start, p - 1)
        quick_sort(perc, p + 1, end)

def display_top_five(perc):
    print("Top five percentages are:")
    for p in sorted(perc, reverse=True)[:5]:
        print(p)

unsorted_percentage = []

while True:
    print("\n--------------------MENU--------------------")
    print("1. Enter the percentage of students")
    print("2. Display the percentages of students")
    print("3. Perform Quick Sort on the data")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        unsorted_percentage = input_percentage()
    elif choice == 2:
        print("Percentages of students are:")
        print_percentage(unsorted_percentage)
    elif choice == 3:
        quick_sort(unsorted_percentage, 0, len(unsorted_percentage) - 1)
        print("Percentages of students after performing Quick Sort:")
        print_percentage(unsorted_percentage)
        if input("Do you want to display the Top 5 percentages of students (yes/no): ").strip().lower() == 'yes':
            display_top_five(unsorted_percentage)
    else:
        print("Invalid Choice!")
