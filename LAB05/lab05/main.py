# Pomysl na program:

# DONE    Program do zarzadzania baza danych studentow, kazdy student bedzie mial imie, nazwisko,
# wiek, srednia, kierunek, id

# W ramach programu uzytkownik bedzie mogl sprawdzic rozne informacje o studencie;
# wylsitowac studentow ktorzy kwalifikuja sie pod stypendium,
# dostac poszczegolne informacje, czy uzyskac studentow z tym samym np imieniem.

# Rowniez uzytkownik bedzie mogl zmieniac dowolne dane, usuwac i dodawac studentow z bazy danych.

# funkcja dekomponujaca: np funkcja usuniecia studentow o okreslonych informacjach, wtedy
# bede dawal funkcja usun_studenta(jakies dane) a ta funkcja np porownuje GPA, imiona itp.
# wiec no, to chyba tyle...


from library_lab05 import *

create_table()


input_student("Aleksandra", "Pilsner", 21, 123456, "Electrical Engineering", 3.75)
input_student("Bartosz", "Stout", 19, 234567, "Computer Science", 4.00)
input_student("Celina", "Porter", 20, 345678, "Business Administration", 3.90)
input_student("Dawid", "Hefeweizen", 22, 456789, "Mechanical Engineering", 3.60)
input_student("Eliza", "Amber", 18, 567890, "Biochemistry", 4.20)
input_student("Feliks", "Bock", 21, 678901, "Graphic Design", 3.80)
input_student("Gabriela", "Lager", 20, 789012, "Environmental Science", 3.95)
input_student("Henryk", "Ale", 19, 890123, "Psychology", 3.85)
input_student("Izabela", "Saison", 22, 901234, "Civil Engineering", 3.70)
input_student("Jacek", "Porter", 18, 102345, "English Literature", 4.10)

while True:
    disp_welcome()
    op_choice = disp_menu()

    match op_choice:
        # First case, displaying the students already in the database
        case 1:
            print("--- Display Options ---")
            print("1. Display all students")
            print("2. Filter students by a specific criterion")

            display_choice = input("Choose display option (1 or 2): ")

            if display_choice == "1":
                result = display_student("all")
                if not result:
                    print("No students found.")
                else:
                    for student in result:
                        print(
                            student
                        )  # Modify this to display specific information from each student
            elif display_choice == "2":
                input_where = input(
                    "Provide the column name by which you'd like to filter students: "
                )
                input_what = input(
                    f"Provide the value you want the '{input_where}' to be equal to: "
                )
                result = display_student("filter", input_where, input_what)
                if not result:
                    print("No students found with the provided criteria.")
                else:
                    for student in result:
                        print(
                            student
                        )  # Modify this to display specific information from each student
            else:
                print("Invalid choice.")

            if end_option():
                continue

        # Second case, inputting a student of chosen attributes
        case 2:
            print("--- You are now adding students into the database ---")

            name = input("Provide the student's name: ")
            surname = input("Provide the student's surname: ")
            age = int(input("Provide the student's age: "))
            id = int(input("Provide the student's ID: "))
            major = input("Provide the student's major: ")
            gpa = float(input("Provide the student's GPA: "))
            input_student(name, surname, age, id, major, gpa)

            if end_option():
                continue

        # Third case, removing a student based on given criteria
        case 3:
            print("--- You are now removing students from the database ---")

            rem_where = input(
                "Provide the column name by which you'd like to remove students: "
            )
            rem_equal = input(
                f"Provide the value you want the '{rem_where}' to be equal to for removal: "
            )

            remove_student(rem_where, rem_equal)

            if end_option():
                continue

        # Fourth case, changing student data based on given criteria
        case 4:
            print("--- You are now changing student data in the database ---")

            what_change = input(
                "Provide the column name you want to change for the student: "
            )
            new_value = input(f"Provide the new value for '{what_change}': ")
            where_change = input(
                "Provide the column name by which you'd like to select the student: "
            )
            old_value = input(
                f"Provide the value you want the '{where_change}' to be equal to: "
            )

            change_student(what_change, new_value, where_change, old_value)

            if end_option():
                continue

        # Fifth case, comparing GPAs between two students
        case 5:
            print("--- You are now comparing student GPAs ---")

            stud_A = int(input("Provide ID of first student: "))
            stud_B = int(input("Provide ID of second student: "))
            comparing_students(stud_A, stud_B)

            if end_option():
                continue
