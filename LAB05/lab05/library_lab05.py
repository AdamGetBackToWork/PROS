import sqlite3
import os
from terminal_UI_lib import *

connection = sqlite3.connect("students.db")
cursor = connection.cursor()
global clear
clear = lambda: os.system("cls")


# ---- MENU fucntions -------
def disp_welcome():
    clear()
    welcome()

    check = input()
    if check == "":
        clear()
    else:
        exit


def disp_menu():
    clear()
    op_choice = menu()

    clear()
    if op_choice > 0 and op_choice <= 6:
        return op_choice
    else:
        exit


# ----- CREATE fucntion ---------
def create_table():
    cursor.execute(
        "CREATE TABLE students(name TEXT, surname TEXT, age INTEGER, id INTEGER, major TEXT, gpa DOUBLE)"
    )


def input_student(name, surname, age, id, major, gpa):
    cursor.execute(
        " INSERT INTO students (name, surname, age, id, major, gpa) values (?, ?, ?, ?, ?, ?)",
        (name, surname, age, id, major, gpa),
    )


def change_student(what_change, new_value, where_change, old_value):
    query = f"UPDATE students SET {what_change} = ? WHERE {where_change} = ?"
    cursor.execute(query, (new_value, old_value))


def display_student(display_option=None, disp_where=None, disp_equal=None):
    if display_option == "filter":
        query = f"SELECT * FROM students WHERE {disp_where} = ?"
        cursor.execute(query, (disp_equal,))
        output = cursor.fetchall()
        return output
    elif display_option == "all":
        cursor.execute("SELECT * FROM students")
        output = cursor.fetchall()
        return output
    else:
        print("Invalid display option. Please choose 'filter' or 'all'.")


def display_student_by_order(disp_order):
    query = f"SELECT * FROM students ORDER BY {disp_order}"
    cursor.execute(query)
    output = cursor.fetchall()
    print(output)


def remove_student(rem_where, rem_equal):
    query = f"DELETE FROM students WHERE {rem_where} = ?"
    cursor.execute(query, (rem_equal,))


def comparing(a, a_id, b, b_id):
    if a > b:
        return a_id
    elif a < b:
        return b_id
    else:
        return 0


def comparing_students(stud_A, stud_B):
    query = f"SELECT * FROM students WHERE id IN (?, ?)"
    cursor.execute(query, (stud_A, stud_B))
    output = cursor.fetchall()

    if len(output) != 2:
        print("Invalid student IDs provided.")
        return

    a = output[0][-1]
    b = output[1][-1]
    print(output)

    greater_id = comparing(a, stud_A, b, stud_B)
    if greater_id == 0:
        print("Both students have the same GPA, and it's equal to:", a)
    else:
        print("The student with a greater GPA is with id =", greater_id)


def end_option():
    choice = input("Do you want to exit (E) or return to the menu (M)?: ").lower()
    if choice == "e":
        exit()
    elif choice == "m":
        return True
    else:
        print("Invalid choice. Returning to the menu.")
        return True
