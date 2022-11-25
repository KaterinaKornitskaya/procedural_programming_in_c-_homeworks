﻿// дз тиждень 4, страница 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main1()
/*
Завдання 2. Зарплата менеджера становить 200$ + відсоток від продажів, 
продажі до 500$ — 3%, 
від 500 до 1000 — 5%, 
понад 1000 — 8%. 
Користувач вводить з клавіатури рівень продажів для трьох менеджерів. 
Визначити їхню зарплату, визначити найкращого менеджера, нарахувати
йому премію 200$, вивести підсумки на екран.
*/
{
    float sale1, sale2, sale3;        // переменная для ввода уровня продаж троих менеджеров
    float salary1, salary2, salary3;  // перемення для зарплаты троих менеджеров
    const float salary_start = 200;   // константа для зарплаты без процента
    const float bonus = 200;          // константа для бонуса для лучшего менеджера
    

    std::cout << "Enter the sales of three managers\n" << std::endl << "1st manager's sales: ";
    std::cin >> sale1;
    std::cout << "2nd manager's sales: ";
    std::cin >> sale2;
    std::cout << "3rd manager's sales: ";
    std::cin >> sale3;
    

    if (sale1 < 500)
    {
        salary1 = salary_start + (sale1 * 0.03);
    }
    else if (sale1 >= 500 && sale1 < 1000) 
    {
        salary1 = salary_start + (sale1 * 0.05);
    }
    else if (sale1 >= 1000)
    {
        salary1 = salary_start + (sale3 * 0.08);
    }
    std::cout << std::endl << "The manager's salaries are: " << std::endl
        << "1st manager`s salary: " << salary1 << std::endl;

    if (sale2 < 500)
    {
        salary2 = salary_start + (sale2 * 0.03);
    }
    else if (sale2 >= 500 && sale2 < 1000)
    {
        salary2 = salary_start + (sale2 * 0.05);
    }
    else if (sale2 >= 1000)
    {
        salary2 = salary_start + (sale2 * 0.08);
    }
    std::cout << "2nd manager`s salary: " << salary2 << std::endl;

    if (sale3 < 500)
    {
        salary3 = salary_start + (sale3 * 0.03);
    }
    else if (sale3 >= 500 && sale3 < 1000)
    {
        salary3 = salary_start + (sale3 * 0.05);
    }
    else if (sale3 >= 1000)
    {
        salary3 = salary_start + (sale3 * 0.08);
    }

    std::cout << "3rd manager`s salary: " << salary3 << std::endl <<std::endl;
    std::cout << "The best manager also erned a bonus" <<std::endl <<std::endl;

    if (sale1 > sale2 && sale1 > sale3)
    {
        std::cout << "The best manager is 1st" << std::endl << "He has " << salary1 << " salary + " << bonus << "bonus."
            << std::endl
            << std::endl
            << "Total amount for 1st manager is: " << salary1 + bonus << std::endl;
    }
    else if (sale2 > sale1 && sale2 > sale3)
    {
        std::cout << "The best manager is 2nd" << std::endl << "He has " << salary2 << " salary + " << bonus << "bonus."
            << std::endl
            << std::endl
            << "Total amount for 2nd manager is: " << salary2 + bonus << std::endl;
    }
    else if (sale3 > sale1 && sale3 > sale2)
    {
        std::cout << "The best manager is 3rd" << std::endl << "He has " << salary3 << " salary + " << bonus << "bonus."
            << std::endl
            << std::endl
            << "Total amount for 3rd manager is: " << salary3 + bonus << std::endl;
    }

    return 0;
}


int main()
/*
Користувач вводить дві дати (день, місяць, рік у вигляді цілих чисел). 
Необхідно визначити і вивести кількість днів між цими двома датами. 
Для розрахунків враховувати високосні роки, а також коректне число днів
у місяцях (березень — 31, вересень — 30, лютий невисокосного року — 28 і т.д.).
*/
{
    int day_s, month_s, year_s;  // вводит пользователь - дата начала - день, месяц, год
    int day_e, month_e, year_e;  // вводит пользователь - дата конца - день, месяц, год
    int days_in_years;           // кол-во дней в полных годах
    int days_total;              // общее кол-во дней (результат всей программы)
    int x;                       // високосных лет от 0 года до года конца
    int y;                       // високосных лет от 0 года до года начала + 1 (+1 - т.к. год начала уже идет)
    int a;                       // дней в месяцах года начала
    int b;                       // дней в месяцах года конца
    int z;                       // дней в полных годах между годом конца и годом начала
    int d;                       // полных лет между датам (год конца минус год начала+1)
    int day_in_end;              // дней в месяце даты начала (месяц, который уже идет)

    std::cout << "Enter your date start (day. month. year.)" << std::endl;
    std::cin >> day_s;
    std::cin >> month_s;
    std::cin >> year_s;
    std::cout << "Enter your date end (day. month. year.)" << std::endl;
    std::cin >> day_e;
    std::cin >> month_e;
    std::cin >> year_e;
    
    x = (year_e / 4) - (year_e / 100);              // посчитали високосных лет от 0 года до года конца
    y = ((year_s + 1) / 4) - ((year_s + 1) / 100);  // високосных лет от 0 года до года начала + 1 (+1 - т.к. год начала уже идет)
    z = x - y;                                      // посчитали дней в полных годах между годом конца и годом начала
    d = year_e - (year_s + 1);                      // посчитали полных лет между датам (год конца минус год начала+1)

    days_in_years = ((d - z) * 365) + (z * 366);    // посчитали кол-во дней в полных годах

  
  

    if (month_s == 1 && year_s % 4 == 0 && year_s % 100 != 0  // условия для кол-ва дней в полных месяцах даты начала 
        || month_s == 1 && year_s % 400 == 0)
    {
        a = (6 * 31) + (4 * 30) + 29;
    }
    else if (month_s == 1)
    {
        a = (6 * 31) + (4 * 30) + 28;
    }
    else if (month_s == 2)
    {
        a = (6 * 31) + (4 * 30);
    }
    else if (month_s == 3)
    {
        a = (5 * 31) + (4 * 30);
    }
    else if (month_s == 4)
    {
        a = (5 * 31) + (3 * 30);
    }
    else if (month_s == 5)
    {
        a = (4 * 31) + (3 * 30);
    }
    else if (month_s == 6)
    {
        a = (4 * 31) + (2 * 30);
    }
    else if (month_s == 7)
    {
        a = (3 * 31) + (2 * 30);
    }
    else if (month_s == 8)
    {
        a = (2 * 31) + (2 * 30);
    }
    else if (month_s == 9)
    {
        a = (2 * 31) + (1 * 30);
    }
    else if (month_s == 10)
    {
        a = (1 * 31) + (1 * 30);
    }
    else if (month_s == 11)
    {
        a = (1 * 31);
    }
    else if (month_s == 12)
    {
        a = 0;
    }

   

    if (month_e == 12 && year_e % 4 == 0 && year_e % 100 != 0  // условия для кол-ва дней в оставшихся полных месяцах даты конца 
        || month_e == 12 && year_e % 400 == 0)
    {
        b = (6 * 31) + (4 * 30) + 29;
    }
    else if (month_e == 12)
    {
        b = (6 * 31) + (4 * 30) + 28;
    }
    else if (month_e == 11)
    {
        b = (6 * 31) + (4 * 30);
    }
    else if (month_e == 10)
    {
        b = (5 * 31) + (4 * 30);
    }
    else if (month_e == 9)
    {
        b = (5 * 31) + (3 * 30);
    }
    else if (month_e == 8)
    {
        b = (4 * 31) + (3 * 30);
    }
    else if (month_e == 7)
    {
        b = (4 * 31) + (2 * 30);
    }
    else if (month_e == 6)
    {
        b = (3 * 31) + (2 * 30);
    }
    else if (month_e == 5)
    {
        b = (2 * 31) + (2 * 30);
    }
    else if (month_e == 4)
    {
        b = (2 * 31) + (1 * 30);
    }
    else if (month_e == 3)
    {
        b = (1 * 31) + (1 * 30);
    }
    else if (month_e == 2)
    {
        b = (1 * 31);
    }
    else if (month_e == 1)
    {
        b = 0;
    }

   

    
    if (month_s == 12)               // условия для кол-ва оставшихся дней в текущем месяце даты конца 
        day_in_end = 31 - day_s;
    if (month_s == 11)
        day_in_end = 30 - day_s;
    if (month_s == 10)
        day_in_end = 31 - day_s;
    if (month_s == 9)
        day_in_end = 30 - day_s;
    if (month_s == 8)
        day_in_end = 31 - day_s;
    if (month_s == 7)
        day_in_end = 31 - day_s;
    if (month_s == 6)
        day_in_end = 30 - day_s;
    if (month_s == 5)
        day_in_end = 31 - day_s;
    if (month_s == 4)
        day_in_end = 30 - day_s;
    if (month_s == 3)
        day_in_end = 31 - day_s;
    if (month_s == 2 && year_s % 4 == 0 && year_s % 100 != 0
        || month_s == 12 && year_s % 400 == 0)
        day_in_end = 29 - day_s;
    if (month_s == 2)
        day_in_end = 28 - day_s;
    if (month_s == 1)
        day_in_end = 31 - day_s;


    days_total = days_in_years + a + b + day_e + day_in_end;  // конечная формула для общего кол-ва дней между датами
    std::cout << "Total days" << std::endl << std::endl << days_total << std::endl;
     
    return 0;
}


