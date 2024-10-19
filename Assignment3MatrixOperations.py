def display(mat, r, c):
    """Display the matrix."""
    for i in range(r):
        print(mat[i])

def trs(a, r, c):
    """Transpose the matrix."""
    transposed = [[0] * r for _ in range(c)]
    for i in range(r):
        for j in range(c):
            transposed[j][i] = a[i][j]
    print("Transposed matrix is: ")
    display(transposed, c, r)
    print()

def addr(mat1, mat2, r, c):
    """Add two matrices."""
    add = []
    for i in range(r):
        mat = []
        for j in range(c):
            m = mat1[i][j] + mat2[i][j]
            mat.append(m)
        add.append(mat)
    print("Added matrix is: ")
    display(add, r, c)
    print()

def subt(mat1, mat2, r, c):
    """Subtract second matrix from the first matrix."""
    sub = []
    for i in range(r):
        mat = []
        for j in range(c):
            m = mat1[i][j] - mat2[i][j]
            mat.append(m)
        sub.append(mat)
    print("Subtracted matrix is: ")
    display(sub, r, c)
    print()

def mult(mat1, mat2, r, c):
    """Multiply two matrices."""
    mul = [[0] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(c):  # Matrix multiplication rule
                mul[i][j] += mat1[i][k] * mat2[k][j]
    print("Multiplied matrix is: ")
    display(mul, r, c)
    print()

def enterval(mat, r, c):
    """Enter values for the matrix."""
    for i in range(r):
        row = []
        for j in range(c):
            while True:
                try:
                    m = int(input(f"Enter value for matrix element ({i+1}, {j+1}): "))
                    row.append(m)
                    break
                except ValueError:
                    print("Invalid input. Please enter an integer.")
        mat.append(row)
    display(mat, r, c)
    print()

def main():
    """Main function to drive the menu-based matrix operations."""
    r = int(input("Enter number of rows: "))
    c = int(input("Enter number of columns: "))
    mat1 = []
    mat2 = []

    print("\nEnter values for matrix 1: ")
    enterval(mat1, r, c)

    print("Enter values for matrix 2: ")
    enterval(mat2, r, c)

    while True:
        print("\nEnter your choice: ")
        print("1. Addition of matrix")
        print("2. Subtraction of matrix")
        print("3. Multiplication of matrix")
        print("4. Transpose of matrix")

        try:
            ch = int(input("\nEnter your choice: "))
            if ch == 1:
                addr(mat1, mat2, r, c)
            elif ch == 2:
                subt(mat1, mat2, r, c)
            elif ch == 3:
                mult(mat1, mat2, r, c)
            elif ch == 4:
                trs(mat1, r, c)
                trs(mat2, r, c)
            else:
                print("Invalid choice!!")
        except ValueError:
            print("Please enter a valid integer for the choice.")

if __name__ == "__main__":
    main()
