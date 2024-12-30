#!/usr/bin/bash

KBDS="converter/usb_usb peej/lumberjack waterfowl splitkb/kyria/rev1 splitkb/aurora/sweep/rev1 40percentclub/gherkin/pro_micro planck/rev6_drop"
KM=jenspets

for k in $KBDS; do
    echo 
    echo -e "\033[01;31m***\033[00m Compile keymap \033[01;32m$KM\033[00m for keyboard \033[01;32m$k\033[00m \033[01;31m***\033[00m" 

    qmk compile -kb $k -km $KM

    ret=$?
    if [[ $ret != 0 ]]; then
	echo -e "\033[01;31m***\033[00m failed with code $ret: $k \033[01;31m***\033[00m"
	break
    fi
done;
