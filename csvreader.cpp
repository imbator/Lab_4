#include "csvreader.h"
#include <iostream>


std::vector<std::string> split(const std::string &str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
            end = str.find(delim, start);
            start = end + 1;
    } while (end != std::string::npos);
}

    return tokens;
}


CSVReader::CSVReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

CSVReader::~CSVReader()
{
    fin.close();
}

// тело функции readAll для чтения данных из файла
std::vector<Lesson> CSVReader::readAll()
{
    std::vector<Lesson> lesson;

        std::ifstream fin("schedule_database.csv");
        if (fin.is_open())
        {
            while (fin.good())
            {
                std::string line;
                std::getline(fin, line);

                std::vector<std::string> v = split(line, ';');

                Lesson temp;
                temp.number = std::stoi(v[0]);
                temp.title = QString::fromStdString(v[1]);
                temp.type = static_cast<lesson_type>(stoi(v[2]));
                temp.auditory = stoi(v[3]);

                lesson.push_back(temp);
                std::cout << "Added, next" << std::endl;
            }
        }
    return lesson;
}
