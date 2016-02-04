#Example code from:
#http://www.binarytides.com/python-socket-server-code-example/

# Jonathan Rawlinson - M0ZJO - 2016

import socket
import sys
import thread
HOST = ''
PORT = 8950



s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print "Socket Created"

try:
	s.bind((HOST, PORT))
except socket.error as msg:
	print "Bind Failed - Error: " + str(msg[0]) + " Message: " + msg[1]
	sys.exit()

print "Socket Bind Complete"

s.listen(10)
print "Socket now Listening"


def clientthread(conn):
	#conn.send("Welcome to the Server")

	while True:
		
		data = conn.recv(1024)
		print len(data)
		print data
		reply = "ACK" #ACK here
		if not data:
			break

		conn.sendall(reply + ":[end]@")
	conn.close()



while True:
	conn, addr = s.accept()
	print "Connected with " + addr[0] + ":" + str(addr[1])
	thread.start_new_thread(clientthread ,(conn,))

s.close()
