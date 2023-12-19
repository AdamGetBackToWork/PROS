# This code contains a plenty of hardcodes, of which im aware, yet its not the point of this task to make it as universal as possible, but to showcase
# different function operations.

# Both Task 1 and Task 2 are done within this code, yet are a bit mixed up together to enhance the usability of the programme.

# Making the terminal UI a bit prettier and intuitive
# The user chooses the operation and the numbers/strings
# they want to perform the operation on

print("------------------------------------")
print("---- OPERATION 1:       ADDITION ---")
print("---- OPERATION 2: MULTIPLICATION ---")
print("---- OPERATION 3:     COMPARISON ---")
print("---- OPERATION 4:     ALTER LIST ---")
print("------------------------------------")
op_choice = int(input("Input operation you want to perform [1-4]: "))

# initializing the later called global variable
j = 0

# ---------------------------------------------------------------------------------
# Different functions to choose from - later called by op_choice = operation choice


# function for addition, it accepts any kind of input, but is being tested on intigers and strings
def addition(a, b):
    """This function adds up two input arguments, either a string or an integer!"""
    global j
    j += 1
    addition_result = a + b
    print("The addition equals to: {}; CALL No.: {}".format(addition_result, j))


# function for multiplication, it accepts any kind of input, but is being tested on intigers and strings
def multiplication(a, b):
    """This function multiplies up two input arguments, either a string or an integer!
    In case of integers, simply multiplies them, in case of string, it multiplies it by
    the number later provided by the user"""
    multiplication_result = a * b
    print("The multiplication equals to: {}".format(multiplication_result))


# function for comparison, it accepts any kind of input, but is being tested on intigers and strings
def comparing(a, b):
    """ "This function compares which is greater (or bigger) of two input arguments,
    either a string or an integer!"""

    if isinstance(a, str) and isinstance(b, str):
        if len(a) < len(b):
            print("The length of {} is smaller than {}".format(a, b))
        else:
            print("The length of {} is bigger or equal to {}".format(a, b))
    else:
        if a < b:
            print("The {} is smaller than {}".format(a, b))
        elif a == b:
            print("The {} is equal to {}".format(a, b))
        else:
            print("The {} is bigger than {}".format(a, b))


# function for altering a list, the user firstly chooses which of the two
# lists they want to alter, then chooses what they want to change to,
# and where in the list they want to make this change!
# It prints the default chosen list and then the altered version
def alter_list(some_list: list, index, new_value):
    """This function lets the user alter the chosen predefined list, user
    chooses desired list, index of change and what to change to"""
    print(some_list)
    some_list[index] = new_value
    print(some_list)


# Typical for structural programming, switch case structure, wanted to add this to the programme so its easier to use :)
match op_choice:
    # First case, adding up the input, testing for intiger and then a string
    case 1:
        X = int(input("Provide first number: "))
        Y = int(input("Provide second number: "))
        Z = str(input("Provide first string: "))
        G = str(input("Provide second string: "))

        addition(X, Y)
        addition(Z, G)
        print(f"Alternate addition, using lambda: {(lambda a, b: a + b)(X, Y)} ")

    # Second case, multiplying the input, testing for intiger and then a string
    case 2:
        X = int(input("Provide first number: "))
        Y = int(input("Provide second number: "))
        Z = str(input("Provide a string: "))
        G = int(
            input("Provide sthe number by which you want to multiply that string: ")
        )

        multiplication(X, Y)
        multiplication(Z, G)

    # Third case, comparing the input, testing for intiger and then a string
    case 3:
        X = int(input("Provide first number: "))
        Y = int(input("Provide second number: "))
        Z = str(input("Provide first string: "))
        G = str(input("Provide second string: "))

        comparing(X, Y)
        comparing(Z, G)

    # Fourth case, altering a specified list
    case 4:
        # Predifinig two lists, im aware of this being a hardcode, but its just an example so yeah...
        fruits = ["apple", "banana", "cherry"]
        cars = ["Audi", "Peugeot", "Fiat"]

        # Mapping the input string to the actual list variable
        lists = {"fruits": fruits, "cars": cars}

        # Taking data from the user, then calling the function to do the specified operation
        list_choice = str(input("Which list you want to change? (fruits/cars): "))
        if list_choice in lists:
            b = str(input("Give me the thing you want to change to: "))
            a = int(input("Give me the index of your change: "))

            # Calling the alter_list function with, lists[list_choice] - from dictionary
            # "lists", choosing the one fitting list_choice,
            # altering with input a and b provided by the user.
            alter_list(lists[list_choice], a, b)
        else:
            print("Invalid list choice.")
