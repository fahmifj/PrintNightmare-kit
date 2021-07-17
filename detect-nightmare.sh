#!/bin/sh

targets=$1

if [ -z "$targets" ]; then
  echo "[-] Usage\t: $0 [Target file]" 
  echo "[-] File format : <ip>:<username>:<password> | 127.0.0.1:foo:bar"
  else
	for target in `cat $targets`; do
		 ip=$(echo $target | cut -d ':' -f1)
		 username=$(echo $target | cut -d ':' -f2)
		 password=$(echo $target | cut -d ':' -f3)
		 echo  " - [$ip] - " 
		 impacket-rpcdump $ip | egrep 'MS-RPRN|MS-PAR'
		 rpcclient -U "$username%$password" $ip -c "enumprinters;quit"
	done
fi