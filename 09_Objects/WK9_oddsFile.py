# This is the python program used to generate the input file "example.txt"
# It is here for your curiosity and is not part of the class
from random import choice, random , randrange

_FNAME = "example.txt"
_NUMS  =   20
_VALS  = 1000
_SKIPP =    0.25
_NLINE =   15

names = [
    "Ambolo Wablo" ,
    "Blendomere Zhazden" ,
    "Cremdo Allverten" ,
    "Desmodeous Bunk" ,
    "Erankun Bloff" ,
    "Fii Tembato" ,
    "Gumpald Scordle" ,
    "Helios Cronkadonk" ,
    "Iglian Wronst" ,
    "Jacobian Jones" ,
    "Kendala Querx" ,
    "Linten Hamperdocio" ,
    "Melba Ubert" ,
    "Nomblin Tofurga" ,
    "Oberon Norebo" ,
    "Penton Flark" ,
    "Quantico Ilben" ,
    "Runction Fidoof" ,
    "Swempleton Hod" ,
    "Tibbits Malone" ,
    "Ubicus Grandola" ,
    "Vandus Plendosphere" ,
    "Wemply Crayfish" ,
    "Xur Kleptonomicon" ,
    "Yampa Zidoooo" ,
    "Zanpoi Yalburton"
]

n_i = 0

with open( _FNAME , 'w' ) as f:
    for i in range( _NLINE ):
        lineStr = ""
        if random() >= _SKIPP:
            lineStr += names[ i % len(names) ] + ', '
            for j in range( randrange( 1 , _NUMS+1 ) ):
                lineStr += str( randrange( 1 , _VALS+1 ) ) + ', '
        lineStr += '\n'
        f.write( lineStr )
        print( "Wrote:" , lineStr )
        