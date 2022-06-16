from datetime import datetime
from socket import *
from time import time

def main():
    serverName = 'localhost'
    serverPort = 9600
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    message = 'Ping'
    counter = 10
    i = 0
    remain = counter - i
    print(counter,'tried\n')

    while i < counter:
        i += 1
    print('\nAttempt Number: ', i)
    print('Left attempts:', remain)

    a = datetime.now()
    clientSocket.sendto(message, (serverName, serverPort))

    clientSocket.settimeout(1)

    try:
        modifiedMessage, serverAddress = clientSocket.recvfrom(1024)
        b = datetime.now()
        c = a-b;
        print(modifiedMessage)
        print('Elapsed Time:', c.microseconds)
    except timeout:
        print('Sorry! Your connection timed out!')

    if i == 10:
        print('Bye!')

        clientSocket.close()

        print('Socket closed no more pings!')
pass

if __name__ == '__main__':
    main()
