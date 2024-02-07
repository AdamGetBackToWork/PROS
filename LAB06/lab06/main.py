# Pomysł na program:
#
# Uzytkownik odpala program, wowczas pobierana jest baza danych. Uzytkownik moze plotowac
# sobie rozne funkcje w zaleznosci od wybranych parametrow, rowniez moze wybeirac typ wykresu:
# slupkowy/liniowy itp
#
# funkcja dotyczaca danych niepelnych; jedna funckja do zamiany "?" na " ", ale tez moze okresl
# opcja programu by uzupelnic puste dane przykladowymi z reszty setu
#
# dodac funkcje ktora nam pokazuje czesc bazy danych w jakis sposob


import matplotlib.pyplot as plt
import pandas as pd
from mylib_lab06 import *


df = pd.read_csv(data.csv)

# Check available columns
columns = df.columns
print(columns)

# Read data from CSV file


# ---------------- DEBUGGING -------------------
# # Check unique values for 'Age' in '>50K' income group
# high_income_age = df[df['Income'] == ' >50K']['Age'].unique()
#
# print("Unique ages for '>50K' income:", high_income_age)
#
# # Check unique values in the 'Income' column
# unique_income_values = df['Income'].unique()
# print("Unique values in 'Income' column:", unique_income_values)
#
# # Check unique values for 'Sex' in '>50K' income group
# high_income_sex = df[df['Income'] == ' >50K']['Sex'].unique()
# print("Unique sexes for '>50K' income:", high_income_sex)
#
# Check unique values for 'Race' in '>50K' income group
# high_income_race = df[df["income"] == " >50K"]["occupation"].unique()
# print("Unique races for '>50K' income:", high_income_race)
#
# # Check unique values for 'Education' in '>50K' income group
# high_income_education = df[df['Income'] == '>50K']['Education'].unique()
# print("Unique education levels for '>50K' income:", high_income_education)


while True:
    disp_welcome()
    op_choice = disp_menu()

    match op_choice:
        case 1:
            print(
                "You can choose between those values: 'age', 'workclass', 'education', 'education-years', 'marital-status','occupation', 'relationship', 'race', 'sex', 'hours-per-week','country'"
            )
            x_axis = input("On what do you want the chart to depend? ").lower()
            plot_earnings_by_attribute(df, x_axis)

            if end_option():
                continue
        case 2:
            print(
                "You can choose between those values: 'age', 'workclass', 'education', 'education-years', 'marital-status','occupation', 'relationship', 'race', 'sex', 'hours-per-week','country'"
            )
            x_axis = input("On what do you want the chart to depend? ").lower()
            y_axis = input("What youd like to be the depending value? ").lower()
            plot_line(df, x_axis, y_axis)
            if end_option():
                continue
        case 3:
            choice = input(
                "Youre about to remove all rows with at least one blank value at any column, do you want to proceed [P] or exit [E]? "
            ).lower()
            if choice == "p":
                curr_records = check_records_number(df)
                df_cleaned = remov_blank_rows(df)
                check_records_number(df_cleaned)
            else:
                continue

            if end_option():
                continue

        case 4:
            unique_values = df["occupation"].unique()
            print(unique_values)
            df_fixed = fill_blanks(df, "occupation")
            unique_values = df_fixed["occupation"].unique()
            print(unique_values)

            if end_option():
                continue
