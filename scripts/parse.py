from contextlib import redirect_stdout

import sys

import os

with open(sys.argv[1], 'r') as inputFile:

    inputText = inputFile.read()

    with open (sys.argv[2], "w") as outputFile:

        with redirect_stdout(outputFile):

            outputText = ''.join(sym for sym in inputText if sym.isalpha() or sym == ' ').lower().split()

            for word in outputText:
                print(f'{word}\n', end='')
            
    