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
DISK_PER=$(echo "$DISK_USE $DISK_TOTAL 100" | awk '{printf ("%d", $1 / $2 * $3)}')
echo "$DISK_USE/8Gb ($DISK_PER%)"
printf "#CPU load: \n"
printf "#Last boot: "
who -b | awk '{print $3" "$4}'
printf "#LVM use : \n"
printf "#Connexions TCP : \n"
printf "#User log: \n"
IP_ADDRESS=`hostname -I | tr -d " "`
MAC_ADDRESS=`ip addr | grep "ether" | awk '{print $2}' | tr -d " "`
echo "#Network: IP $IP_ADDRESS ($MAC_ADDRESS)"
