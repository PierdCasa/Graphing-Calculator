# Calculator-de-functii
Proiect OOP - Pislariu Mario-Catalin 


Proiectul va contine o implementare utlilizand Programarea Orientata pe Obiecte a unui program ce are drep principal scop trasarea graficelor functiilor matematice.Pentru simplitate le voi cataloga in functii: Algebrice,Logaritmice,Trigonometrice si Mixte. 

Conventii:

Trigonometrice: SIN COS TG CTG ARCSIN ARCCOS ARCTG ARCCTG

--scrise cu litere mari, fara variabile X => vor desena graficele functiilor trig. elementare

Logaritmice: LN LG

--scrise cu litere mari, fara variab X => vor desena graficele functiilor log. elementare( lg si ln)

Algebrice: (X^2+3X+1)

--scrise cu litere mari(i.e fiecare aparitie a variab. "X" este uppercase) => va desena graficul functiei algebrice

Mixte:

--scrise cu litere mici(i.e fiecare aparitie a variab. "x" este lowercase) => va desena graficul functiei mixte

Nerespectarea conventiilor va genera erori.

Comenzi:

Type 'del' - delete all functions
Type 'enter' - draw function
Press 'NumPad +' - zoom in
Press 'NumPad -' - zoom out

Implementarea trasarii graficelor va fi realizata folosind SFML 3.0.
Inputul va fi luat de la tastatura(prin SFML).

Memorarea functiilor matematice se va face utilizand RPN si Shunting-Yard Algorithm, tranformand stringul dat drep input( INFIX) intr-un vector de Token-uri(POSTFIX).
