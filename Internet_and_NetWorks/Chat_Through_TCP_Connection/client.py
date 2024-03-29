import sys
import socket
import argparse
#########################
## - CSE 150 Final Project Script
## - Programmer: Ali Eshghi
## - Usage: "python3 client.py --id=<client_id> --port=<port> --server=<server_ip:port>"
#########################

# Function: to send messages between the client and the server
def send_message(server_ip, server_port, message):
    # AF_INET for IPv4, SOCK_STREAM for TCP packets
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((server_ip, int(server_port)))
        client_socket.sendall(message.encode())
        response = client_socket.recv(1024).decode().strip()
        client_socket.close()
        return response

# Function to set the client as a server and go into listening mode (AKA listening mode)
def wait_mode(server_ip, server_port, client_id, user_ip, user_port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        # if is_socket_bound(sock) == False:
        sock.bind((user_ip, user_port))
        sock.listen()
        conn, addr = sock.accept()
        with conn:
            response = send_message(server_ip, server_port, f"BRIDGE\r\nclientID: {client_id}\r\n\r\n")
            if "BRIDGEACK" in response:
                res_header = response.split("\r\n")[0]
                res_peerID = response.split("\r\n")[1].split(":")[1].lstrip()
                res_peerIP = response.split("\r\n")[2].split(":")[1].lstrip()
                res_peerPort = response.split("\r\n")[3].split(":")[1].lstrip()
            # print(f"Connected by {res_peerID}: {addr}")
            # while True:
            data = conn.recv(1024).decode().strip()
            if not data or "QUIT" in data:
                sock.close()
                return 0
            else:
                data_header = data.split("\r\n")[0]
                data_source = data.split("\r\n")[1].split(":")[1].lstrip()
                data_content = data.split("\r\n")[2].split(":")[1].lstrip()
                print(data_content)
    sock.close()
    chat_mode(server_ip, server_port, client_id, user_ip, user_port, res_peerIP, res_peerPort)

# Function that connects the client to the peer client and sends CHAT messages
def chat_mode(server_ip, server_port, client_id, user_ip, user_port, peer_ip, peer_port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # if is_socket_bound(s) == False:
        s.connect((peer_ip, int(peer_port)))
        chat = input(">")
        if chat == "/quit":
            message = "QUIT\r\n\r\n"
            s.sendall(message.encode())
            s.close()
            return 0
        else:
            message = f"CHAT\r\nclientID: {client_id}\r\ncontent: {chat}\r\n\r\n"
            s.sendall(message.encode())
        # s.sendall(chat.encode())
    s.close()
    wait_mode(server_ip, server_port, client_id, user_ip, user_port)


def main():
    # Check for the correct usage input
    if len(sys.argv) != 4:
        print("Usage: python3 client.py --id=<client_id> --port=<port> --server=<server_ip:port>")
        return

    # Parese the input aruments
    client_id = sys.argv[1].split('=')[1]
    port = int(sys.argv[2].split('=')[1])
    server_ip, server_port = sys.argv[3].split('=')[1].split(':')
    server_port = int(server_port)

    res_header = ""
    res_peerID = ""
    res_peerIP = ""
    res_peerPort = ""

    # Infinite loop to run the program as long as chat is not ended
    while True:
        command = input("Enter Command: ")
        # Register the user to the server
        if command == "/register":
            response = send_message(server_ip, server_port, f"REGISTER\r\nclientID: {client_id}\r\nIP: 127.0.0.1\r\nPort: {port}\r\n\r\n")
            print(response)
        # get the peer information
        elif command == "/bridge":
            response = send_message(server_ip, server_port, f"BRIDGE\r\nclientID: {client_id}\r\n\r\n")
            print(response)
            if "BRIDGEACK" in response:
                res_header = response.split("\r\n")[0]
                res_peerID = response.split("\r\n")[1].split(":")[1].lstrip()
                res_peerIP = response.split("\r\n")[2].split(":")[1].lstrip()
                res_peerPort = response.split("\r\n")[3].split(":")[1].lstrip()
                
                if res_peerID == "":
                    print("Wait to connect--")
                    wait_mode(server_ip, server_port, client_id, "127.0.0.1", port)
                    return 0
        # Quit the program completely (Break out of the loop)
        elif command == "/quit":
            break
        # Initiate chat
        elif command == "/chat":
            if res_peerIP != "" and res_peerPort != "":
                chat_mode(server_ip, server_port, client_id, "127.0.0.1", port, res_peerIP, res_peerPort)
                return 0
        # Prints the user ID
        elif command == "/id":
            print(client_id)
        # invalid command
        elif command.startswith("/"):
            print("invalid Command")
            continue
        # Nothing happens if text is entered outside of chat and it is not a command
        else:
            pass

    return 0



if __name__ == "__main__":
    main()