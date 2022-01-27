# Minesweeper
## Configuration du projet
Se placer avec le terminal dans la où le fichier **CMakeLists.txt** se trouve et taper la commande suivante :

```
$ cmake .
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Curses: /usr/lib/x86_64-linux-gnu/libcurses.so
-- Configuring done
-- Generating done
-- Build files have been written to: ...
```

Cela permet de configurer le projet C/C++ en générant un **Makefile**.

Si lors de la configuration, votre machine ne trouve aucun compilateur, vérifiez qu'elle possède bien un compilateur en tapant la commande :

```
$ which gcc
/usr/bin/gcc

$which g++
/usr/bin/g++
```

Et ensuite configurez le projet CMake en tapant la commande :
```
cmake -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++
```

## Compiler le projet
Apres avoir configuré le projet CMake et qu'il vous ait généré un **Makefile**, pour compiler taper la commande :

```
$ make
Scanning dependencies of target minesweeper
...
[100%] Linking CXX executable bin/minesweeper
[100%] Built target minesweeper
```

Pour nettoyer le projet : 

```
$ make clean
```

Pour lancer le programme : 
```
$ bin/minesweeper
```