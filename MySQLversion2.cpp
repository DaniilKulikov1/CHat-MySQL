#include<iostream>
#include<string>
#include<vector>
#include <mysql.h>
using namespace std;



void hello()
{

    cout << R"(

                 ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv)

 )";
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "ПРИВЕТСТУЮ ВАС ПОЛЬЗОВАТЕЛЬ ВЫ ВОШЛИ В ЧАТ!" << endl;
    cout << "Перед тем как чатится прочтите инструкции:" << endl;
    cout << "Проект должен быть настроен на работу с MYSQL API, этот вроде настроен, но пересыл на гитхаб возможно уберёт все настройки" << endl;
    cout << "На пк должен быть установлен MYSQL" << endl;
    cout << "К файлам MYSQL lib, bin и др должен быть прописан путь, но на всякий случай я положил их в папку с проектом - на моём пк запускалось только с таким набором" << endl;
    cout << "В MYSQL нужно до открытия чата создать базу testdb, пользователя root со всеми правами и паролем MayAzot777 " << endl;
    cout << "В базе testdb создадим таблицу MESSAGE c двумя колонками - id, messageSQL" << endl;
    cout << "И вторуб таблицу USERS с колонками id, username" << endl;
    cout << "В таблицу MESSAGE через MYSQL вводим слово 'HI users' " << endl;
    cout << "В таблицу USERS через MYSQL вносим слово 'Shapoklack' " << endl;
    cout << "Чтобы не мучаться с настройками пишем логины и сообщения ТОЛЬКО НАы АНГЛИЙСКОМ" << endl;
    cout << "Далее оставляем MYSQL включеным, запускаем проект, регистрируемся на АНГЛИЙСКОМ, и после набираем ВХОД (кнопка 2)" << endl;
    cout << "Программа выведет всех пользователей сохранённых в базе данных, и все сообщения" << endl;
    cout << "Можно регистрироваться под разными никами и слать сообщения - они будут сохраняться в бд, а потом выводиться" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
};



class User
{
private:
    string name_p;
    string password_p;

public:

    User()//
    {
        name_p = " ";
        password_p = " ";
    };


    User(const string& name, const string& password) :name_p(name), password_p(password)
    {};


    string& getName()
    {
        return name_p;
    };

    string& getPassword()
    {
        return password_p;
    };

};


template<typename T>
class Memory
{
private:
    vector<T>data;
public:
    void AddSms(const T& value)
    {
        data.push_back(value);
    };


    void Display()
    {

        for (const auto& item : data)
        {


            /* cout << "В чате есть сообщение!!! Кому: " << item.getRecepient() << ". От кого: " << item.getSend() << endl;
             cout << "Cообщение: " << "" << item.getText() << "" << endl;*/

        }

    };

};


class Message
{
private:
    string recepient_p; /*кому*/
    string send_p;/* кто*/
    string text_p; /*текст смс*/
public:


    Message()
    {
        recepient_p = " ";
        send_p = " ";
        text_p = " ";
    }

    Message(const string& recepient, const string& send, const string& text) :recepient_p(recepient), send_p(send), text_p(text)
    {};

    const  string& getRecepient() const { // Добавлен модификатор const
        return recepient_p;
    }

    const  string& getSend() const { // Добавлен модификатор const
        return send_p;
    }

    const string& getText() const { // Добавлен модификатор const
        return text_p;
    }
};



class Chat
{
    Memory<Message>messages;
public:
    //функцией берём данные
    void sendMessage(const string& recepient, const string& send, const string& text)
    {
        //создаём обьект другого класса и наполняем
        Message message1(recepient, send, text);

        messages.AddSms(message1);//помещаем в массив

    };

    void DisplayMessages()
    {
        messages.Display();
    };
};




int main()
{
    system("chcp 1251");

    hello();

    string username, password;

    vector<User>Tolpa;

    cout << "Регистрация\n";
    cout << "Введите логин: " << endl;
    cin >> username;
    cout << "Введите пароль: " << endl;
    cin >> password;
    User First(username, password);
    Tolpa.push_back(First);
    cout << "Вы успешно зарегистрировались!Теперь войдите в аккаунт." << endl;


    //тут пишем команду для добвления в таблицу Users
    string userBD = "INSERT INTO USERS(id, username) values(default, ";

    //тут как и выше пишем текстовую команду для бд, теперь нужно её только перевисти в символы
    string usersBD1 = userBD + "'" + username + "'" + ")";

    //вот снова перевели в символы
    const char* incrementniyUser = usersBD1.c_str();

    // cout << usersBD1.c_str() << endl;

    MYSQL mysql;

    mysql_init(&mysql);
    if (&mysql == nullptr) {

        cout << "Дескриптор не создан" << endl;
    }

    mysql_set_character_set(&mysql, "utf8");
    //соединение
    if (!mysql_real_connect(&mysql, "localhost", "root", "MayAzot777", "testdb", NULL, NULL, 0)) {

        cout << "Ошибка подключения к базе данных " << mysql_error(&mysql) << endl;
    }
    else
    {
        cout << "Регистрация прошла и в базах данных testdb, в таблицу Users" << endl;
    }

    //вот отправили в базу данных и закрыли
    mysql_query(&mysql, incrementniyUser);
    mysql_close(&mysql);

    cout << " \n";
    cout << "Выберите действие:\n ";

    cout << "1. Послать сообщение\n";

    cout << "2. Войти в существующий аккаунт\n";

    cout << "3. Создать новый аккаунт\n";

    cout << "4. Выход из аккаунта\n";

    cout << "5. Завершить\n";

    cout << " \n";

    cout << "В дальнейшем пользуйтесь этими кнопками" << endl;



    User* currentUser = nullptr;

    Chat chat;
    int choice;

    do {
        cin >> choice;
        switch (choice)
        {///////////
            {
        case 1:
            if (currentUser != nullptr) { // только если пользователь вошел
                string recipient, text;
                cout << "Введите получателя: ";
                cin >> recipient;
                cout << "Введите текст сообщения: ";
                cin.ignore();
                getline(cin, text);

                chat.sendMessage(recipient, currentUser->getName(), text);
                cout << "Сообщение отправлено!\n";
                cout << " \n";
                cout << " \n";

                string Recipient = "For user: " + recipient;

                //cоздадим строку "от кого: "
                string sender = ". Who write: " + currentUser->getName();

                //создадим строку сообщение:
                string soobshenie = ". Message: " + text;

                //cклеим эти строки 
                string bd = Recipient + sender + soobshenie;

                //cделаем строку-команду 
                string kommandBD = "INSERT INTO MESSAGE(id, messageSQL) values(default, ";

                //делаем окончательно
                string kommandBD1 = kommandBD + "'" + bd + "'" + ")";


               
                //преобразуем cамую последнюю строку в символы 

                const char* smsBD1 = kommandBD1.c_str();


                MYSQL mysql;
                MYSQL_RES* res;
                MYSQL_ROW row;

                mysql_init(&mysql);
                if (&mysql == nullptr) {

                    cout << "Дескриптор не создан" << endl;
                }

                mysql_set_character_set(&mysql, "utf8");
                //соединение
                if (!mysql_real_connect(&mysql, "localhost", "root", "MayAzot777", "testdb", NULL, NULL, 0)) {

                    cout << "Ошибка подключения к базе данных " << mysql_error(&mysql) << endl;
                }
                else
                {
                    cout << "Cообщение передано в базу данных testdb, в таблицу MESSAGE" << endl;
                }


                mysql_query(&mysql, smsBD1);

                //еще один вывод сообщений
                int i = 0;

                //вывод сообщений с базы
                mysql_query(&mysql, "SELECT * FROM MESSAGE");//тут смотрим таблицу cообщений
                if (res = mysql_store_result(&mysql)) {
                    while (row = mysql_fetch_row(res)) {
                        for (i = 0; i < mysql_num_fields(res); i++) {
                            cout << row[i] << "  ";
                        }
                        cout << endl;
                    }
                    cout << " \n";
                    cout << "Выберите действие:\n ";

                    cout << "1. Послать сообщение\n";

                    cout << "2. Войти в существующий аккаунт\n";

                    cout << "3. Создать новый аккаунт\n";

                    cout << "4. Выход из аккаунта\n";

                    cout << "5. Завершить\n";

                    cout << " \n";
                }

                else
                {
                    cout << "Ошибка MySql номер " << mysql_error(&mysql);
                }





                mysql_close(&mysql);
                //еще один вывод сообщений конец


            }
            else {
                cout << "Вы не вошли в систему. Сначала войдите в свой аккаунт нажав 2.\n";
            }
            break;
            }


            {
        case 2:
            cout << "Вход в существующий аккаунт\n" << endl;
            string username1, password1;
            cout << "Введите логин: " << endl;
            cin >> username1;
            cout << "Введите пароль: " << endl;
            cin >> password1;


            for (int k = 0; k < Tolpa.size(); k++) {
                User* user = &Tolpa[k]; // Получаем указатель на пользователя
                if (user != nullptr && user->getName() == username1 && user->getPassword() == password1)
                {
                    currentUser = user; // Устанавливаем currentUser напрямую
                    cout << "Вы успешно вошли в аккаунт!" << endl;
                 //   chat.DisplayMessages(); //раньше сообщения выводились таким способом без базы данных
                 // 
                 // 
                     //а тут добавим показ списков тех кто зарегестрирован в базе данных и список сообщений чата
                    cout << "Все, кто зарегестрирован" << endl;
                    MYSQL mysql;
                    MYSQL_RES* res;
                    MYSQL_ROW row;

                    int i = 0;
                    mysql_init(&mysql);
                    if (&mysql == nullptr) {
                        // Если дескриптор не получен — выводим сообщение об ошибке
                        cout << "Дескриптор не получен!" << endl;
                    }

                    if (!mysql_real_connect(&mysql, "localhost", "root", "MayAzot777", "testdb", NULL, NULL, 0)) {
                        // Если нет возможности установить соединение с БД выводим сообщение об ошибке
                        cout << "Соединение с базой не установлено" << mysql_error(&mysql) << endl;
                    }

                    mysql_query(&mysql, "SELECT * FROM USERS");//тут смотрим таблицу юзеров
                    if (res = mysql_store_result(&mysql)) {
                        while (row = mysql_fetch_row(res)) {
                            for (i = 0; i < mysql_num_fields(res); i++) {
                                cout << row[i] << "  ";
                            }
                            cout << endl;
                        }
                    }

                    else
                    {
                        cout << "Ошибка MySql номер " << mysql_error(&mysql);
                    }
                    //mysql_close(&mysql);

                    cout << endl;
                    cout << endl;

                    //А теперь покажем сообщения из чата:
                    cout << "Cообщения в чате: " << endl;
                  

                    mysql_query(&mysql, "SELECT * FROM MESSAGE");//тут смотрим СООБЩЕНИЙ
                    if (res = mysql_store_result(&mysql)) {
                        while (row = mysql_fetch_row(res)) {
                            for (i = 0; i < mysql_num_fields(res); i++) {
                                cout << row[i] << "  ";
                            }
                            cout << endl;
                        }
                        //и снова сделаем меню выбора
                        cout << " \n";
                        cout << "Выберите действие:\n ";

                        cout << "1. Послать сообщение\n";

                        cout << "2. Войти в существующий аккаунт\n";

                        cout << "3. Создать новый аккаунт\n";

                        cout << "4. Выход из аккаунта\n";

                        cout << "5. Завершить\n";

                        cout << " \n";

                    }
                    else
                        cout << "Ошибка MySql номер " << mysql_error(&mysql);
                    mysql_close(&mysql);

                    break;
                }

               



            }
            if (currentUser == nullptr) {
                cout << "Неправильный логин или пароль." << endl;
            }
            break;
            }



            {
        case 3:
            cout << "Регистрация\n";
            cout << "Введите логин: " << endl;
            cin >> username;
            cout << "Введите пароль: " << endl;
            cin >> password;
            User newUser(username, password);
            Tolpa.push_back(newUser);  

            int lastuser = Tolpa.size() - 1;


            currentUser = &Tolpa.at(lastuser); 
            cout << "Вы успешно зарегистрировались!" << endl;
            cout << "  " << endl;
         

            //тут пишем команду для добвления в таблицу Users
            string userBD = "INSERT INTO USERS(id, username) values(default, ";

            //тут как и выше пишем текстовую команду для бд, теперь нужно её только перевисти в символы
            string usersBD1 = userBD + "'" + username + "'" + ")";

            //вот снова перевели в символы
            const char* incrementniyUser = usersBD1.c_str();

           // cout << usersBD1.c_str() << endl;

            MYSQL mysql;

            mysql_init(&mysql);
            if (&mysql == nullptr) {

                cout << "Дескриптор не создан" << endl;
            }

            mysql_set_character_set(&mysql, "utf8");
            //соединение
            if (!mysql_real_connect(&mysql, "localhost", "root", "MayAzot777", "testdb", NULL, NULL, 0)) {

                cout << "Ошибка подключения к базе данных " << mysql_error(&mysql) << endl;
            }
            else
            {
                cout << "Пользователь внесён базу данных testdb, в таблицу USERS" << endl;
            }

            //вот отправили в базу данных и закрыли
            mysql_query(&mysql, incrementniyUser);
            mysql_close(&mysql);

            break;
            }

            {
        case 4:
            currentUser = nullptr; // Устанавливаем currentUser в nullptr при выходе
            cout << "Выход выполнен. Войдите в существующий аккаунт нажав 2 или зарегестрируйтесь нажав 3\n";
            cout << " \n";
            cout << " \n";
            break;
            }

            {
        case 5:

            cout << "Вы выполнили учебный выход из чата\n";
            cout << "В будущем эта кнопка будет закрывть всю консоль\n";
            cout << "А пока - это только учебный проект" << endl;
            break;
            }



        default:
            cout << "Вы ввели неправильное значение" << endl;
            break;

        }//////

    } while (choice != 5);


    return 0;
}









