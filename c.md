# C Programming — Andhra University 1st Year 1st Semester
## Exam Prep Guide with Answers

---

## SECTION A: Short Answer Questions

### 1. What is a variable? What are data types in C?
A variable is a named memory location used to store a value that can change during program execution.

Basic data types in C:
- `int` — integers (e.g., `int a = 10;`)
- `float` — single-precision decimal (e.g., `float b = 3.14;`)
- `double` — double-precision decimal
- `char` — single character (e.g., `char c = 'A';`)
- `void` — no value

### 2. Difference between `while` and `do-while`
| while | do-while |
|---|---|
| Condition checked before loop body executes | Condition checked after loop body executes |
| Loop body may run 0 times | Loop body runs at least once |
| `while(cond) { ... }` | `do { ... } while(cond);` |

### 3. Difference between call by value and call by reference
- **Call by value**: A copy of the actual argument is passed. Changes inside the function do NOT affect the original variable.
- **Call by reference**: The address of the actual argument is passed (using pointers). Changes inside the function DO affect the original variable.

### 4. Difference between array and pointer
| Array | Pointer |
|---|---|
| Fixed-size, allocated at compile time | Can point to any memory, allocated at compile or run time |
| Cannot be reassigned to point elsewhere | Can be reassigned |
| `sizeof(array)` gives total size | `sizeof(pointer)` gives pointer size (usually 4 or 8 bytes) |

### 5. Difference between structure and union
| Structure | Union |
|---|---|
| Each member has its own memory | All members share the same memory |
| Size = sum of all members | Size = size of the largest member |
| All members can hold values simultaneously | Only one member holds a valid value at a time |

### 6. Format specifiers
`%d` (int), `%f` (float), `%lf` (double), `%c` (char), `%s` (string), `%u` (unsigned int), `%x` (hexadecimal), `%o` (octal), `%p` (pointer)

### 7. Escape sequences
`\n` (newline), `\t` (tab), `\\` (backslash), `\'` (single quote), `\"` (double quote), `\0` (null character), `\b` (backspace)

### 8. Storage classes in C
- `auto` — default, local scope, automatic storage
- `static` — retains value between function calls
- `extern` — declared in another file/scope, global lifetime
- `register` — suggests storing variable in a CPU register for fast access

### 9. What is a pointer?
A pointer is a variable that stores the memory address of another variable.
```c
int a = 10;
int *p = &a;   // p holds address of a
printf("%d", *p); // prints value at that address, i.e., 10
```

### 10. What is recursion?
A function calling itself directly or indirectly to solve a problem by breaking it into smaller sub-problems. Requires a base case to terminate.

### 11. What are header files?
Files containing function declarations and macro definitions, included using `#include`. Example: `stdio.h` (input/output functions), `stdlib.h` (memory allocation, conversions), `string.h` (string functions), `math.h` (math functions).

### 12. What are preprocessor directives?
Instructions processed before compilation, starting with `#`. Examples: `#include`, `#define`, `#ifdef`, `#ifndef`, `#pragma`.

---

## SECTION B: Program-Based Questions

### 1. Check if a number is prime
```c
#include <stdio.h>
int main() {
    int n, i, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) isPrime = 0;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime)
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}
```

### 2. Check if a number is a palindrome
```c
#include <stdio.h>
int main() {
    int n, original, reversed = 0, remainder;
    printf("Enter a number: ");
    scanf("%d", &n);
    original = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        printf("%d is a palindrome\n", original);
    else
        printf("%d is not a palindrome\n", original);
    return 0;
}
```

### 3. Check if a number is an Armstrong number
(A number equal to the sum of its own digits each raised to the power of the number of digits, e.g., 153 = 1³+5³+3³)
```c
#include <stdio.h>
#include <math.h>
int main() {
    int n, original, remainder, digits = 0;
    double result = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    original = n;

    for (; original != 0; digits++)
        original /= 10;

    original = n;
    for (; original != 0; original /= 10) {
        remainder = original % 10;
        result += pow(remainder, digits);
    }

    if ((int)result == n)
        printf("%d is an Armstrong number\n", n);
    else
        printf("%d is not an Armstrong number\n", n);
    return 0;
}
```

### 4. Fibonacci series (first n terms)
```c
#include <stdio.h>
int main() {
    int n, i, t1 = 0, t2 = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    return 0;
}
```

### 5. Bubble sort
```c
#include <stdio.h>
int main() {
    int arr[100], n, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```

### 6. Linear search
```c
#include <stdio.h>
int main() {
    int arr[100], n, key, i, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Not found\n");
    return 0;
}
```

### 7. Binary search (array must be sorted)
```c
#include <stdio.h>
int main() {
    int arr[100], n, key, low, high, mid, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]); // assume sorted input
    printf("Enter key to search: ");
    scanf("%d", &key);

    low = 0; high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Found at index %d\n", mid);
            return 0;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Not found\n");
    return 0;
}
```

### 8. Sum, max, min of array elements
```c
#include <stdio.h>
int main() {
    int arr[100], n, i, sum = 0, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    max = min = arr[0];
    for (i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Sum = %d, Max = %d, Min = %d\n", sum, max, min);
    return 0;
}
```

### 9. Matrix addition
```c
#include <stdio.h>
int main() {
    int a[10][10], b[10][10], c[10][10], r, col, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &col);

    printf("Enter first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("Sum matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < col; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
```

### 10. Matrix multiplication
```c
#include <stdio.h>
int main() {
    int a[10][10], b[10][10], c[10][10] = {0};
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Multiplication not possible\n");
        return 0;
    }

    printf("Enter first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];

    printf("Product matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
```

### 11. Matrix transpose
```c
#include <stdio.h>
int main() {
    int a[10][10], t[10][10], r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}
```

### 12. String length without library function
```c
#include <stdio.h>
int main() {
    char str[100];
    int length = 0, i;
    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        length++;

    printf("Length = %d\n", length);
    return 0;
}
```

### 13. String reverse without library function
```c
#include <stdio.h>
#include <string.h>
int main() {
    char str[100], rev[100];
    int len, i, j;
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str); // or compute manually as above
    for (i = len - 1, j = 0; i >= 0; i--, j++)
        rev[j] = str[i];
    rev[j] = '\0';

    printf("Reversed string: %s\n", rev);
    return 0;
}
```

### 14. String palindrome check without library function
```c
#include <stdio.h>
int main() {
    char str[100];
    int i, j, len = 0, isPalindrome = 1;
    printf("Enter a string: ");
    scanf("%s", str);

    for (len = 0; str[len] != '\0'; len++); // find length

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}
```

### 15. Structure example — student record
```c
#include <stdio.h>
struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s1;
    printf("Enter name, roll, marks: ");
    scanf("%s %d %f", s1.name, &s1.roll, &s1.marks);

    printf("Name: %s\nRoll: %d\nMarks: %.2f\n", s1.name, s1.roll, s1.marks);
    return 0;
}
```

---

## SECTION C: Long/Essay Answer Questions

### 1. Control structures with examples (if-else, switch, loops)
**if-else**: Executes one block of code if a condition is true, another if false.
```c
if (a > b)
    printf("a is greater");
else
    printf("b is greater");
```

**switch**: Selects one of many code blocks to execute based on a value.
```c
switch (choice) {
    case 1: printf("One"); break;
    case 2: printf("Two"); break;
    default: printf("Invalid");
}
```

**Loops**: `for` (fixed number of iterations), `while` (condition-checked before), `do-while` (condition-checked after, runs at least once). Used for repeating a block of statements.

### 2. Arrays in detail (1D and 2D) with a program
An array is a collection of elements of the same data type stored in contiguous memory locations, accessed using an index starting at 0.

- **1D array**: `int arr[5];` — a single row of elements.
- **2D array**: `int arr[3][4];` — arranged in rows and columns, useful for matrices.

Example combining both concepts is shown in the matrix addition/transpose programs above.

### 3. Pointers in depth
A pointer stores the address of a variable. Key operations:
- `&` — address-of operator
- `*` — dereference operator (access value at address)

**Pointer arithmetic**: Incrementing a pointer moves it forward by the size of the data type it points to.
```c
int arr[5] = {10,20,30,40,50};
int *p = arr;
printf("%d", *(p+2)); // prints 30
```

**Pointer to array**: `int (*p)[5] = &arr;` — points to the whole array, not a single element.

**Pointer to function**: Stores the address of a function, useful for callbacks.
```c
int add(int a, int b) { return a + b; }
int main() {
    int (*fp)(int, int) = add;
    printf("%d", fp(3, 4)); // prints 7
    return 0;
}
```

### 4. Functions — types, recursion, call by value/reference
**Types**: functions with/without arguments, with/without return values.

**Call by value example:**
```c
void modify(int x) { x = x + 10; }
int main() {
    int a = 5;
    modify(a);
    printf("%d", a); // prints 5, unchanged
}
```

**Call by reference example:**
```c
void modify(int *x) { *x = *x + 10; }
int main() {
    int a = 5;
    modify(&a);
    printf("%d", a); // prints 15, changed
}
```

**Recursion example (factorial):**
```c
int factorial(int n) {
    if (n == 0) return 1;      // base case
    return n * factorial(n-1); // recursive case
}
```

### 5. Structures and unions — nested structures, array of structures
```c
struct Address {
    char city[30];
    int pincode;
};

struct Student {
    char name[50];
    struct Address addr;  // nested structure
};

struct Student students[50]; // array of structures
```

### 6. File handling
Basic file operations use `FILE *`, `fopen()`, `fclose()`, and read/write functions.

Modes: `"r"` (read), `"w"` (write, overwrites), `"a"` (append), `"r+"`, `"w+"`, `"a+"` (read+write variants)

```c
#include <stdio.h>
int main() {
    FILE *fp;
    char data[100];

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fp, "Hello, file!\n");
    fclose(fp);

    fp = fopen("data.txt", "r");
    fgets(data, 100, fp);
    printf("Read: %s", data);
    fclose(fp);
    return 0;
}
```

### 7. Dynamic memory allocation
`malloc()`, `calloc()`, `realloc()`, `free()` from `stdlib.h`.

- `malloc(size)` — allocates uninitialized memory
- `calloc(n, size)` — allocates and zero-initializes memory for `n` elements
- `realloc(ptr, newsize)` — resizes previously allocated memory
- `free(ptr)` — releases allocated memory

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, *arr;
    printf("Enter size: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) arr[i] = i + 1;
    for (i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}
```

---

## Common Standalone Programs

### Swap two numbers (using a third variable)
```c
int temp = a;
a = b;
b = temp;
```

### Swap two numbers (without a third variable)
```c
a = a + b;
b = a - b;
a = a - b;
```

### Swap two numbers using pointers
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### Factorial (iterative)
```c
int fact = 1;
for (int i = 1; i <= n; i++) fact *= i;
```

### GCD of two numbers (Euclidean algorithm)
```c
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```

### LCM of two numbers
```c
int lcm(int a, int b) {
    int g = gcd(a, b);
    return (a * b) / g;
}
```

---

## Additional Frequently Asked Topics

### Operators in C
- **Arithmetic**: `+ - * / %`
- **Relational**: `> < >= <= == !=`
- **Logical**: `&& || !`
- **Bitwise**: `& | ^ ~ << >>`
- **Assignment**: `= += -= *= /= %=`
- **Ternary (conditional)**: `condition ? value_if_true : value_if_false`
- **Increment/Decrement**: `++ --` (pre and post)

Example question: "Explain operator precedence and associativity with an example."
```c
int result = 10 + 5 * 2;   // * has higher precedence than +, result = 20
```

### Type conversion and type casting
- **Implicit conversion**: Compiler automatically converts one type to another (e.g., `int` to `float` during arithmetic).
- **Explicit conversion (casting)**: Programmer forces a conversion.
```c
int a = 5, b = 2;
float result = (float)a / b;  // explicit cast, result = 2.5
```

### `break`, `continue`, and `goto`
- `break` — exits the nearest enclosing loop or switch immediately.
- `continue` — skips the rest of the current loop iteration and moves to the next.
- `goto` — jumps to a labeled statement (rarely recommended, but asked theoretically).

### `typedef` and enumerations
```c
typedef unsigned int uint;
uint age = 25;

enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};
enum Day today = WED;  // today = 2
```

### Command line arguments
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("Argument %d: %s\n", i, argv[i]);
    return 0;
}
```

### Commonly used string library functions (`string.h`)
`strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `strrev()`, `strlwr()`, `strupr()`

```c
#include <stdio.h>
#include <string.h>
int main() {
    char s1[50] = "Hello", s2[50] = "World";
    printf("Length: %d\n", strlen(s1));
    strcat(s1, s2);
    printf("Concatenated: %s\n", s1);
    printf("Compare: %d\n", strcmp(s1, s2));
    return 0;
}
```

### Character-testing functions (`ctype.h`)
`isalpha()`, `isdigit()`, `isupper()`, `islower()`, `toupper()`, `tolower()`

### Selection sort
```c
#include <stdio.h>
int main() {
    int arr[100], n, i, j, min_idx, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```

### Insertion sort
```c
#include <stdio.h>
int main() {
    int arr[100], n, i, j, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
```

### Check leap year
```c
#include <stdio.h>
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
    return 0;
}
```

### Count vowels and consonants in a string
```c
#include <stdio.h>
int main() {
    char str[100];
    int i, vowels = 0, consonants = 0;
    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            vowels++;
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            consonants++;
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}
```

### Multiplication table
```c
#include <stdio.h>
int main() {
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);
    return 0;
}
```

### Pattern printing programs (very common in AU papers)

**Right-angled triangle of stars**
```c
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++)
        printf("* ");
    printf("\n");
}
```
Output:
```
*
* *
* * *
* * * *
* * * * *
```

**Pyramid pattern**
```c
int n = 5;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) printf(" ");
    for (int j = 1; j <= 2*i-1; j++) printf("*");
    printf("\n");
}
```

**Number pattern**
```c
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++)
        printf("%d ", j);
    printf("\n");
}
```
Output:
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

### Union example
```c
#include <stdio.h>
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;  // overwrites data.i since they share memory
    printf("data.f: %f\n", data.f);
    return 0;
}
```

### Self-referential structures (intro to linked lists)
Often asked as a theory question introducing next semester's data structures topic.
```c
struct Node {
    int data;
    struct Node *next;  // pointer to same struct type
};
```

---

## Extra Topics Found in Actual AU Papers

### Decimal to Hexadecimal conversion program
```c
#include <stdio.h>
int main() {
    long int decimalNum;
    int remainder, i = 1, j;
    long int hexadecimalNum[100];

    printf("Enter a decimal number: ");
    scanf("%ld", &decimalNum);

    j = decimalNum;
    while (j != 0) {
        remainder = j % 16;
        if (remainder < 10)
            hexadecimalNum[i++] = remainder;
        else
            hexadecimalNum[i++] = remainder + 55; // store as ASCII for A-F
        j /= 16;
    }

    printf("Equivalent hexadecimal value: ");
    for (j = i - 1; j > 0; j--) {
        if (hexadecimalNum[j] < 10)
            printf("%ld", hexadecimalNum[j]);
        else
            printf("%c", hexadecimalNum[j]); // print A-F as characters
    }
    printf("\n");
    return 0;
}
```
**Logic:** Repeatedly divide the number by 16. Each remainder is a hex digit (0-9 stays as-is, 10-15 becomes A-F). Store the digits and print them in reverse order since they're generated least-significant-digit first.

### What is an Abstract Data Type (ADT)?
> An Abstract Data Type is a data type defined by its **behavior (operations)** from the point of view of a user, without specifying **how those operations are implemented** internally.

In simple words: it tells you *what* a data structure can do, not *how* it does it. The implementation details are hidden from the user.

**Examples of ADTs:** Stack (push, pop, peek), Queue (enqueue, dequeue), List, Tree.

**Exam-ready example — Stack as an ADT:**
> A Stack is an ADT that follows the LIFO (Last In, First Out) principle. It supports operations like `push()` (insert an element), `pop()` (remove the top element), and `peek()` (view the top element) — without the user needing to know whether it's implemented using an array or a linked list underneath.

**Key theoretical point often asked:**
> ADTs separate the **specification** of a data structure (what operations it supports) from its **implementation** (how it's coded), which promotes modularity and lets the implementation be changed without affecting code that uses it.

This ADT concept is a bridge topic — it previews what you'll study in detail next semester in Data Structures.

---

## Numerical Methods (paired with C Programming in the AU 1-1 paper)

Andhra University's 1st semester paper for this subject combines **C Programming** with an introduction to **Numerical Methods** — techniques to find approximate solutions to equations that are hard or impossible to solve algebraically.

### Bisection Method
Used to find a root of an equation `f(x) = 0` by repeatedly halving an interval `[a, b]` where the function changes sign (i.e., `f(a)` and `f(b)` have opposite signs).

**Theory:**
1. Choose `a` and `b` such that `f(a) * f(b) < 0` (opposite signs — guarantees a root lies between them).
2. Compute midpoint `c = (a + b) / 2`.
3. If `f(c) == 0`, `c` is the root.
4. Otherwise, replace `a` or `b` with `c` depending on which side the sign change is on.
5. Repeat until the interval is sufficiently small (within a tolerance).

**C program:**
```c
#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 1;  // example equation: x^3 - x - 1 = 0
}

int main() {
    float a, b, c;
    int iteration = 0;

    printf("Enter interval [a, b]: ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval, f(a) and f(b) must have opposite signs\n");
        return 0;
    }

    do {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        iteration++;
    } while (fabs(f(c)) > 0.0001 && iteration < 100);

    printf("Root = %.4f (found in %d iterations)\n", c, iteration);
    return 0;
}
```

### Newton-Raphson Method
Finds a root faster than bisection by using the function's derivative to jump closer to the root each time.

**Formula:**
```
x1 = x0 - f(x0) / f'(x0)
```
Repeat, replacing `x0` with `x1`, until the difference between successive values is small enough.

**C program:**
```c
#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 1;   // example equation
}

float fDerivative(float x) {
    return 3*x*x - 1;       // derivative of x^3 - x - 1
}

int main() {
    float x0, x1;
    int iteration = 0;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    do {
        x1 = x0 - f(x0) / fDerivative(x0);
        x0 = x1;
        iteration++;
    } while (fabs(f(x1)) > 0.0001 && iteration < 100);

    printf("Root = %.4f (found in %d iterations)\n", x1, iteration);
    return 0;
}
```

**Difference between the two (common comparison question):**

| Bisection Method | Newton-Raphson Method |
|---|---|
| Needs two initial guesses `a, b` with opposite signs | Needs only one initial guess |
| Slower (linear convergence) | Faster (quadratic convergence) |
| Always converges if interval is valid | May fail to converge if derivative is zero or a bad guess is chosen |
| Doesn't need derivative | Requires calculating the derivative |

### Trapezoidal Rule (numerical integration — sometimes also asked)
Approximates the area under a curve by dividing it into trapezoids instead of rectangles.

**Formula:**
```
∫f(x)dx ≈ (h/2) * [f(x0) + f(xn) + 2*(f(x1)+f(x2)+...+f(xn-1))]
```
where `h = (b - a) / n` is the width of each sub-interval.

```c
#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x;  // example function
}

int main() {
    float a, b, h, sum = 0, integral;
    int n, i;

    printf("Enter lower limit, upper limit, number of intervals: ");
    scanf("%f %f %d", &a, &b, &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
        sum += 2 * f(a + i * h);

    integral = (h / 2) * sum;
    printf("Integral value = %.4f\n", integral);
    return 0;
}
```

---

## Study Tips
- Practice writing the code by hand — most AU exams require handwritten programs.
- Know the **logic** well enough to explain with a flowchart, since Section C often asks for diagrams alongside code.
- Be comfortable tracing through loops and recursive calls step-by-step; "dry run" questions are common in vivas and sometimes in exams.
- For structures/unions/pointers, expect at least one detailed question with a working program.
