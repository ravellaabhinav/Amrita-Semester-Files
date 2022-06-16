import random
from socket import *

serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', 192))
print("Connection has been established on port 192 ")
while True:
    r = random.randint(0, 10)
    message, address = serverSocket.recvfrom(1024)
    message = message.upper()
    if r < 4:
        continue
    serverSocket.sendto(message, address)
