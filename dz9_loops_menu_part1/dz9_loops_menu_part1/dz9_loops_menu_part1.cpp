﻿// dz9_loops_menu_part1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#define gotoxy(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y})
#include <string>

int main()
/*
Вивести на екран фігури, заповнені зірочками.
Діалог з користувачем реалізувати за допомогою меню.
*/
{
    std::cout
        << "   Menu" << std::endl
        << "  Item a " << std::endl
        << "  Item b " << std::endl
        << "  Item c " << std::endl
        << "  Item d " << std::endl
        << "  Item e " << std::endl
        << "  Item f " << std::endl
        << "  Item g " << std::endl
        << "  Item h " << std::endl
        << "  Item i " << std::endl
        << "  Item j " << std::endl;
    
    gotoxy(0, 1);      // перевод курсора на позицию (0, 1); 1 по оси У вниз - первый пункт меню
    std::cout << '>';  // символ > вывели в позицию (0, 1)
    short y = 1;
    char button;       // переменная для клавиши на клавиатуре

    do                 // цикл для управления иеню
    {
        button = _getch();                  // _getch() - считывает кнопку
        if (button == 0 || button == -32)   // условие для кнопок которые посылают два значения
                                            // для кнопок, которые посылают два значения
        {                                   // кнопки F1 и т.д. отправляют 0 и еще одно значение
            button = _getch();              // стрелки отправляют -32 и еще одно значение
        }                                   // поэтому считываем их дважды
                                            // если я правильно поняла)))
    
        gotoxy(0, y); std::cout << ' ';     // убираем стрелку в позиции (0, у), вместо нее вводим пробел

        if (button == 80)  // условие при нажатии кнопки "вниз"
        {
            y += 1;        // добавляем к У +1, тоесть сдвигаем курсор вниз по оси У
        
            if (y >= 11)   // условие - если У дошло до 11 
            {              // (по кол-ву пунктов меню)
            y = 1;         // возвращаем курсор на У = 1 
            }
        }
        gotoxy(0, y); std::cout << ' ';     // убираем стрелку в позиции (0, у), вместо нее вводим пробел
                                            // или не нужно в этом месте стирать???
    
        if (button == 72)  // условие при нажатии кнопки "вверх"
        {
            y -= 1;        // отнимаем от У -1 --> сдвигаем курсор вверх по оси У

            if (y < 1)     // условие - если У дошло вверх до У=1
            {              //
                y = 10;    // возвращаем курсор на У=10 (последний пункт меню)
            }
        }
        gotoxy(0, y); 
        std::cout << '>';
    }
    
    while (button != 27 && button != 13);  // выполняем условия выше до тех пор, пока
                                           // не будет нажатия клавини "Esc" или "Enter"
                                           // в этом месте Капитан Морган придумал поменять || на &&

    gotoxy(0, 13);  // выводи курсор под меню

                                         // HELP   HELP   HELP
    std::string message;                 // здесь с помощью string я пыталась сделать так, что бы при выводе
    message = std::to_string(y);     // на экран выводился не номер пункта меню по У, а само
                                         // название пункта, как оно прописано в меню
                                         // например в моем меню это буква алфавита 
                                         // Но ничего не получилось, все равно выводит число по У


    if (button == 27)  // условие - при нажатии Esc программа выводит "Bye!" и завершает работу
    {
        std::cout << "Bye!";
        return -1;
    }

    if (button == 13)  // условие - при нажатии Enter программа открывает выбранный пункт меню
    {
        std::cout << "You select " << message << std::endl << std::endl;
    }
   
    int n = 9;  // переменная для количества символов
    switch (y)  // в каждом case прописываем содержимое выбранного пункта меню
    {   
        case 1:
        /*  *********
            -********
            --*******
            ---******
            ----*****
            -----****
            ------***
            -------**
            --------*
        */
            for (int i = 0; i < n; ++i)         // +1 строка, пока количество строк не станет = n
            {
                for (int j = 0; j <= i; ++j)    // вложенный цикл для символа " "
                {
                    _putch(' ');
                }
                for (int k = n - i; k >0; --k)  // вложенный цикл для символа "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
        break;

        case 2:
        /*  *
            **
            ***
            ****
            *****
            ******
            *******
            ********
            *********
        */
            for (int i = 0; i < n; ++i)       // цикл для количества строк
            {
                for (int j = 0; j <= i; ++j)  // вложенный цикл для символа "*"
                {
                     _putch('*');
                }  
                std::cout << std::endl;
            }
        break;

        case 3:
        /*  *********
            -*******-
            --*****--
            ---***---
            ----*----



       
        */
            for (int i = n / 2; i >= 0; --i)          // верхняя часть
            {
                int spaces = n / 2 - i;               // переменная для " "
                int stars = 1 + 2 * i;                // переменная для "*"
                    for (int j = 0; j < spaces; ++j)  // вложенный цикла для " "
                    {
                        _putch(' ');
                    }
                    for (int j = 0; j < stars; ++j)   // вложенный цикла для "*"
                    {
                    _putch('*');
                    }
                std::cout << std::endl;
            }
            for (int i = n / 2; i >= 0; --i)          // нижняя часть (если она нужна???)
            {
                std::cout << std::endl;               // для пустых строк, 
            }                                         // кол-во пустых строк нижней части = верхней
        break;

        case 4:
        /* 
        


           ----*----
           ---***---
           --*****--
           -*******-
           *********
        */
          
            for (int i = n / 2; i >= 0; --i)      // цикл для строк верхней части
            {
                std::cout << std::endl;
            }
            for (int i = 0; i <= n / 2; ++i)      // цикл для нижней части
            {
                int spaces = (n / 2) - i;         // переменная для " "    
                int stars = 1 + 2 * i;            // переменная для "*" 
                
                for (int j = 0; j < spaces; ++j)  // вложенный цикл для " "
                {
                    _putch(' ');
                }
                for (int j = 0; j < stars; ++j)   // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
        break;

        case 5:
        /*  *********
            -*******-
            --*****--
            ---***---
            ----*----
            ----*----
            ---***---
            --*****--
            -*******-
            *********
        */

            for (int i = n / 2; i >= 0; --i)      // верхняя часть
            {
                int spaces = n / 2 - i;
                int stars = 1 + 2 * i;
                for (int j = 0; j < spaces; ++j)  // вложенный цикл для " "
                {
                    _putch(' ');
                }
                for (int j = 0; j < stars; ++j)   // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
            for (int i = 0; i <= n / 2; ++i)      // нижняя часть 
            {
                int spaces = (n / 2) - i;
                int stars = 1 + 2 * i;
                for (int j = 0; j < spaces; ++j)  // вложенный цикл для " "
                {
                    _putch(' ');
                }
                for (int j = 0; j < stars; ++j)   // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
        break;

        case 6:
        /*  *---------*
            **-------**
            ***-----***
            ****---****
            *****-*****
            ****---****
            ***-----***
            **-------**
            *---------*
        */
            for (int i = 0; i <= n / 2 ; ++i)     // верхняя часть 
            {
                for (int j = 0; j <= i; ++j)      // вложенный цикл для "*" слева
                {
                    _putch('*');
                }
                int spaces = n - i*2;
                int stars = 1 + i;
                for (int j = 0; j < spaces; ++j)  // вложенный цикл для " " в центре
                {
                    _putch(' ');
                }
                for (int k = 0; k < stars; ++k)   // вложенный цикл для "*" справа
                {
                    _putch('*');
                }
                std::cout << std::endl;
            } 
           for (int i = 0; i < n / 2; ++i)                // нижняя часть 
            {
                for (int j = 0; j <= n / 2 - i - 1; ++j)  // вложенный цикл для "*" слева
                {                                         // здесь я запуталась с j <= n / 2 - i - 1
                    _putch('*');                       // выводит верно, но может можно было сократить как-то
                }
                int spaces = i * 2;
                int stars = n/2 - i - 1;
                for (int j = 0; j <= spaces +2; ++j)      // вложенный цикл для " " в центре
                {
                    _putch(' ');
                }
                for (int k = 0; k <= stars; ++k)          // вложенный цикл для "*" справа
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }    
        break;

        case 7:
        /*  *
            **
            ***
            ****
            *****
            ****
            ***
            **
            *
        */
            for (int i = 0; i <= n / 2; ++i)         // верхняя часть
            {  
                for (int j = 0; j <= i; ++j)         // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
            for (int i = 0; i < n / 2; ++i)          // нижняя часть
            {
                for (int j = 0; j < n / 2 - i; ++j)  // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
        break;

        case 8:
        /*  ---------*
            --------**
            -------***
            ------****
            -----*****
            ------****
            -------***
            --------**
            ---------*
        */  
            for (int i = 0; i <= n / 2; ++i)       // верхняя часть 
            {
                int spaces = n - i;
                int stars = 1 + i;
               for (int j = 0; j <spaces; ++j)     // вложенный цикл для " " слева
                {
                    _putch(' ');
                }
                for (int k = 0; k <stars; ++k)     // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
            for (int i = 1; i <= n / 2; ++i)       // нижняя часть
            {
                int spaces = n / 2 + i;
                int stars = n/2  - i;
                for (int j = 0; j <= spaces; ++j)  // вложенный цикл для " " слева
                {
                    _putch(' ');
                }
                for (int k = 0; k <= stars; ++k)   // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
             
        break;

        case 9:
        /*  *********
            ********
            *******
            ******
            *****
            ****
            ***
            **
            *
        */
            for (int i = n; i >= 0; --i)
            {
                for (int j = 0; j < i; ++j)
                {
                    _putch('*');
                }
                std::cout << std::endl;
            }
        break;

        case 10:
        /*  --------*
            -------**
            ------***
            -----****
            ----*****
            ---******
            --*******
            -********
        */
            for (int i = 0; i <= n; ++i)
            {

                for (int j = n - i; j >= 0; --j)  // вложенный цикл для " "
                {
                    _putch(' ');
                }
                for (int k = 0; k < i; ++k)       // вложенный цикл для "*"
                {
                    _putch('*');
                }
                std::cout << std::endl;

            }
        break;
    }

        return 0;

}
