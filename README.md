Это модель чата соединённого с БД, при запуске программы регистрируем, потом входим в аккаунт,
и чат вывод список пользователей и их сообщения


ВАЖНО! ЧИТАТЬ ОБЯЗАТЕЛЬНО!!!

   "Перед тем как тестироывть прочтите инструкции:

Проект должен быть настроен на работу с MYSQL API как в уроке "25.2. Работа с БД через API MySQL". Этот вроде настроен, но пересыл на гитхаб возможно уберёт все настройки

На пк должен быть установлен MYSQL

К файлам MYSQL lib, bin и др должен быть прописан путь, ("25.2. Работа с БД через API MySQL" )


ВАЖНО!
В MYSQL нужно до открытия чата создать базу testdb, пользователя root со всеми правами и паролем MayAzot777


В базе testdb создадим таблицу MESSAGE c двумя колонками - id, messageSQL


И вторую таблицу USERS с колонками id, username



В таблицу MESSAGE через MYSQL вводим слова 'HI users' на английском чтобы не мучатся с настройками


В таблицу USERS через MYSQL вносим слово 'Shapoklack' - тоже на Английском!


Чтобы не мучаться с настройками пишем логины и сообщения на АНГЛИЙСКОМ" 


Далее оставляем MYSQL включеным, запускаем проект, регистрируемся в чате на АНГЛИЙСКОМ, и после набираем ВХОД (кнопка 2)


Программа выведет всех пользователей сохранённых в базе данных, и все сообщения

теперь можно регистрироваться под разными никами и слать сообщения - они будут сохраняться в бд, а потом выводиться.

На скринах примеры того, как программа выводит пользователей и сообщения
