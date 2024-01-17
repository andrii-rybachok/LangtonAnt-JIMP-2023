Program został stworzony przez: Rybachok Andrii, Chaienko Oleksandr

Opis Programu:
Program symuluje ruch mrówki Langtona na planszy. Mrówka Langtona jest abstrakcyjnym automatem komórkowym, który porusza się na dwuwymiarowej siatce. Kierunek ruchu mrówki zmienia się w zależności od koloru komórki, na której się znajduje.

Sposób Użycia:
Aby skorzystać z programu, należy uruchomić go z linii poleceń, podając odpowiednie parametry:
•	-r: Liczba wierszy planszy.
•	-c: Liczba kolumn planszy.
•	-i: Liczba iteracji symulacji.
•	-d: Kierunek początkowy mrówki (0 - dół, 1 - lewo, 2 - góra, 3 - prawo).
•	-b: Procent czarnych komórek na planszy.
•	-p: Prefix nazw plików wyjściowych.
•	-m: Prefix nazw plików mapy (opcjonalne).

Idee Działania Mrówki Langtona:
Mrówka chodzi po dwuwymiarowej siatce. Może poruszać się w jednym z 4-ech kierunków (góra, dół, lewo, prawo), zgodnie z następującymi zasadami:
•	Mrówka znajduje się w komórce białej, wykonuje: obrót o 90 stopni w prawo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu
•	Mrówka znajduje się w komórce czarnej, wykonuje: obrót o 90 stopni w lewo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu.

Podział Programu na Moduły:
Program został podzielony na moduły w celu lepszej organizacji kodu i zwiększenia czytelności. Moduły to:
•	langtonAnt.h: Zawiera deklaracje struktury LangtonAnt.c oraz funkcji związanych z mrówką Langtona.
•	coordinates.h: Deklaracja struktury Coordinates,c używanej do reprezentowania współrzędnych.
•	cellColor.h: Deklaracja enumeracji CellColor.c reprezentującej kolory komórek (białe, czarne).
•	langtonField.h: Zawiera deklaracje struktury LangtonField.c oraz funkcji do obsługi planszy.
•	main.c: Główny plik programu zawierający funkcję i logikę obsługi argumentów oraz symulacji.

Opis podstawowych funkcji i struktur:
1. Struktury:
•	LangtonAnt (langtonAnt.h):
typedef struct {
    Coordinates cords;
    Direction direction;
} LangtonAnt;
Struktura reprezentująca mrówkę Langtona.
Zawiera współrzędne (cords) i kierunek (direction) mrówki.
•	Coordinates (coordinates.h):
typedef struct {
    int x;
    int y;
} Coordinates;
Struktura reprezentująca współrzędne na planszy.
•	LangtonField (langtonField.h):
typedef struct {
    int** field;
    int rows;
    int cols;
    LangtonAnt ant;
} LangtonField;
Struktura reprezentująca planszę i mrówkę Langtona.
Zawiera dwuwymiarową tablicę (field), liczby wierszy i kolumn (rows i cols) oraz mrówkę.
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

Przykładowe Działanie Programu:
Uruchomienie programu z przykładowymi parametrami:
./bin/langton -r 10 -c 10 -i 20 -d 2 -b 40 -p example
Program utworzy pliki wynikowe z symulacją mrówki Langtona na planszy 10x10, wykonując 20 iteracji. Działanie programu można zobaczyć w plikach wyjściowych o nazwach "example_nriteracjin.txt", gdzie n to numer iteracji.

Wnioski:
Program umożliwia eksperymentowanie z różnymi ustawieniami symulacji mrówki Langtona. Działanie programu jest zgodne z zasadami ”projekt23Z”, a wyniki są zależne od początkowych warunków i reguł ruchu mrówki. 
