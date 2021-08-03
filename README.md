# Minitalk
Цель проекта:
Реализовать связь между двумя процессами Client и Server посредством сигналов в С, по стандарту 98 года.


Creating a communication program in the form of a client and server.
The server is launched first, and after being launched it displays its PID.
The client takes as parameters:

• The server PID.
• The string that should be sent.
• The client communicates the string passed as a parameter to the server. Once the string has been received, the server displays it.
• Communication between programs is done using UNIX signals.
• The server must be able to display the string pretty quickly.
• Server receives strings from several clients in a row, without needing to be restarted.
• Only two signals (SIGUSR1 and SIGUSR2) are used.


Bonus part

A small reception acknowledgment system was added to mandatory part.
Supports Unicode characters


Detailed information is in en.subject_minitalk.pdf.

Простейшая реализация с использованием библиотечных функций написанных для школы 21 (42) ранее.
Задержка 1600 установлена в связи с появлением ошибок вывода при тестированиии на моей системе при меньшей задержке.
