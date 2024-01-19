Symulacja Mrówki Langtona
Program został stworzony przez: Rybachok Andrii, Chaienko Oleksandr
GitHub: https://github.com/andrii-rybachok/LangtonAnt-JIMP-2023/tree/main

Opis Programu
Program symuluje ruch mrówki Langtona na planszy. Mrówka Langtona jest abstrakcyjnym automatem komórkowym, który porusza się na dwuwymiarowej siatce. Kierunek ruchu mrówki zmienia się w zależności od koloru komórki, na której się znajduje.

Sposób Użycia
Aby skorzystać z programu, należy uruchomić go z linii poleceń, podając odpowiednie parametry:
•	-r: Liczba wierszy planszy.
•	-c: Liczba kolumn planszy.
•	-i: Liczba iteracji symulacji.
•	-d: Kierunek początkowy mrówki (0 - dół, 1 - lewo, 2 - góra, 3 - prawo).
•	-b: Procent czarnych komórek na planszy.
•	-p: Prefix nazw plików wyjściowych.
•	-m: Nazwa pliku dla wyczytania początkowej mapy(opcjonalnie).
•	-a: Służy dla animacji mrówki w terminale. 
Idee Działania Mrówki Langtona
Mrówka chodzi po dwuwymiarowej siatce. Może poruszać się w jednym z 4-ech kierunków (góra, dół, lewo, prawo), zgodnie z następującymi zasadami:
•	Mrówka znajduje się w komórce białej, wykonuje: obrót o 90 stopni w prawo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu
•	Mrówka znajduje się w komórce czarnej, wykonuje: obrót o 90 stopni w lewo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu.
•	Znaki mrówki jaki korzystamy dla programy:
•	Ściana (koniec planszy):
Jeśli mrówka dotrze do końca planszy, pozostanie na miejscu, a program powiadomi użytkownika, że mrówka dotarła do końca planszy.

Podział Programu na Moduły
Program został podzielony na moduły w celu lepszej organizacji kodu i zwiększenia czytelności. Moduły to:
•	langtonAnt.h: Zawiera deklaracje struktury LangtonAnt.c oraz funkcji związanych z mrówką Langtona.
•	coordinates.h: Deklaracja struktury Coordinates,c używanej do reprezentowania współrzędnych.
•	cellColor.h: Deklaracja enumeracji CellColor.c reprezentującej kolory komórek (białe, czarne).
•	langtonField.h: Zawiera deklaracje struktury LangtonField.c oraz funkcji do obsługi planszy.
•	main.c: Główny plik programu zawierający funkcję i logikę obsługi argumentów oraz symulacji.

Opis podstawowych funkcji i struktur
1. Struktury:
•	LangtonAnt (langtonAnt.h):
1) Struktura reprezentująca mrówkę Langtona.
2) Zawiera współrzędne (cords) i kierunek (direction) mrówki.
•	Coordinates (coordinates.h):
1)	Struktura reprezentująca współrzędne na planszy.
•	LangtonField (langtonField.h):
1)	Struktura reprezentująca planszę i mrówkę Langtona.
2)	Zawiera dwuwymiarową tablicę (field), liczby wierszy i kolumn (rows i cols) oraz mrówkę.

2. Funkcje:
•	initializeAnt (langtonAnt.h):
Inicjalizuje strukturę LangtonAnt z określonymi współrzędnymi startowymi i kierunkiem.
•	antIterate (langtonAnt.h):
Realizuje jedną iterację ruchu mrówki w zależności od koloru aktualnej komórki.
Aktualizuje współrzędne mrówki i zwraca -1, jeśli mrówka opuściła planszę.
•	toggleColor (cellColor.h):
Zmienia kolor komórki (biały na czarny, czarny na biały).
•	initializeField (langtonField.h):
Inicjalizuje strukturę LangtonField z określoną liczbą wierszy, kolumn, procentem czarnych komórek i kierunkiem startu mrówki.
•	fieldIterate (langtonField.h):
Realizuje jedną iterację ruchu mrówki na planszy.
Aktualizuje stan planszy i zwraca -1, jeśli mrówka opuściła planszę.
•	printField (langtonField.h):
Wypisuje stan planszy na standardowe wyjście.
•	printFieldToFile (langtonField.h):
Zapisuje stan planszy do pliku.
•	loadMapFromFile (langtonField.h):
Wczytuje mapę planszy z pliku do struktury LangtonField.
•	initializeFieldWithMap (langtonField.h):
Inicjalizuje planszę z mapy wczytanej z pliku.
•	checkMap (langtonField.h):
służy do analizy zawartości pliku.

Przykładowe Działanie Programu
Uruchomienie programu z przykładowymi parametrami:
Program utworzy pliki wynikowe z symulacją mrówki Langtona na planszy 10x10 i z 50% czarnymi komórkami, wykonując 12 iteracji i pokazuje animacji w terminale. Działanie programu można zobaczyć w plikach wyjściowych o nazwach "file_nriteracjin.txt", gdzie n to numer iteracji.
Uruchomienie programu z przykładowymi parametrami(opcjonalnie):
Program utworzy pliki wynikowe z symulacją mrówki Langtona zgodnie z parametrami jaki jest w pliku (kolumny, wiersze i procent czarnych komórek) Działanie programu można zobaczyć w plikach wyjściowych o nazwach "file_nriteracjin.txt", gdzie n to numer iteracji.

Wnioski
Program umożliwia eksperymentowanie z różnymi ustawieniami symulacji mrówki Langtona. Działanie programu jest zgodne z zasadami ”projekt23Z”, a wyniki są zależne od początkowych warunków i reguł ruchu mrówki. 
