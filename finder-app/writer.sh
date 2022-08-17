#!/bin/sh
if [ $# -lt 2 ]
then
	echo "writefile not specified"
	exit 1
else
	if [ $# -lt 1 ]
        then
                echo "writestr not secified"
                exit 1
        else
                writefile=$1
        fi
	writestr=$2
fi

if [ ! -d "$(dirname $writefile)" ]
then
	mkdir "$(dirname $writefile)" -p
fi
echo "$writestr" >> "$writefile"
if [ $? -ne 0 ]
then
	echo "File could not be created"
	exit 1
fi
