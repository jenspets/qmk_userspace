#!/usr/bin/bash

KBDS="converter/usb_usb peej/lumberjack waterfowl splitkb/kyria splitkb/aurora 40percentclub/gherkin planck/rev6_drop"
KM=jenspets

for k in $KBDS; do
    echo 
    echo Compiling $k

    qmk compile -kb $k -km $KM
    
    ret=$?
    if [[ $ret != 0 ]]; then
	echo "*** Compilation failed with code $ret: $k ***"
	break
    fi
done;
