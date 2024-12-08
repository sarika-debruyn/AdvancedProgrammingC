#!/bin/bash
on_ctrl_c() {
	echo "Ignoring Ctrl-C"
}

PID=$$
mkfifo mypipe-$PID
cat mypipe-$PID | nc -l "$1" | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > mypipe-$PID

echo "Removing FIFO"
rm mypipe-$PID
