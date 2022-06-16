
from socket import *
import random


serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', 9600))

while True:
    rand = rand.randint(0, 10)
    message, address = serverSocket.recvfrom(1024)
    message = message.upper()
    if rand< 4:
        continue
    serverSocket.sendto(message, address)

pass
