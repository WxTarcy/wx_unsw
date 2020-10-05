from datetime import  datetime
import time
import sys
from socket import *


serverip=sys.argv[1]
serverport=int(sys.argv[2])
client_socket= socket(AF_INET,SOCK_DGRAM)
ad=(serverip,serverport)
rtts=[]
lostpackets=0
for i in range(3331,3346):
    time_stamp=datetime.now().isoformat(sep=" ")[:-3]
    ping=str(i)+' '+time_stamp+'\r\n'
    time_send=datetime.now()
    client_socket.sendto(ping.encode(),ad)
    try:
        client_socket.settimeout(0.6)
        response, serveradd= client_socket.recvfrom(1024)
        time_recive=datetime.now()
        rtt=round((time_recive-time_send).total_seconds()*1000)
        rtts.append(rtt)
        print(f'{i} PING to {serverip}, seq={i}, rtt={rtt} ms')
        client_socket.settimeout(None)
    except timeout:
        lostpackets=lostpackets+1
        print(f'{i} PING to {serverip}, seq={i}, rtt= time out')

print('\n')
print(f'Minimum RTT= {min(rtts)} ms')
print(f'Maximum RTT= {max(rtts)} ms')
print(f'Average RTT= {round(sum(rtts)/len(rtts))} ms')
print(f'{float(lostpackets)/15*100}% of packets have been lost ')
client_socket.close()

