def Selection_Sort(marks):
    for i in range(len(marks)):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j
        # Swap the minimum element with the first element
        marks[i], marks[min_idx] = marks[min_idx], marks[i]
    
    print("Marks of students after performing Selection Sort on the list:")
    for mark in marks:
        print(mark)

def Bubble_Sort(marks):
    n = len(marks)
    # Traverse through all array elements
    for i in range(n - 1):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]
    
    print("Marks of students after performing Bubble Sort on the list:")
    for mark in marks:
        print(mark)

def top_five_marks(marks):
    sorted_marks = sorted(marks, reverse=True)
    print("Top 5 marks are:")
    for mark in sorted_marks[:5]:
        print(mark)

# Main program
marks = []
n = int(input("Enter number of students whose marks are to be displayed: "))
print("Enter marks for", n, "students (Press ENTER after every student's marks): ")
for _ in range(n):
    ele = int(input())
    marks.append(ele)

print("The marks of", n, "students are:")
print(marks)

while True:
    print("\n---------------MENU---------------")
    print("1. Selection Sort of the marks")
    print("2. Bubble Sort of the marks")
    
    ch = int(input("\nEnter your choice: "))
    
    if ch == 1:
        Selection_Sort(marks)
        display = input("\nDo you want to display top five marks from the list (yes/no): ")
        if display.lower() == 'yes':
            top_five_marks(marks)
        else:
            print("\nSorting completed!")
    
    elif ch == 2:
        Bubble_Sort(marks)
        display = input("\nDo you want to display top five marks from the list (yes/no): ")
        if display.lower() == 'yes':
            top_five_marks(marks)
        else:
            print("\nSorting completed!")
