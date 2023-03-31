#!/bin/bash

#RAM
ram=$(free --mega | grep Mem)
total_ram=$(echo  "$ram" | awk '{print $2}')
used_ram=$(echo "$ram" | awk '{print $3}')
ram_per=$(echo "$used_ram $total_ram" | awk '{printf "%.2f" ,$1 * 100 /  $2}')

#Memory
mem=$(df --total -BM | grep total)
mem_size=$(df --total -BG | grep total | awk '{print $2}')
used_mem=$(echo $mem | awk '{printf "%d", $3}')
mem_per=$(echo $mem | awk '{print $5}')

#Cpu load
cpu_load=$(top -bn1 | grep %Cpu | awk -F, '{printf "%.2f", 100 - $4}')

#check if lvm used
is_lvm_used=$(lsblk -o type | grep lvm | wc -l | awk '{printf $1 == 0? "no" : "yes"}')

#MAC address
mac=$(ip link | grep link/ether | awk '{print $2}')

#IPv4
ipv4=$(hostname -I)

echo "#Architecture: $(uname -a)"
echo "#CPU physical : $(nproc --all)"
echo "#vCPU : $(cat /proc/cpuinfo | grep processor | wc -l)"
echo "#Memory Usage: $used_ram/$total_ram""MB ($ram_per%)"
echo "#Disk Usage: $used_mem/$mem_size""b ($mem_per)"
echo "#CPU load: $cpu_load"
echo "#Last boot: $(uptime -s)"
echo "#LVM use: $is_lvm_used"
echo "#Connections TCP : $(ss -t | grep 'ESTAB' | wc -l) ESTABLISHED"
echo "#User log: $(who | awk '{print $1}' | uniq | wc -l)"
echo "#Network: $ipv4 ($mac)"
echo "#Sudo : $(journalctl _COMM=sudo -q | grep COMMAND | wc -l)"
