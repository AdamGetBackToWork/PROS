def welcome():
    print("------------------------------------------")
    print("------------------------------------------")
    print("---  WELCOME TO USOS TERMINAL VERSION  ---")
    print("------------------------------------------")
    print("-------  PRESS ENTER_ TO CONTINUE  -------")
    print("------------------------------------------")
    print("------------------------------------------")


def menu():
    print("------------------------------------------")
    print("-----------------  MENU  -----------------")
    print("------------------------------------------")
    print("-----  CHOOSE YOUR OPERATION NUMBER:  ----")
    print("------------------------------------------")
    print("--  OPERATION 1 -     display students  --")
    print("--  OPERATION 2 -         add students  --")
    print("--  OPERATION 3 -      remove students  --")
    print("--  OPERATION 4 -  change student data  --")
    print("--  OPERATION 5 -  compare student GPA  --")
    print("------------------------------------------")
    op_choice = int(input("Input operation you want to perform [1-5]: "))
    return op_choice
