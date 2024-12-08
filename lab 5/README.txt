-Sarika de Bruyn
-sed2194
-Lab #5

Part 1:

a) Program works as expected in lab instructions

b)

systemd(1) /lib/systemd/systemd --system --deserialize 40
 \_ /usr/sbin/sshd -D [listener] 2 of 10-100 startups
     \_ sshd: sed2194 [priv]
         \_ sshd: sed2194@pts/1
             \_ -bash
                 \_ ./sarika-nc-1 20200
                     \_ /bin/bash ./mdb-lookup-server-nc.sh 20200***
                         \_ cat mypipe-<PID>
                         \_ nc -l 20200
                         \_ /bin/sh/home/jae/cs3157-pub/bin/mdb-lookup-cs3157***
                             \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157)


Shell Script files are marked with "***"

c) Program works as expected in lab instructions
