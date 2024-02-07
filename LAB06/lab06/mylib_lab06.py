import matplotlib.pyplot as plt
import pandas as pd
import os
import random


global clear
clear = lambda: os.system("cls")


def disp_welcome():
    def welcome():
        print("------------------------------------------")
        print("------------------------------------------")
        print("--------  WELCOME TO PLOTTER_420  --------")
        print("------------------------------------------")
        print("-------  PRESS ENTER_ TO CONTINUE  -------")
        print("------------------------------------------")
        print("------------------------------------------")

    clear()
    welcome()

    check = input()
    if check == "":
        clear()
    else:
        exit


def disp_menu():
    def menu():
        print("------------------------------------------")
        print("-----------------  MENU  -----------------")
        print("------------------------------------------")
        print("-----  CHOOSE YOUR OPERATION NUMBER:  ----")
        print("------------------------------------------")
        print("--  OPERATION 1 -            bar chart  --")
        print("--  OPERATION 2 -           line chart  --")
        print("--  OPERATION 3 -    remove blank rows  --")
        print("--  OPERATION 4 -    fill blank values  --")
        print("------------------------------------------")
        op_choice = int(input("Input operation you want to perform [1-5]: "))
        return op_choice

    clear()
    op_choice = menu()

    clear()
    if op_choice > 0 and op_choice <= 6:
        return op_choice
    else:
        exit


def end_option():
    choice = input("Do you want to exit (E) or return to the menu (M)?: ").lower()
    if choice == "e":
        exit()
    elif choice == "m":
        return True
    else:
        print("Invalid choice. Returning to the menu.")
        return True


def plot_earnings_by_attribute(data, attribute):
    high_earners = data[data["income"] == " >50K"]

    grouped_data = high_earners.groupby(attribute).size().reset_index(name="count")

    if grouped_data.empty:
        print(f"No data available for attribute: {attribute}")
        return

    plt.figure(figsize=(10, 6))
    plt.bar(grouped_data[attribute], grouped_data["count"])
    plt.title(f"Distribution of earners >50k by {attribute}")
    plt.xlabel(attribute)
    plt.ylabel("Number of people earning >50k")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()


def plot_line(dataframe, column_x, column_y):
    grouped = dataframe.groupby(column_x)[column_y].count().reset_index()

    plt.figure(figsize=(10, 6))
    plt.plot(grouped[column_x], grouped[column_y], marker="o")
    plt.xlabel(column_x)
    plt.ylabel(f"Count of {column_y}")
    plt.title(f"Count of {column_y} per {column_x}")
    plt.xticks(rotation=90)
    plt.grid(True)
    plt.tight_layout()
    plt.show()


def remov_blank_rows(df):
    mask = (df == " ?").any(axis=1)
    df_cleaned = df[~mask]
    return df_cleaned


def check_records_number(df):
    row_count = len(df)
    print("Number of rows:", row_count)


def fill_blanks(df, column):
    unique_values = df[column].unique()

    def other_values(unique_values):
        other_values = [value for value in unique_values if value != " ?"]
        return other_values

    non_question_mark_values = other_values(unique_values)

    for index, value in df[column].items():
        if value == " ?":
            random_filler = random.choice(non_question_mark_values)
            df.at[index, column] = random_filler

    return df
