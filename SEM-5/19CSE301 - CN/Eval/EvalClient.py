import socket
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
ping_address = ('localhost', 192)
sock.settimeout(1)

try:
    for i in range(1, 11):
        start = time.time()
        message = 'Ping Attempt #' + str(i) + " " + time.ctime(start)
        try:
            sent = sock.sendto(message.encode(), ping_address)
            print("Sent " + message)
            data, server = sock.recvfrom(4096)
            print("Received ", data)
            end = time.time()
            elapsed = end - start
            print("RTT: " + str(elapsed) + " seconds\n")
        except socket.timeout:
            print("Attempt #" + str(i) + ": Requested Time out\n")
finally:
    print("closing socket")
    sock.close()
