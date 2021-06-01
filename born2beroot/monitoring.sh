#!/bin/bash

printf "#Architecture: "
uname -a
printf "#CPU physical : "
grep "physical id" /proc/cpuinfo | wc -l
printf "#vCPU : "
grep "processor" /proc/cpuinfo | wc -l
printf "#Memory Usage: "
MEMORY_TOTAL=`free -m | grep Mem | awk '{print $2}'`
MEMORY_USE=`free -m | grep Mem | awk '{print $3}'`
MEMORY_PERCENTAGE=`free | grep Mem | awk '{printf("%.2f", $3/$2 * 100.0)}'`
echo "$MEMORY_USE/${MEMORY_TOTAL}MB ($MEMORY_PERCENTAGE%)"
printf "#Disk Usage: "
DISK_TOTAL=8192
DISK_USE=`df -BM | grep -v Filesystem | awk '{sum+=$3}END{print sum}'`
DISK_PER=`echo "$DISK_USE $DISK_TOTAL 100" | awk '{printf ("%d", $1 / $2 * $3)}'`
echo "$DISK_USE/8Gb ($DISK_PER%)"
printf "#CPU load: "
top -b -n1 | grep "Cpu(s)" | awk '{printf("%.1f%%\n",$2 + $4)}'
printf "#Last boot: "
who -b | awk '{print $3" "$4}'
printf "#LVM use :"
LVM_DATA=`lsblk | grep "lvm" | wc -l`
if [ ${LVM_DATA} == 0 ];
then
	echo "no"
else
	echo "yes"
fi
printf "#Connexions TCP : "
CONNECTIONS=`ss -t | grep -v "State" | wc -l`
echo "$CONNECTIONS ESTABLISHED"
printf "#User log: "
top -b -n1 | grep "user" | awk '{print $6}'
IP_ADDRESS=`hostname -I | tr -d " "`
MAC_ADDRESS=`ip addr | grep "ether" | awk '{print $2}' | tr -d " "`
echo "#Network: IP $IP_ADDRESS ($MAC_ADDRESS)"
printf "#Sudo : "
SUDO_CMD=`sudo ls -l /var/log/sudo/00/00 | wc -l`
echo "$SUDO_CMD cmd"
