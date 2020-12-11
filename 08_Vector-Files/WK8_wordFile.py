# This is the python program used to generate the input file "example.txt"
# It is here for your curiosity and is not part of the class
from english_words import english_words_set # pip3 install english_words --user
from random import choice

_FNAME = "example.txt"
_N     =  5
_M     = 10
_WORDS = list( english_words_set )

with open( _FNAME , 'w' ) as f:
    for i in range( _M ):
        lineStr = ""
        for j in range( _N ):
            lineStr += str( choice( _WORDS ) ) + ','
        lineStr += '\n'
        f.write( lineStr )
        print( "Wrote:" , lineStr )
        