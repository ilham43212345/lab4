    #include <iostream>
    #include <random>
    #include <vector>
    #include<ctime>

    int main()
    {
        setlocale(LC_ALL,"RU");
        srand(time(NULL));
        int len;
        std::cout << "Введите длину массива:" << std::endl;
        std::cin >> len;
        std::vector <std::vector <int>> mas(len);//создаем динамический массив
        for (int i = 0;i < mas.size();i++)
        {
            mas[i].resize(len);//рабатаем с памятью
        }
        for (int i = 0;i < mas.size();i++)
        {
            for (int j = 0;j < mas.size();j++)
            {
                mas[i][j] = rand() % (100);//заполняем массив случайными числами 
            }
        }
        std::cout << "Массив до изменения:" << std::endl;
        for (int i = 0;i < mas.size();i++)
        {
            for (int j = 0;j < mas.size();j++)
            {
                std::cout << mas[i][j] << " ";//выводим массив до изменения 
            }
            std::cout << std::endl;
        }
        int minindex = mas[0][0];//запомним самый первый элемент в массиве 
        int index_i = 0;//чтобы запомнить положение по столбцу 
        int index_j = 0;//чтобы запомнить положение по строке 
        for (int i = 0;i < mas.size();i++)
        {
            for (int j = 0;j < mas.size();j++)
            {
                //если условие не сработает то минимальный элемент и есть первый
                if (minindex > mas[i][j])
                {
                    minindex = mas[i][j];
                    index_i = i;//запоминаем i
                    index_j = j;//запоминаем j
                }
            }
        }
        std::cout << "Массив после изменения:" << std::endl;
        mas.erase(mas.begin()+index_i);//удаляем полностью строку
        for (int i = 0;i < len-1;i++)
        {
            mas[i].erase(mas[i].begin()+index_j);//удаляем элементы по столбикам 
        }
        for (int i = 0;i < mas.size();i++)
        {
            for (int j = 0;j < mas[i].size();j++)
            {
                std::cout << mas[i][j] << " ";
            }
            std::cout << std::endl;
        }        
    }