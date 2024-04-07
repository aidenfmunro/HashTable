from contextlib import redirect_stdout

import sys

with open(sys.argv[1], 'r') as inputFile:

    inputText = inputFile.read()

    with open ("result.txt", "w") as outputFile:

        with redirect_stdout(outputFile):

            outputText = ''.join(sym for sym in inputText if sym.isalpha() or sym == ' ').lower().split()

            for word in outputText:
                print(f'{word}')
    