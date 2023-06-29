# Hash-and-tree
Tarea Nro. 3 para el curso de algoritmos y estructuras de datos

Experimentación con estructuras de datos para medir el tiempo de búsqueda e inserción.

Cada estructura está implementada en su correspondiente nombre_de_estructura.cpp, y el algoritmo principal esta en main.cpp.
En condiciones ideales este debería correr todas las variantes de experimentos usando un Makefile, pero mi falta de experiencia y tiempo me obligaron a editar y correr manualmente cada uno.

Los resultados obtenidos se encuentran en ./outputs y con los scripts plot_hist.py y plot_line.py se pueden visualizar pasando como argumentos el nombre de los archivos de interés (hist para los tipo search*.csv, line para los tipo insertion*.csv).
Los datos de univsersities-followers_2022.csv fueron pre-procesados usando el notebook pre_process.ipynb, obteniendo los archivos clean_int_id.csv, clean_str_id.csv y las variantes de in_search* y not_in_search*.
