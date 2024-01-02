import sqlite3
import os
from terminal_UI_lib import *
from main import *


connection = sqlite3.connect(":memory:")
cursor = connection.cursor()

create_table()


def test_input_student():
    input_student("TestName", "TestSurname", 20, 123456, "TestMajor", 3.5)
    cursor.execute("SELECT * FROM students")
    result = cursor.fetchall()
    assert len(result) == 1
    assert result[0][0] == "TestName"
    assert result[0][1] == "TestSurname"


def test_remove_student():
    input_student("RemoveTest", "RemoveSurname", 22, 654321, "RemoveMajor", 4.0)
    cursor.execute("SELECT * FROM students")
    result_before = cursor.fetchall()
    assert len(result_before) == 1

    remove_student("id", 654321)
    cursor.execute("SELECT * FROM students")
    result_after = cursor.fetchall()
    assert len(result_after) == 0


def test_change_student():
    input_student("ChangeTest", "ChangeSurname", 25, 111111, "ChangeMajor", 3.8)
    cursor.execute("SELECT * FROM students WHERE id = 111111")
    result_before = cursor.fetchone()
    assert result_before[2] == 25

    change_student("age", 30, "id", 111111)
    cursor.execute("SELECT * FROM students WHERE id = 111111")
    result_after = cursor.fetchone()
    assert result_after[2] == 30


def test_comparing_students():
    input_student("Student1", "Surname1", 20, 111111, "Math", 3.9)
    input_student("Student2", "Surname2", 21, 222222, "Science", 4.2)

    print("Expected output:")
    comparing_students(111111, 222222)


if __name__ == "__main__":
    test_input_student()
    test_remove_student()
    test_change_student()
    test_comparing_students()

    print("All tests passed!")
