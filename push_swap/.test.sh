#!/bin/bash
​
if [ -e "./res" ]
then
	echo "\033[0merasing res file"
	rm res
fi
​
if [ -e "./MVS" ]
then
	echo "\033[0merasing MVS file"
	rm MVS
fi
​
echo '\033[0mTesting validity 100 Times in a range from 0 to 4'
ERR=0
for i in range {1..99}
do
	ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | ./checker $ARG`
	if [ "$RET" != "OK" ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		cat MVS | wc -l >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m Success\033[0;0m'
else
	echo "\033[0;31m Fail $ERR / 100\033[0;0m"
fi
​
echo '\033[0mTesting length 100 Times in a range from 0 to 4 '
ERR=0
for i in range {1..99}
do 
	ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | wc -l`
	if [ $RET -gt 12 ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		echo $RET >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m Success\033[0;0m'
else
	echo "\033[0;31m Fail $ERR / 100\033[0;0m"
fi
​
./tester res
rm res
​
echo '\033[0mTesting 100 Times in a range from -50 to 49'
ERR=0
for i in range {1..99}
do 
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | ./checker $ARG`
	if [ "$RET" != "OK" ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		cat MVS | wc -l >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m Success\033[0;0m'
else
	echo "\033[0;31m Fail $ERR / 33\033[0;0m"
fi
​
echo '\033[0mTesting 100 Times in a range from -99 to 0'
ERR=0
for i in range {1..99}
do 
	ARG=`ruby -e "puts (-99..0).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | ./checker $ARG`
	if [ "$RET" != "OK" ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		cat MVS | wc -l >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m Success\033[0;0m'
else
	echo "\033[0;31m Fail $ERR / 33\033[0;0m"
fi
​
echo '\033[0mTesting 100 Times in a range from 0 to 99'
ERR=0
for i in range {1..99}
do 
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | ./checker $ARG`
	if [ "$RET" != "OK" ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		cat MVS | wc -l >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m▓ Success\033[0;0m'
else
	echo "\033[0;31m▓ Fail $ERR / 33\033[0;0m"
fi
​
./tester res
rm res
​
echo '\033[0mTesting 100 Times in a range from 0 to 499'
ERR=0
for i in range {1..99}
do 
	ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	./push_swap $ARG > MVS
	RET=`cat MVS | ./checker $ARG`
	if [ "$RET" != "OK" ];
	then
		((ERR++))
		printf '\033[0;31m▓\033[0;0m'
	else
		cat MVS | wc -l >> res
		printf '\033[0;32m▓\033[0;0m'
	fi
	rm MVS
done
​
if [ $ERR -eq 0 ];
then
	echo '\033[0;32m Success\033[0;0m'
else
	echo "\033[0;31m Fail $ERR / 25\033[0;0m"
fi
​
./tester res
rm res