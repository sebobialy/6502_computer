#!/bin/bash

cat symoniii.txt | \
   sed 's/.ORG/* =/g' | \
   sed 's/.EQU/=/g' | \
   sed 's/\.DW/\.word/g' | \
   sed 's/\.DB "/\.text "/g' | \
   sed 's/\.DB  "/\.text "/g' | \
   sed 's/\.DB/\.byte/g' | \
   sed "s/LDA  \$INBUFF-1,X/LDA  INBUFF-1,X/g" | \
   sed "s/LDA  \$HEX0AND1,X/LDA  HEX0AND1,X/g" | \
   sed 's/LDX  #$00)/LDX  #$00/g'  \
   >symon.asm

64tass --nostart symon.asm -o symon.bin
